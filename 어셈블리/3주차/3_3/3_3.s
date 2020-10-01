	AREA ARMex, CODE, READONLY
		ENTRY
	
	LDR r0, Address         ;Insert address value
	MOV r1, #1			 	;r1 = 1
	MOV r2, r1, LSL #1		;r2 = 2
	MOV r3, r1, LSL #3		;r3 = 8
	ADD r3, r3, r1			;r3 = 9
   
	ADD r3, r3, r2			;r3 = 11
	ADD r4, r3, r2			;r4 = 13
	ADD r5, r4, r2			;r5 = 15
	ADD r6, r5, r2			;r6 = 17
	ADD r7, r6, r2			;r7 = 19
	ADD r8, r7, r2			;r8 = 21
	ADD r9, r8, r2			;r9 = 23
	ADD r10, r9, r2			;r10 = 25
	ADD r11, r10, r2		;r11 = 27
	ADD r12, r11, r2        ;r12 = 29

	ADD r3, r3, r4			;r3 = 11 + 13 = 24 = 0x18
	ADD r4, r5, r6			;r4 = 15 + 17 = 32 = 0x20
	ADD r5, r7, r8			;r5 = 19 + 21 = 40 = 0x28
	ADD r6, r9, r10			;r6 = 23 + 25 = 48 = 0x30
	ADD r7, r11, r12		;r7 = 27 + 29 = 56 = 0x38
	
	ADD r3, r3, r4			;r3 = 24 + 32 = 56 = 0x38
	ADD r4, r5, r6			;r4 = 40 + 48 = 88 = 0x58
	ADD r4, r4, r7			;r4 = 88 + 56 = 144 = 0x90
	
	ADD r3, r3, r4			;r3 = 56 + 144 = 0xc8
	
	STR r3, [r0]			;store r3 in r0.
	
Address DCD &00040000   
	END                  ;Exit the program