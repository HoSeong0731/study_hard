	AREA	ARMex, CODE, READONLY
		ENTRY
		
Main
	MOV r0, #1 ;r0 = 1(1)
	MOV r1, r0, LSL #1 ;shift r0 by 1 and r1 = r0(2)
	MOV r2, r0, LSL #3 ;shift r0 by 3 and r2 = r0(8)
	
	LDR r7, Address	;Insert address value
		
	ADD r6, r0, r1 	;r6 = r0 + r1(r6 = 3)
	ADD r6, r6, r2 	;r6 = r6 + r2(r6 = 11)
	SUB r5, r6, r0 	;r5 = r6 - r0(r5 = 10)
	
Loop
	ADD r3, r3, r6 	;r3 = r3 + r6(r3 = 0 + 11[first value]), 11(First) + 13(second)...
	ADD r6, r6, r1 	;r6 = r6 + r1(r6 = 11 + 2[first value])
	ADD r4, r4, r0 	;r4 = r4 + 1(count ++)
	CMP r5, r4 		;compare r5, r4(if count = 10)
	BEQ Endline 	;if r5 == r4(count = 10), go to Endline
	B Loop 			;else, go to Loop
	
Address DCD &00040000  
	
Endline
	STR r3, [r7] 	;store r3 to r7(c8 = 200)
	END