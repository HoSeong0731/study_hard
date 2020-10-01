	AREA ARMex, CODE, READONLY
	ENTRY

start
	MOV r0, #01
	MOV r1, #10
	MOV r2, #15
	MOV r3, #10
	
	LDR r4, TEMPADDR1
	STRB r0, [r4], #1
	STRB r1, [r4], #1
	STRB r2, [r4]
	
	LDRB r0, [r4, #-2]!
	CMP r0, r3
	MOVMI r5, #2
	MOVGT r5, #1
	MOVEQ r5, #3
	
	LDRB r0, [r4, #1]!
	CMP r0, r3
	MOVMI r5, #2
	MOVGT r5, #1
	MOVEQ r5, #3
	
	LDRB r0, [r4, #1]
	CMP r0, r3
	MOVMI r5, #2
	MOVGT r5, #1
	MOVEQ r5, #3

TEMPADDR1 &&0x40000;

	MOV pc, lr
	END