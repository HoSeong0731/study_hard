   AREA ARMex, CODE, READONLY
      ENTRY
Main
   LDR r0, =Number      ;Insert address of array
   LDR r1, Address     	;Insert address value
   MOV r4, #10         	;Insert value
   ADD r0, r0, #36		; r0 = r0 + 36(To load in reverse order)
   
Loop					;Loop label
   LDR r2, [r0], #-4   	;Load the values of the array stored in the address value into r0 one by one
   STR r2, [r1], #4   	;Store one array element to the address value of r1(4 in the address value)
   ADD r3, r3, #1      	;r3 = r3 + 1
   CMP r3, r4         	;compare r3 and r4
   BEQ Endline         	;goto Endline (if r3 = r4)
   B Loop            	;goto Loop
   
Number DCD 10, 9, 8, 7, 6, 5, 4, 3, 2, 1   ;Array declaration
Address DCD &00040000
	
Endline					;Loop Endline
   END              	;Exit