   AREA ARMex, CODE, READONLY
      ENTRY
      
Main
   LDR r0, Address      ;Insert address value
   MOV r1, #1           ;Insert value
   MOV r2,r1,LSL #1     ;Shift the bit stream to the left by a 1
   MOV r3,r2,LSL #2     ;Shift the bit stream to the left by a 2
   ADD r4,r2,r3         ;Add r2 and r3 to r4
   
Loop
   ADD r5,r6,r4         ;Express n+10
   MUL r5,r6,r5         ;Express n(n+10)
   CMP r6,r4            ;Compare r6 to r4
   ADD r6,r6,#1         ;Add 1 to r6
   BEQ Endline          ;Move to Endline branch (if r6 = r4)
   B Loop               ;Move to Loop branch
   
Endline   
   STR r5, [r0]         ;Store the value of r5 in the address of r0
   
Address DCD &00040000
   END                  ;Exit the program