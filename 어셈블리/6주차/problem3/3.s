	AREA Problem3, CODE, READONLY
		ENTRY
Main
	MOV r0,#10
	MOV r1,#11
	MOV r2,#12
	MOV r3,#13
	MOV r4,#14
	MOV r5,#15
	MOV r6,#16
	MOV r7,#17			;Initialize Register r0-r7 to 10 ~ 17
	MOV r9,#160			;The value to get the greatest common divisor
	LDR sp,TEMPADDR1	;Load address value
	
doRegister
	STMFA sp!, {r0-r7}	;Empty the first address to store the GCD and store the previous values

	ADD r0, r0, #0		;10 + 0 = 10
	ADD r1, r1, #1		;11 + 1 = 12
	ADD r2, r2, #2		;12 + 2 = 14
	ADD r3, r3, #3		;13 + 3 = 16
	ADD r4, r4, #4		;14 + 4 = 18
	ADD r5, r5, #5		;15 + 5 = 20
	ADD r6, r6, #6		;16 + 6 = 22
	ADD r7, r7, #7		;17 + 7 = 24
						;Store the value of each register plus the index value
	
	ADD r8, r0, r1
	ADD r8, r8, r2
	ADD r8, r8, r3
	ADD r8, r8, r4
	ADD r8, r8, r5
	ADD r8, r8, r6
	ADD r8, r8, r7		;Get the sum of r0-r7 get above
						;Result(r8) = 136
	LDMDA sp!, {r0-r7}	;load r0-r7 value(10-17)
	STMFA sp!, {r8, r9}	;store r8, r9(136, 160)
doGCD
	CMP r8,r9			;Set the flag to the value of r8(136)-r9(160)
	SUBGT r8,r8,r9		;If r8 > r9, r8 = r8 - r9
	SUBLE r9,r9,r8		;If r8 <= r9, r9 = r9 - r8
	BEQ Endline			;If r8 == r9, Move to Endline branch
	BNE	doGCD			;If r8 != r9, Move to doGCD branch
	
Endline
	ADD r12, r8, r4			;r12 = GCD + 4
	LDMDA sp!, {r8, r9}		;load r8, r9(136, 160)
	STR r12,[sp]			;store r12
	
	
	MOV pc,#0			;Inserting a zero value into the program counter
	
TEMPADDR1	& &00040000
	END