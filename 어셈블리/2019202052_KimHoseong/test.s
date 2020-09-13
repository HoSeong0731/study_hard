	AREA ARMex, CODE, READONLY
	ENTRY

start
	MOV r0,#10		;store integer 10 to register 0
	MOV r1,#3		;store integer 3 to register 1
	ADD r0,r0,r1	;add register 0's value and register 1's value and store result to register 0
	MOV pc,lr		;go to first instruction
	END				;Mark end of file