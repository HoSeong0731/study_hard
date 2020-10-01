module fa_v2(a,b,ci,s);	//3input 
input a,b,ci;				//input a and b, and carry in
output s;					//1output
wire w0;						//1wire
_xor2 U0_xor2(.a(a), .b(b), .y(w0));	//2input xor gate
_xor2 U1_xor2(.a(w0), .b(ci), .y(s));	//2input xor gate
endmodule					//end module
