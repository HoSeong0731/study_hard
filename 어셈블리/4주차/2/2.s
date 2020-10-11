	AREA ARMem, CODE, READONLY
		ENTRY

Main
	LDR r0, ADDRESS			;ADDRESS load
	
	MOV r11, #1				;Value for multiplication
	MOV r1, #1				;insert value and 1!
	
	ADD r11, r11, #1		;r11 = 1 + 1
	MUL r2, r1, r11			;2!
	
	ADD r11, r11, #1		;r11 = 2 + 1
	MUL r3, r2, r11			;3!
	
	ADD r11, r11, #1		;r11 = 3 + 1
	MUL r4, r3, r11			;4!
	
	ADD r11, r11, #1		;r11 = 4 + 1
	MUL r5, r4, r11			;5!
	
	ADD r11, r11, #1		;r11 = 5 + 1
	MUL r6, r5, r11			;6!
	
	ADD r11, r11, #1		;r11 = 6 + 1
	MUL r7, r6, r11			;7!
	
	ADD r11, r11, #1		;r11 = 7 + 1
	MUL r8, r7, r11			;8!
	
	ADD r11, r11, #1		;r11 = 8 + 1
	MUL r9, r8, r11			;9!
			
	ADD r11, r11, #1		;r11 = 9 + 1
	MUL r10, r9, r11		;10!
	
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

ADDRESS & &40000			;ADDRESSto save
	END