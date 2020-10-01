module cla4(a,b,ci,s,co);	//3input 
input [3:0] a,b;
input ci;
output [3:0] s;				//2output
output co;
wire c1, c2, c3;				//3 wire
fa_v2 U0_fa (.a(a[0]), .b(b[0]), .ci(ci), .s(s[0]));	//1bit full adder
fa_v2 U1_fa (.a(a[1]), .b(b[1]), .ci(c1), .s(s[1]));	//1bit full adder
fa_v2 U2_fa (.a(a[2]), .b(b[2]), .ci(c2), .s(s[2]));	//1bit full adder
fa_v2 U3_fa (.a(a[3]), .b(b[3]), .ci(c3), .s(s[3]));	//1bit full adder
clb4 U4_clb4(.a(a), .b(b), .ci(ci), .c1(c1), .c2(c2), .c3(c3), .co(co));	//4bit clack block
endmodule	//end module
