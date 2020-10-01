	AREA ARMex, CODE, READONLY
		
start
/*
	MOV r0, #16
	MOV r1, #5
	CMP r0, r1
	MOVMI r2, r0
	MOVGT r2, r1
	ADDEQ r0, r0, r1
	MOVEQ r2, r0
*/	
	MOV r0, #1
	MOV r1, #-1
	MOV r2, #8
	
	CMP r0, #0
	MOVGT r3, r0
	
	CMP r1, r3
	ADDMI r3, r3, r1
	
	MOV r4, #7
	CMP r2, r4
	ADDLE r3, r3, r2
	
	TST r3, #0
	MOVEQ r3, r0
	
	END