module ha(a, b, s, co);	//start half adder
input a, b;					//2input
output s, co ;				//2output
_and2 and2(.a(a), .b(b), .y(co));	//load module 2input and gate
_xor2 xor2(.a(a), .b(b), .y(s));		//load module 2input xor gate
endmodule					//end half adder
