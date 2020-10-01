	AREA ARMex, CODE, READONLY
	ENTRY

start
	MOV r0, #01; store integer 1 to register 0
	MOV r1, #10; store integer 10 to register 1
	MOV r2, #15; store integer 15 to register 2
	MOV r3, #10; store integer 10 to register 3
	
	LDR r4, TEMPADDR12	; authorize memory area to use
	STRB r0, [r4], #1	; save r0 to r4 and r4 = r4 + 1
	STRB r1, [r4], #1	; save r1 to r4 and r4 = r4 + 1
	STRB r2, [r4]		; save r2 to r4
	
	LDRB r0, [r4, #-2]!	; Auto-index addressing, r0 = mem[r4-2], r4 = r4 - 2
	CMP r0, r3			; Compare(r0-r3)
	MOVMI r5, #2		; MOV 2 into r5, if r0<r3
	MOVGT r5, #1		; MOV 1 into r5, if r0>r3
	MOVEQ r5, #3		; MOV 3 into r5, if r0==r3
	
	LDRB r0, [r4, #1]!	; Auto-index addressing, r0=mem[r4+1], r4 = r4 + 1
	CMP r0, r3			; Compare(r0-r3)
	MOVMI r5, #2		; MOV 2 into r5, if r0<r3
	MOVGT r5, #1		; MOV 1 into r5, if r0>r3
	MOVEQ r5, #3		; MOV 3 into r5, if r0==r3
	
	LDRB r0, [r4, #1]	; Pre-index addressing, r0 = mem[r4+1], r4 unchanged
	CMP r0, r3			; Compare (r0-r3)
	MOVMI r5, #2		; MOV 2 into r5, if r0<r3
	MOVGT r5, #1		; MOV 1 into r5, if r0>r3
	MOVEQ r5, #3		; MOV 3 into r5, if r0==r3

TEMPADDR12 & &40000		;allocate 0x40000 to TEMPADDR12

	MOV pc, lr			;go to first instruction
	END					;Mark end of file