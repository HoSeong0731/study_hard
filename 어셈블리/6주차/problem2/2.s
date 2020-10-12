	AREA Problem2, CODE, READONLY
		ENTRY
Main
	MOV r0,#2
	MOV r1,#7
	MOV r2,#1
	MOV r3,#3
	MOV r4,#8
	MOV r5,#4
	MOV r6,#5
	MOV r7,#6					;Initialize Register r0-r7 to 2,7,1,3,8,4,5,6
	
	LDR sp, TEMPADDR1			;Load address value to stack pointer (sp = r13)
	
	STMEA	sp!, {r2}			;Store r2
	STMEA	sp!, {r0,r3}		;Store r0, r3 values into memory via multiple stores and auto incrementing
	STMEA	sp!, {r5-r7}		;Store r5 ro r7 values into memory via multiple stores and auto incrementing
	STMEA	sp!, {r1,r4}		;Store r1, r4 values into memory vua mulipule stores and auto incrementing
	
	LDMEA	sp!, {r0-r7}		;Called the value stored on the SP into the r0~r7 legester.
	
	MOV pc,#0					;Inserting a zero value into the program counter
	
TEMPADDR1	& &00040000			;address 
	END