	AREA ARMex, CODE, READONLY
	ENTRY

start
	MOV r0, #01; store integer 1 to register 0
	MOV r1, #02; store integer 2 to register 1
	MOV r2, #03; store integer 2 to register 2
	MOV r3, #04; store integer 2 to register 3
	
	
	LDR r4, TEMPADDR1; authorize memory area to use
	LDR r6, TEMPADDR2; authorize memory area to use
	
	STRB r3, [r4], #1; save r3 to r4 and r4 = r4 + 1
	STRB r2, [r4], #1; save r2 to r4 and r4 = r4 + 1
	STRB r1, [r4], #1; save r1 to r4 and r4 = r4 + 1
	STRB r0, [r4]	 ; save r0 to r4
	
	STRB r0, [r6], #1; save r0 to r6 and r6 = r6 + 1
	STRB r1, [r6], #1; save r1 to r6 and r6 = r6 + 1
	STRB r2, [r6], #1; save r2 to r6 and r6 = r6 + 1
	STRB r3, [r6]	 ; save r3 to r6
	
TEMPADDR1 & &40000 ; allocate 0x40000 to TEMPADDR1
TEMPADDR2 & &40200 ; allocate 0x40200 to TEMPADDR2
	
	LDR r5, [r6, #-3]!
	LDR r6, [r4, #-3]!
	
	MOV pc, lr	; go to first instruction
	END			; Mark end of file