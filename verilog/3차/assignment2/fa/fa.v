module fa(a,b,ci,s,co);	//start full adder
input a,b,ci;				//3 input
output s;					//first output
output co;					//second output (carry out)
wire c1,c2,sm;				//create wire c1, c2, sm
ha U0_ha(.a(b), .b(ci), .s(sm), .co(c1));	//load module half adder
ha U1_ha(.a(a), .b(sm), .s(s), .co(c2));	//load module half adder
_or2 U2_or2(.a(c1), .b(c2), .y(co));		//load module 2 input or gate
endmodule					//end full adder
