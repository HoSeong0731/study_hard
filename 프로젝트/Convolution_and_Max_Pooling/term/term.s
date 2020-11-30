   AREA ARMex, CODE, READONLY
   ENTRY

Convolution_func
   LDR r10, =Data_set   ;Data_set
   LDR r1, [r10], #4   	;Convolution size 
   LDR r0, [r10], #8   	;Stride size
   LDR r2, [r10], #4   	;Matrix size
 
 
;================== Store Kernel AREA =============================================
Store_Kernel_Data
   LDR r11, Kernel_Data 	;Kernel_Data

Store_Loop1               	;convolution size * convolution size = number of elements
   CMP r1, r3            
   BLE Store_Matrix_Data   	;if(r1 <= r3) => go to store_Matrix_Data == End of Kernel element Storage
   
Store_Loop2
   
   LDR r9, [r10], #4      	;load
   STR r9, [r11], #4      	;store
   ADD r4, r4, #1         	;r4++
   CMP r1, r4            	;
   BGT Store_Loop2         	;if(r1 > r4) => Loop2
   
   MOV r4, #0            	;r4 = 0
   ADD r3, r3, #1         	;r3++
   B Store_Loop1         	;else => Loop1
   
;================== Store Matrix AREA =============================================
Store_Matrix_Data
   LDR r12, Input_Data      ;Input Data
   MOV r3, #0            	;reset r3
   MOV r9, #0            	;reset r9
   
Store_Input_Loop1
   CMP r2, r3         
   BLE Convolution        	;if(r2 <= r3) => go to Coonvolution == End of Input element Storage
   
Store_Input_Loop2         	;Input size * input size = number of element
   
   LDR r9, [r10], #4      	;Load
   STR r9, [r12], #4      	;Store
   ADD r4, r4, #1         	;r4++
   CMP r2, r4
   BGT Store_Input_Loop2   	;if(r2 > r4) => Loop2
   
   MOV r4, #0            	;reset r4
   ADD r3, r3, #1         	;r3++
   B Store_Input_Loop1      ;else => Loop1
   
   
;================== Convolution AREA =============================================
Convolution               	;reset register
   MOV r3, #0
   MOV r9, #0
   MOV r10, #0
   LDR r11, Kernel_Data
   LDR r12, Input_Data
   LDR r10, Convolution_middle_result
before_Loop1            	;Initial Conditions of Loop1
   MOV r3, #0
   ADD r3, r3, r1
   SUB r3, r3, #1         	;matrix_size > height position + kernel_size -1
Loop1
   CMP r2, r3
   BGT before_Loop2      	;if(matrix_size>height position + kernel_size -1) => go to Loop2
   B Calculation         	;else go to Calculation
before_Loop2            	;Initial Conditions of Loop2
	MOV r4, #0            	;reset r4
	ADD r4, r4, r1         	;
	SUB r4, r4, #1         	;matrix_size > width position + kernel_size -1;
Loop2
	CMP r2, r4            	;
	BGT before_Loop3      	;if(matrix_size > width position + kernel_size -1) => go to Loop3
	ADD r3, r3, r0         	;else height position += stride
	B Loop1               	;go to Loop1
   
before_Loop3            	;Initial Conditions of Loop3
	MOV r5, #0
Loop3
	CMP r5, r1            	;
	BLT before_Loop4      	;if(height position of kernel < kernel_size) => go to Loop4
	LDR r11, Kernel_Data   	;set Kernel_point   
	ADD r4, r4, r0         	;else width position++
	B Loop2               	;go to Loop2
   
before_Loop4            	;Initial Conditions of Loop4
	MOV r6, #1

