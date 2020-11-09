module cla64(a, b, ci, s, co);
	input [63:0] a, b;
	input ci;
	output [63:0] s;
	output co;
	wire z;
																			//cla32 * 2 = 64bit
	cla32 U0(.a(a[31:0]), .b(b[31:0]), .ci(ci), .s(s[31:0]), .co(z));
	cla32 U1(.a(a[63:32]), .b(b[63:32]), .ci(z), .s(s[63:32]), .co(co));
endmodule

module cla32(a, b, ci, s, co);
	input [31:0] a, b;
	input ci;
	output [31:0] s;
	output co;
	wire [6:0] z;
																			//cla4* 8 = 32bit
	cla4 U0(.a(a[3:0]), .b(b[3:0]), .ci(ci), .s(s[3:0]), .co(z[0]));
	cla4 U1(.a(a[7:4]), .b(b[7:4]), .ci(z[0]), .s(s[7:4]), .co(z[1]));
	cla4 U2(.a(a[11:8]), .b(b[11:8]), .ci(z[1]), .s(s[11:8]), .co(z[2]));
	cla4 U3(.a(a[15:12]), .b(b[15:12]), .ci(z[2]), .s(s[15:12]), .co(z[3]));
	cla4 U4(.a(a[19:16]), .b(b[19:16]), .ci(z[3]), .s(s[19:16]), .co(z[4]));
	cla4 U5(.a(a[23:20]), .b(b[23:20]), .ci(z[4]), .s(s[23:20]), .co(z[5]));
	cla4 U6(.a(a[27:24]), .b(b[27:24]), .ci(z[5]), .s(s[27:24]), .co(z[6]));
	cla4 U7(.a(a[31:28]), .b(b[31:28]), .ci(z[6]), .s(s[31:28]), .co(co));
endmodule

module cla8(a, b, ci, s, co);										//cla4 module
	input [7:0] a, b;
	input ci;
	output [7:0] s;
	output co;
	wire z;
																			//cla4 * 2 = 8bit
	cla4 U0(.a(a[3:0]), .b(b[3:0]), .ci(ci), .s(s[3:0]), .co(z));
	cla4 U1(.a(a[7:4]), .b(b[7:4]), .ci(z), .s(s[7:4]), .co(co));
endmodule

module cla4(a, b, ci, s, co);										//cla4 module
	input [3:0] a, b;
	input ci;
	output [3:0] s;
	output co;
	wire [2:0] z;
	
	
	fa_v2 U0_fa_v2(.ci(ci),.a(a[0]),.b(b[0]),.s(s[0]));	//full adder instance
	fa_v2 U1_fa_v2(.ci(z[0]),.a(a[1]),.b(b[1]),.s(s[1]));
	fa_v2 U2_fa_v2(.ci(z[1]),.a(a[2]),.b(b[2]),.s(s[2]));
	fa_v2 U3_fa_v2(.ci(z[2]),.a(a[3]),.b(b[3]),.s(s[3]));
	clb4 U4_clb4(.a(a), .b(b), .ci(ci), .c1(z[0]), .c2(z[1]), .c3(z[2]), .co(co));//clb4 module instance
	
endmodule

module clb4(a, b, ci, c1, c2, c3, co);
	input [3:0]a , b;
	input ci;
	output c1, c2, c3, co;
	
	wire [3:0] g, p;
	
	wire w0_c1;
	wire w0_c2, w1_c2;
	wire w0_c3, w1_c3, w2_c3;
	wire w0_co, w1_co, w2_co, w3_co;
	
	//Generate
	_and2 U0_and2(.a(a[0]),.b(b[0]),.y(g[0]));
	_and2 U1_and2(.a(a[1]),.b(b[1]),.y(g[1]));
	_and2 U2_and2(.a(a[2]),.b(b[2]),.y(g[2]));
	_and2 U3_and2(.a(a[3]),.b(b[3]),.y(g[3]));
	
	//propagate
	_or2 U4_or2(.a(a[0]),.b(b[0]),.y(p[0]));
	_or2 U5_or2(.a(a[1]),.b(b[1]),.y(p[1]));
	_or2 U6_or2(.a(a[2]),.b(b[2]),.y(p[2]));
	_or2 U7_or2(.a(a[3]),.b(b[3]),.y(p[3]));
	
	//c1 = g[0] | (p[0] & ci);
	_and2 U8_and2(.a(p[0]),.b(ci),.y(w0_c1));
	_or2 U9_or2(.a(g[0]),.b(w0_c1),.y(c1));
	
	//c2
	_and3 U10_and3(.a(p[1]),.b(p[0]),.c(ci),.y(w0_c2));
	_and2 U11_and2(.a(p[1]),.b(g[0]),.y(w1_c2));
	_or3 U12_and3(.a(w0_c2),.b(w1_c2),.c(g[1]),.y(c2));
	
	//c3
	_and3 U13_and3(.a(p[2]),.b(p[1]),.c(g[0]),.y(w0_c3));
	_and4 U14_and4(.a(p[2]),.b(p[1]),.c(p[0]),.d(ci),.y(w1_c3));
	_and2 U15_and2(.a(p[2]),.b(g[1]),.y(w2_c3));
	_or4 U16_and4(.a(w0_c3),.b(w1_c3),.c(w2_c3),.d(g[2]),.y(c3));
	
	//co
	_and5 U17_and5(.a(p[3]),.b(p[2]),.c(p[1]),.d(p[0]),.e(ci),.y(w0_co));
	_and4 U18_and4(.a(p[3]),.b(p[2]),.c(p[1]),.d(g[0]),.y(w1_co));
	_and3 U19_and3(.a(p[3]),.b(p[2]),.c(g[1]),.y(w2_co));
	_and2 U20_and2(.a(p[3]),.b(g[2]),.y(w3_co));
	_or5 U21_and5(.a(w0_co),.b(w1_co),.c(w2_co),.d(w3_co),.e(g[3]),.y(co));
	
endmodule

module fa_v2(ci,a,b,s);												//full adder
input ci,a,b;
output s;
wire x;

_xor2 U0_xor2(.a(a),.b(b),.y(x));								//xor gate
_xor2 U1_xor2(.a(x),.b(ci),.y(s));								//xor gate

endmodule
