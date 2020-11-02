	AREA PR1,CODE,READONLY
		ENTRY

Main
	LDR r0, Address1
	LDR r10, =float1
	LDR r11, =float2			;Load Memory Address Value of Variable
	MOV r1, #0x3F800000			;it was not saved as 7F800000 right away
	ADD r1, r1, #0x40000000		;so 3F800000 + 40000000
	
	LDR r2,[r10]				;Load float1
	CMP r2,#0x80000000			;Conditions for checking the sign bit
	MOVHI r3, #1				;Negative Number
	MOVLS r3, #0				;Positive Number
	
	LDREQ r2, [r11]				;(if float1 = #0x80000000) special case N1 = -0
	BEQ ENDLINE2				;go to ENDLINE2
	
	CMP r2, #0x00000000			;special case N1 = +0
	LDREQ r2, [r11]				;(if float1 = 0) r2 = float2
	BEQ ENDLINE2				;go to ENDLINE2
	
	CMP r2, r1					;special case N1_is_Positive_Infinite number
	BEQ N1_is_Positive_Infinite

								
	CMP r2, #0xFF800000			;special case N1_is_Negative_Infinite number
	BEQ N1_is_Negative_Infinite
	
	
	MOV r2, r2, ROR#23			;Rotation for Bit Clear
	BIC r4, r2, #0xFFFFFF00		;Bit Clear for Exponent
	
	MOV r5, r2, LSR#9			;Shift by 9 to the right to obtain the Mantissa value
	MOV r2, r2, ROR#9			;Restore original values
	
	LDR r6,[r11]				;Load float2
	CMP r6,#0x80000000			;Conditions for checking the sign bit
	MOVHI r7, #1				;Negative Number
	MOVLS r7, #0				;Positive Number
	
	LDREQ r2, [r10]				;(if float1 = #0x80000000) special case N2 = -0
	BEQ ENDLINE2				;go to ENDLINE2
	
	CMP r6, #0x00000000			;special case N2 = +0
	LDREQ r2, [r10]				;(if float2 = 0) r2 = float1
	BEQ ENDLINE2				;go to ENDLINE2
	
	CMP r6, r1					;special case N2_is_Positive_Infinite number	
	BEQ N2_is_Positive_Infinite
	
	CMP r6, #0xFF800000			;special case N2_is_Negative_Infinite number
	BEQ N2_is_Negative_Infinite
	
	MOV r6, r6, ROR#23			;Rotation for Bit Clear
	BIC r8, r6, #0xFFFFFF00		;Bit Clear for Exponent
	
	MOV r9, r6, LSR#9			;Shift by 9 to the right to obtain the Mantissa value
	MOV r6, r6, ROR#9			;Restore original values
	
	CMP r3,r7
	BEQ EQUAL
	BNE NOTEQUAL
	
EQUAL
	ADD r5, r5, #0x00800000
	ADD r9, r9, #0x00800000		;Attaching 1 in front of Mantissa type
	
	CMP r4, r8					;Comparing Exponent
	SUBGT r10, r4, r8			
	SUBGT r13, r4, #0x0000007F	
	
	SUBLT r10, r8, r4			;Subtract small Exponent value from large Exponent
	SUBLT r13, r8, #0x0000007F	;Subtract 127 from Exponent value
	
	MOVGT r11, r9, LSR r10
	MOVLT r11, r5, LSR r10		;Shift Mantissa to the right by the difference of Exponent value
	
	ADDGT r12, r5, r11
	ADDLT r12, r9, r11			;Add two Mantissa values with equal Exponent values
	
	CMP r12, #0x01000000		;If Carry value occurs(Normalize)
	MOVHS r12, r12, LSR #1		;Shift the Mantissa value to the right by 1
	ADDHS r13, r13, #1			;Add 1 to the exponent value
	
	MOV r2, #0					;Initialize r2
	MOV r3, r3, ROR#1			
	ADD r2, r2, r3				;Addition after rotation to obtain sign bit
	MOV r12, r12, LSL#9
	MOV r12, r12, LSR#9
	ADD r2, r2, r12				;Extract Mantissa value using Shift
	ADD r13, r13, #0x000007F
	MOV r13, r13, ROR#9
	ADD r2, r2, r13				;Add 127 to get Exponent value and extract
	
	B ENDLINE2

NOTEQUAL
	CMP r5, r9
	MOVHI r1, #1
	MOVLS r1, #0				;Compares absolute values and stores 0 or 1 in r1
	
	ADD r5, r5, #0x00800000
	ADD r9, r9, #0x00800000		;Attaching 1 in front of Mantissa type
	
	CMP r5, r9					;Comparing Mantissa
	CMPEQ r4, r8				;Exponent comparison if equal
	MOVEQ r2, #0				;Insert 0 to r2, if equal
	BEQ ENDLINE2				;Go to ENDLINE2, if equal

	CMP r4, r8					;Comparing Exponent
	SUBGT r10, r4, r8
	SUBGT r13, r4, #0x0000007F
	SUBLE r10, r8, r4			;Subtract small Exponent value from large Exponent
	SUBLE r13, r8, #0x0000007F	;Subtract 127 from Exponent value
	
	MOVGT r9, r9, LSR r10
	MOVLE r5, r5, LSR r10		;Shift Mantissa to the right by the difference of Exponent value
		
	CMP r1, #1					
	SUBEQ r12, r5, r9
	SUBNE r12, r9, r5			;The absolute value flag is used to subtract a small value from a large value

LOOP
	CMP r12, #0x00800000		;Condition for Normalizing Mantissa Value
	MOVLS r12, r12, LSL #1		;Shift the Mantissa value to the left by 1
	SUBLS r13, r13, #1			;Subtract 1 to the exponent value
	CMP r12, #0x00800000		;r12 - 0x00800000
	BLO LOOP					;If it is less than 0x00800000, go to LOOP
	BHS ENDLINE1				;If it is greater than 0x00800000, go to ENDLINE

ENDLINE1
	MOV r2, #0					;Initialize r2
	CMP r1, #1					;Sign bit Checking
	MOVEQ r3, r3, ROR#1
	MOVNE r7, r7, ROR#1
	ADDEQ r2, r2, r3
	ADDNE r2, r2, r7			;Addition after rotation to obtain sign bit
	MOV r12, r12, LSL#9
	MOV r12, r12, LSR#9
	ADD r2, r2, r12				;Extract Mantissa value using Shift
	ADD r13, r13, #0x000007F
	MOV r13, r13, ROR#9
	ADD r2, r2, r13				;Add 127 to get Exponent value and extract
	B ENDLINE2
	
N1_is_Positive_Infinite
	LDR r6,[r11]				;Load float2
	CMP r6, #0xFF800000			;special case N2_is_Negative_Infinite number
	MOVEQ r2, #0x00000000		;+infinite +(-infinie) = 0
	B ENDLINE2					;else case: +infinite +- RealNumber = +infinite
								;and current value of r2 = +infinite => skip other conditions.
	
N1_is_Negative_Infinite
	LDR r6,[r11]				;Load float2
	CMP r6, r1					;special case N2_is_Posititive_Infinite number
	MOVEQ r2, #0x00000000		;-infinite +infinite = 0
	B ENDLINE2					;else case: -infinite +- RealNumber = -infinite
								;and current value of r2 = +infinite => skip other conditions.
	
N2_is_Positive_Infinite
	CMP r2, #0xFF800000			;special case N1_is_Negetive_Infinite number
	MOVEQ r2, #0x00000000		;-infinite +infinite = 0
	MOVNE r2, r1				;else case: +-Real number + infinite = +infinite
	B ENDLINE2					;go to ENDLINE2
	
N2_is_Negative_Infinite
	CMP r2, r1					;special case N1_is_Posititive_Infinite number	
	MOVEQ r2, #0x00000000		;+infinite +(-infinite) = 0
	MOVNE r2, r6				;else case: +-Real number +(-infinite) = -infinite 
								;skip B ENDLINE2 (No need)
	
ENDLINE2
	STR r2, [r0]				;Store r2 value in the memory address value of r0
	MOV pc,lr
	
float1 & 0x3FC00000				;0 01111111 100 0000...
float2 & 0x40500000 			;0 10000000 101 0000...
Address1 DCD &40000
	END