Loop4
	CMP r6, r1				
	;ADD r9, r9, #1

	LDR r7, [r11], #4		;Load kernel Data

	ADD r9, r3, r5			;Calculate coordinate values for Matrix data start
	SUB r9, r9, r1
	ADD r9, r9, #1         	;x + i2 -stride - i + 2
	
	MUL r8, r9, r2         	;j(x + i2 -stride - i + 2)

	ADD r9, r8, r4
	SUB r9, r9, r1
	ADD r9, r9, r6       	;j(x + i2 -stride - i + 2) + j2 - stride - i + 2 - 1(because start 1)  + y      
							;Calculate coordinate values for Matrix data end
	LDR r8, [r12, r9, LSL #2]	;Load Matrix Data

	MUL r9, r8, r7				;kernel Data * Matrix Data
	STR r9, [r10], #4		;Store Convolution Middle result

	ADD r6, r6, #1         	;Kernel++ of width position
	MOV r9, #0				;reset
	MOV r8, #0				;reset
	BLT Loop4            	;if(width position < kernel_size) => go to Loop4
	ADD r5, r5, #1         	;else height position of kernel++
	B Loop3              	;go to Loop3
   
Calculation
	LDR r10, Convolution_middle_result	;set register
	LDR r3, Convolution_result
	MOV r5, #1					;condition count
	ADD r6, r1, r0
Calculation_condition
	CMP r2, r6					;input size = Convolution + (i-1)*stride
	ADD r5, r5, #1				;i++
	ADD r6, r6, r0				;next value += stried
	BNE Calculation_condition
 	MUL r6, r5, r5				;i = convolution result size,  i*i = Number of elements in the Convolution Middle results / kernel size^2
	
	MUL r7, r1, r1			;kernel size * kernel size
	MOV r8, #0
	MOV r4, #0			
Calculation_Loop1
	CMP r6, #0
	BGT Calculation_Loop2
	MOV r2, r5				;r2 = Convolution result size
	B Max_Pooling
	
Calculation_Loop2
	CMP r7, #1
	LDR r9, [r10], #4		;Load Convolution middle Data
	ADD r4, r4, r9			;Repeat adding of kernel size^2 
	SUB r7, r7, #1			;count++
	BGT Calculation_Loop2
	STR r4, [r3], #4		;STR Convolution result
	SUB r6, r6, #1			;count++
	MOV r4, #0				;r4 reset
	MUL r7, r1, r1			;r7 reset
	B Calculation_Loop1


;================== Multiplication AREA =============================================
;Radix2_of_Convolution_calculate
;   MOV r6, #31            ;count
;   MOV r10, #0            ;store result
;
;   
;multi                  ;matrix data = multiplicand, kernel data = multiplier
;   LDR r5, [r12]         ;load kernel data to r5
;   MOV r5, r5, LSL r6      
;   MOV r5, r5, LSR #31      ;r5 has[0]bit
;   CMP r6, #0            ;if count = 0
;   SUB r6, r6, #1         ;r5 -= 1
;   MOVLT r6, #1         ;reset r6 for multilcation
;   MOVLT r7, #0         
;   BLT Radix_end
;   CMP R5, r7;            ;Compare x,x-1
;   BEQ Shift            ;case 00 or 11
;   BLT Add_Shift         ;case 01
;   BGT Sub_Shift         ;case 10
;Shift               ;Only shift at case 00 or 11
;   ASR r10, r10, #1   ;Shift at case 00 or 11
;   MOV r7, r5         ;Store r5 to r7 for comparing next bit
;   B multi            ;Compare next bit
;Add_Shift                  ;add and shift case 01
;   ADD r10, r10, r9         ;Add A to r10
;   ASR r10, r10, #1         ;Shift
;   MOV r7, r5               ;Store r5 to r7 for comparing next bit
;   B multi                  ;Compare next bit
;Sub_Shift
;   SUB r10, r10, r9   ;Sub A from r10
;   ASR r10, r10, #1;   ;Shift
;   MOV r7, r5         ;Store r5 to r7 for comparing next bit
;   B multi            ;Compare next bit
;Radix_end




;================== Max Pooling AREA Setting =============================================

Max_Pooling				;r3 = Convolution_result_data, r2 = input size - stride size - kernel size + 2 => Convolution_result_size
	LDR r0, =Data_set
	LDR r1, [r0, #8]
	LDR r3, Convolution_result
	LDR r0, result

	MOV r4, #0			;count1
	MOV r5, #0			;count2
	MOV r6, #0			;count3
	MOV r7, #0			;count3
	MOV r8, #0
	MOV r9, #0
	MOV r10, #0
	MOV r11, #0
	MOV r12, #0

;================== Max Pooling AREA Calculation =============================================
Max_Pooling_before_Loop1            ;Initial Conditions of Loop1
	MOV r4, #0
	NEG r9, r9
Max_Pooling_Loop1
	CMP r2, r4
	BGT	Max_Pooling_before_Loop2	;if (Convolution_result_size > count1) go to Loop2 
	B	HO							;else is finish!!!!!!!!
Max_Pooling_before_Loop2            ;Initial Conditions of Loop2
	MOV r5, #0
Max_Pooling_Loop2
	CMP r2, r5
	BGT	Max_Pooling_before_Loop3	;if (Convolution_result_size > count2) go to Loop3 
	
	ADD r4, r4, r1					;ADD r4 += Max Pooling size
	B	Max_Pooling_Loop1
Max_Pooling_before_Loop3            ;Initial Conditions of Loop3
	MOV r6, #0
Max_Pooling_Loop3
	CMP r1, r6
	BGT	Max_Pooling_before_Loop4	;if (Max Pooling size > count3) go to Loop4
	STR r9, [r0], #4				;else Store
	MOV r9, #0						;else reset
	ADD r5, r5, r1					;else r5 += Max Pooling size
	B	Max_Pooling_Loop2			;go to Loop2
Max_Pooling_before_Loop4            ;Initial Conditions of Loop4
	MOV r7, #0						
Max_Pooling_Loop4
	ADD r11, r4, r6					;Calculate position
	MUL r10, r11, r2
	ADD r10, r10, r5
	ADD r10, r10, r7				;Calculate position end
	
	LDR r8, [r3, r10, LSL #2]		;Load Convolution result Data
	CMP r8, r9
	MOVGT r9, r8					;if (r8> r9) r9 = r8
	
	ADD r7, r7, #1					;Count4++
	CMP r1, r7
	BGT Max_Pooling_Loop4			;if (Max Pooling size > Count4) go to Loop4
	ADD r6, r6, #1					;count3++
	B Max_Pooling_Loop3				;else go to Loop3
   
HO
	MOV pc, #0						;Program end
;================== Address AREA =============================================

Kernel_Data DCD 0x00006000									;Kernel Data

Input_Data DCD 0x00060000									;Matrix Data
   
Convolution_middle_result DCD 0x06000000                    ;Convolution middle Address
   
Convolution_result DCD 0x00600000                          	;Convolution Result Address
   
result DCD 0x60000000                              			;Max Pooling Result Address
;================== DATA AREA =============================================
Data_set
	DCD 2
	DCD 2
	DCD 3
	DCD 6
	DCD 2_00000000000000000000000001101101
	DCD 2_00000000000000000000000010101010
	DCD 2_00000000000000000000000010010001
	DCD 2_00000000000000000000000001101101
	DCD 2_00000000000000000000011100101101
	DCD 2_11111111111111111111111110110111
	DCD 2_00000000000000000000000101010001
	DCD 2_11111111111111111111101100011110
	DCD 2_00000000000000000000010100100000
	DCD 2_11111111111111111111101010000000
	DCD 2_11111111111111111111100001000100
	DCD 2_00000000000000000000010101011101
	DCD 2_11111111111111111111101010010000
	DCD 2_00000000000000000000000001010000
	DCD 2_11111111111111111111100101011000
	DCD 2_11111111111111111111110010001111
	DCD 2_11111111111111111111110010100101
	DCD 2_00000000000000000000011001000001
	DCD 2_11111111111111111111101000000100
	DCD 2_11111111111111111111101111001010
	DCD 2_11111111111111111111101001001101
	DCD 2_00000000000000000000010010010001
	DCD 2_11111111111111111111101100100101
	DCD 2_11111111111111111111111000000100
	DCD 2_11111111111111111111101110000100
	DCD 2_00000000000000000000000010011101
	DCD 2_00000000000000000000001111001101
	DCD 2_00000000000000000000011100010111
	DCD 2_11111111111111111111110001010110
	DCD 2_11111111111111111111100110000001
	DCD 2_11111111111111111111101111111101
	DCD 2_11111111111111111111111001001001
	DCD 2_00000000000000000000001010101011
	DCD 2_11111111111111111111111010000111
	DCD 2_11111111111111111111101100011001
	DCD 2_11111111111111111111100101011010
	DCD 2_00000000000000000000010001000000
	DCD 2_11111111111111111111101011101101
	DCD 2_00000000000000000000001001010011
	DCD 2_11111111111111111111100011010101
	;5C6FB
   END