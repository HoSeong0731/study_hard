module _inv(a,y);	//start not gate
input a;				//1input
output y;			//1output
assign y=~a;		//Invert input value.
endmodule			//end not gate

module _nand2(a,b,y);//start 2input nand gate
input a,b;				//2input
output y;				//1output
assign y=~(a&b);		//nand two inputs
endmodule				//end 2input nand gate

module _and2(a,b,y);	//start 2input and gate
input a,b;				//2input
output y;				//1output
assign y=a&b;			//and two inputs
endmodule				//end 2input and gate

module _or2(a,b,y);	//start 2input or gate
input a,b;				//2input
output y;				//1output
assign y=a|b;			//or two inputs
endmodule				//end 2input or gate

module _xor2(a,b,y);	//start 2input xor gate
input a, b;				//2input
output y;				//1output
wire inv_a, inv_b;	//wire inv value a and b
wire w0, w1;			//create w0 and w1
_inv U0_inv(.a(a), .y(inv_a));	//load module inv
_inv U1_inv(.a(b), .y(inv_b));	//load module inv
_and2 U2_and2(.a(inv_a), .b(b), .y(w0));	//load module and
_and2 U3_and2(.a(a),.b(inv_b), .y(w1));	//load module and
_or2 U4_or2(.a(w0), .b(w1),.y(y));			///load module or
endmodule				//end 2input xor gate
