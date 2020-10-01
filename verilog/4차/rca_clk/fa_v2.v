module fa(a,b, ci, s, co);	//3input
input a, b, ci;				//input a and b and carry in
output s, co;					//output sum and carry out
wire [2:0]w;					//2*1 wire
ha U0_ha(.a(b), .b(ci), .s(w[0]), .co(w[1]));	//load half adder
ha U1_ha(.a(a), .b(w[0]), .s(s), .co(w[2]));		//load half adder
_or2 U2_or(.a(w[1]),.b(w[2]), .y(co));				//load 2 input or gate
endmodule						//end module
