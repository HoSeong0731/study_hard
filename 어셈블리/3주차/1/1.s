	   AREA ARMex, CODE, READONLY
      ENTRY
Main
   LDR r0, Address 		;Insert address value
   
   CMP r9, #0           ;compare r9 and 0
   BEQ first			;if r9 and 0 is same goto first

   CMP r9, #1           ;compare r9 and 1
   BEQ second			;if r9 and 1 is same goto second
   
   CMP r9, #2           ;compare r9 and 2
   BEQ third			;if r9 is higher than or equal to 2, goto third

   CMP r9, #3
   BCS program_exit
   
skip					;label skip

   MOV r7, #0x0A        ;r7 = 0x0A
   MOV r8, #0x0B        ;r8 = 0x0B

Loop1					;loop label
   LDRB r4,[r1],#1		;Load to byte
   LDRB r5,[r2],#1      ;Load to byte
   
   CMP r4,r5            ;compare r4 and r5
   BNE Loop2            ;goto Loop2 branch (if r4 != r5)
   CMPEQ r4,#0          ;Check end of string (if r4 = 0)
   BNE Loop1            ;Move to Loop1 branch (if r4 != 0)
   BEQ Endline          ;Move to Endline branch (if r4 = 0)
   
Loop2
   STR r8, [r0]         ;Store the value of r8 in the address of r0 
   ADD r9, r9, #1		;r9 = r9 + 1(string count)
   MOV pc, lr			;goto Main

Endline
   STR r7, [r0]         ;Store the value of r7 in the address of r0
   ADD r9, r9, #1		;r9 = r9 + 1(string count)
   MOV pc, lr           ;goto main

first
   LDR r1, =C_string1   ;Insert address value of string
   LDR r2, =C_String2   ;Insert address value of string
   B skip				;goto skip
   
second
   LDR r1, =C_string3   ;Insert address value of string
   LDR r2, =C_String4   ;Insert address value of string
   B skip				;goto skip

third
   LDR r1, =C_string5   ;Insert address value of string
   LDR r2, =C_String6	;Insert address value of string
   B skip				;goto skip
   
C_string1 DCB "Hi",0   ;String declaration
C_String2 DCB "Hi",0   ;String declaration (first) C_string1 = C_string2
C_string3 DCB "Hi",0   ;String declaration
C_String4 DCB "Di",0   ;String declaration (second) C_String3 != C_String4
C_string5 DCB "De",0   ;String declaration
C_String6 DCB "Se",0   ;String declaration (third) C_String5 != C_String6

Address DCD &00040000  ;Location of address
program_exit
      END              ;Exit the program
		 