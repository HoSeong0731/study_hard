	AREA ARMem, CODE, READONLY
		ENTRY

Main
	LDR r0, ADDRESS			;ADDRESS load
		
	MOV r1, #1				;insert value and 1! a(1) = 1
	
	ADD r2, r1, LSL#1		;2!	= a(2) = 2*a(1)
	
	ADD r3, r2, r2, LSL#1	;3! = a(3) = a(2) + 2*a(2)
	
	ADD r4, r3, LSL#2		;4! = a(4) = 4*a(3)
	
	ADD r5,	r4, r4, LSL#2	;5! = a(5) = a(4) + 4*a(4)
	
	ADD r6, r6, r5, LSL#2	;6! = a(6) = 4*a(5) 					
	ADD r6, r5, LSL#1  		;					+ 2*a(5)
	
	RSB	r7, r6, r6, LSL#3	;7! = a(7) = 8*a(6) - a(6) [reverse subtract]
	
	ADD	r8, r7, LSL#3		;8! = a(8) = 8*a(7)
	
	ADD	r9, r8, r8, LSL#3	;9! = a(9) = a(8) + 8*a(8) 
	
	ADD r10, r9, LSL#1 		;10! = a(10) = 2*a(9)
	ADD	r10, r10, r9, LSL#3	;10!				  +8*a(9)
	
	STR	r1, [r0], #4		;store 1 in r0, r0 = r0 + 4
	STR	r2, [r0], #4		;store 2 in r0, r0 = r0 + 4
	STR	r3, [r0], #4		;store 6 in r0, r0 = r0 + 4
	STR	r4, [r0], #4		;store 24 in r0, r0 = r0 + 4
	STR	r5, [r0], #4		;store 120 in r0, r0 = r0 + 4
	STR	r6, [r0], #4		;store 720 in r0, r0 = r0 + 4
	STR	r7, [r0], #4		;store 5040 in r0, r0 = r0 + 4
	STR	r8, [r0], #4		;store 40320 in r0, r0 = r0 + 4
	STR	r9, [r0], #4		;store 362880 in r0, r0 = r0 + 4
	STR	r10, [r0]			;store 3628800 in r0

ADDRESS & &40000			;ADDRESS to save
	END