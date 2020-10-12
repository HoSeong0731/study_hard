	AREA Problem1, CODE, READONLY
		ENTRY
Main
	MOV r0, #10					;r0 = #10
	LDR sp, TEMPADDR1			;Load address value to stack pointer (sp = r13)
	MOV r3, #1					;r3 = #1

LOOP
	CMP r0, #1					;cmp r0 & #1
	MULGT r3, r0, r3			;if r0 > 1 r3 = r0 * r3
	SUBGT r0, r0, #1			;if r0 > 1 r0 = r0 - 1
		
	BGT LOOP					;factorial recursive function
	
	STR r3, [sp]				;store #3628800 = 0x375f00
	MOV pc, #0					;Mov pc, #0

TEMPADDR1	& &00040000			;address 
	END