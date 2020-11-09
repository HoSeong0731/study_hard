CR EQU 0x0d						; it means CR = 0x0d
	
	area strcpy, code, readonly
		entry
		
main
	LDR r0, =Table				;load the address of table
	LDR r1, =Table2				;load the address of table2
	LDR r5, TEMPADDR1			;load r5 to TEMPADDR1
	EOR r2, r2, r2				;clear R2 to store count, mov r1, #0
	
Loop
	LDRB r3, [r0], #1			;load the first byte into r2
	STRB r3, [r1], #1			;save each byte into Table2
	STRB r3, [r5], #1			;save each byte into TEMPADDR1
	CMP r3, #CR					;is it the terminator?
	BEQ Done					;yes => stop loop
	ADD r2, r2, #1				;no => incrament count-
	
	BAL Loop					;read next char
	
Done
	STR r2, CharCount			;store result
	mov pc, #0					;finish
TEMPADDR1 DCD &00040000			;TEMPADDR1's address
	
;=========Data area
	AREA Data, DATA

Table
	ALIGN
	DCB "Hello, World", CR		;sentence to copy

Table2
	ALIGN
	DCB 0						;empty to save each word

	
;=========Result area
	AREA Result, DATA
CharCount						;store the length of sentence
	DCB 0						;stroage for count

	END