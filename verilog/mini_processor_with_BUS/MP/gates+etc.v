module _inv_32bits(a, y);
input [31:0] a;
output [31:0] y;
assign y=~a;
endmodule

module _and2_32bits(a, b, y);
input [31:0] a, b;
output [31:0] y;
assign y=a&b;
endmodule

module _or2_32bits(a, b, y);
input [31:0] a, b;
output [31:0] y;
assign y=a|b;
endmodule

//---------------------make xor32bit---------------------------------------------

module _xor2(a,b,y);								//start 2input xor gate
input a, b;											//2input
output y;											//1output
wire inv_a, inv_b;								//wire inv value a and b
wire w0, w1;										//create w0 and w1
_inv U0_inv(.a(a), .y(inv_a));				//load module inv
_inv U1_inv(.a(b), .y(inv_b));				//load module inv
_and2 U2_and2(.a(inv_a), .b(b), .y(w0));	//load module and
_and2 U3_and2(.a(a),.b(inv_b), .y(w1));	//load module and
_or2 U4_or2(.a(w0), .b(w1),.y(y));			///load module or
endmodule											//end 2input xor gate

module _xor2_4bits(a,b,y);							//start 4bit 2input xor gate
input [3:0] a,b;										//4bit input a, b
output [3:0] y;										//4bit output y
_xor2 U0_xor2(.a(a[0]), .b(b[0]), .y(y[0]));	//y = a xor b 	first bit
_xor2 U1_xor2(.a(a[1]), .b(b[1]), .y(y[1]));	//            	second bit
_xor2 U2_xor2(.a(a[2]), .b(b[2]), .y(y[2]));	//					third bit
_xor2 U3_xor2(.a(a[3]), .b(b[3]), .y(y[3]));	//					forth bit
endmodule												//end 4bit 2input xor gate

module _xor2_32bits(a,b,y);														//start 32bit 2input xor gate
input [31:0] a,b;																		//input 32bit a, b
output [31:0] y;																		//output 32bit y
_xor2_4bits U0_xor2_4bits(.a(a[3:0]), .b(b[3:0]), .y(y[3:0]));			//4bit 2input xor gate 0~3
_xor2_4bits U1_xor2_4bits(.a(a[7:4]), .b(b[7:4]), .y(y[7:4]));			//4bit 2input xor gate 4~8
_xor2_4bits U2_xor2_4bits(.a(a[11:8]), .b(b[11:8]), .y(y[11:8]));		//4bit 2input xor gate 9~11
_xor2_4bits U3_xor2_4bits(.a(a[15:12]), .b(b[15:12]), .y(y[15:12]));	//4bit 2input xor gate 12~15
_xor2_4bits U4_xor2_4bits(.a(a[19:16]), .b(b[19:16]), .y(y[19:16]));	//4bit 2input xor gate 16~19
_xor2_4bits U5_xor2_4bits(.a(a[23:20]), .b(b[23:20]), .y(y[23:20]));	//4bit 2input xor gate 20~23
_xor2_4bits U6_xor2_4bits(.a(a[27:24]), .b(b[27:24]), .y(y[27:24]));	//4bit 2input xor gate 24~27
_xor2_4bits U7_xor2_4bits(.a(a[31:28]), .b(b[31:28]), .y(y[31:28]));	//4bit 2input xor gate 27~31
endmodule																				//end 32bit 2input xor gate


//---------------------make xnor32bit---------------------------------------------

module _inv_4bits(a,y);		//start 4input not gate
input [3:0] a;					//4bit input	
output [3:0] y;				//4bit output
assign y=~a;					// y = not a
endmodule						//end 4input not gate

module _xnor2_4bits(a,b,y);							//start 4bit 2input xnor gate
input [3:0] a,b;											//4bit input a, b
output [3:0] y;											//4bit output y
wire [3:0] w0;												//4bit wire w0		
_xor2_4bits U0_xor2_4bits(.a(a), .b(b), .y(w0));//module 4bit 2input xor gate
_inv_4bits U1_inv_4bits(.a(w0), .y(y));			//module 4bit 2input not gate
endmodule	

module _xnor2_32bits(a,b,y);															//start 32bit 2input xnor gate
input [31:0] a,b;																			//input 32bit a, b
output [31:0] y;																			//output 32bit y
_xnor2_4bits U0_xnor2_4bits(.a(a[3:0]), .b(b[3:0]), .y(y[3:0]));			//4bit 2input xnor gate 0~3
_xnor2_4bits U1_xnor2_4bits(.a(a[7:4]), .b(b[7:4]), .y(y[7:4]));			//4bit 2input xnor gate 4~7
_xnor2_4bits U2_xnor2_4bits(.a(a[11:8]), .b(b[11:8]), .y(y[11:8]));		//4bit 2input xnor gate 8~11
_xnor2_4bits U3_xnor2_4bits(.a(a[15:12]), .b(b[15:12]), .y(y[15:12]));	//4bit 2input xnor gate 12~15
_xnor2_4bits U4_xnor2_4bits(.a(a[19:16]), .b(b[19:16]), .y(y[19:16]));	//4bit 2input xnor gate 16~19
_xnor2_4bits U5_xnor2_4bits(.a(a[23:20]), .b(b[23:20]), .y(y[23:20]));	//4bit 2input xnor gate 20~23
_xnor2_4bits U6_xnor2_4bits(.a(a[27:24]), .b(b[27:24]), .y(y[27:24]));	//4bit 2input xnor gate 24~27
_xnor2_4bits U7_xnor2_4bits(.a(a[31:28]), .b(b[31:28]), .y(y[31:28]));	//4bit 2input xnor gate 28~31
endmodule																					//end 32bit 2input xnor gate


//---------------------make cla32bit----------------------------------------------

module fa_v2(a,b,ci,s);						//3input 
input a,b,ci;									//input a and b, and carry in
output s;										//1output
wire w0;											//1wire
_xor2 U0_xor2(.a(a), .b(b), .y(w0));	//2input xor gate
_xor2 U1_xor2(.a(w0), .b(ci), .y(s));	//2input xor gate
endmodule										//end module


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

module _and3(a,b,c,y);	//start 3input and gate
input a,b,c;				//3input
output y;					//1output
assign y=a&b&c;			//and three inputs
endmodule					//end 3input and gate

module _and4(a,b,c,d,y);//start 4input and gate
input a,b,c,d;				//4input
output y;					//1output
assign y=a&b&c&d;			//and four inputs
endmodule					//end 4input and gate

module _and5(a,b,c,d,e,y);	//start 5input and gate
input a,b,c,d,e;				//5input
output y;						//1output
assign y=a&b&c&d&e;			//and five inputs
endmodule						//end 5input and gate

module _or3(a,b,c,y);	//start 3input or gate
input a,b,c;				//3input
output y;					//1output
assign y=a|b|c;			//or three inputs
endmodule					//end 3input or gate

module _or4(a,b,c,d,y);	//start 4input or gate
input a,b,c,d;				//4input	
output y;					//1output
assign y=a|b|c|d;			//or four inputs
endmodule					//end 4input or gate

module _or5(a,b,c,d,e,y);	//start 5input or gate
input a,b,c,d,e;				//5input	
output y;						//1output
assign y=a|b|c|d|e;			//or five inputs
endmodule						//end 5input or gate

module clb4(a,b,ci,c1,c2,c3,co);	
input [3:0]a,b;		//3input
input ci;
output c1,c2,c3,co;	//4output

wire [3:0] g,p;		//4*1 wire
wire w0_c1;
wire w0_c2, w1_c2;
wire w0_c3, w1_c3, w2_c3;
wire w0_co, w1_co, w2_co, w3_co;	//etc wire

// Generate
_and2 U0_and2(.a(a[0]),.b(b[0]),.y(g[0]));	//2input and gate
_and2 U1_and2(.a(a[1]),.b(b[1]),.y(g[1]));	//2input and gate
_and2 U2_and2(.a(a[2]),.b(b[2]),.y(g[2]));	//2input and gate
_and2 U3_and2(.a(a[3]),.b(b[3]),.y(g[3]));	//2input and gate

// Propagate
_or2 U4_or2(.a(a[0]),.b(b[0]),.y(p[0]));	//2input or gate
_or2 U5_or2(.a(a[1]),.b(b[1]),.y(p[1]));	//2input or gate
_or2 U6_or2(.a(a[2]),.b(b[2]),.y(p[2]));	//2input or gate
_or2 U7_or2(.a(a[3]),.b(b[3]),.y(p[3])); 	//2input or gate

/*	Gi = AiBiPi = Ai + Bi
	C1 = G0 + P0C0
	C2 = G1 + P1G0 + P1P0C0
	C3 = G2 + P2G1 + P2P1G0 + P2P1P0C0
	CO = G3 + P3G2 + P3P2G1 + P3P2P1G0 + P3P2P1P0C0
*/

// c1 = g[0] | (p[0] & ci);
_and2 U8_and2(.a(p[0]),.b(ci),.y(w0_c1));	//2input and gate
_or2 U9_or2(.a(g[0]),.b(w0_c1),.y(c1));	//2input or gate

// c2 = g[1] | (p[1] & g[0]) | (p[1] & p[0] & ci);
_and2 U9_and2(.a(p[1]),.b(g[0]),.y(w0_c2));				//2input and gate
_and3 U10_and3(.a(p[1]),.b(p[0]),.c(ci),.y(w1_c2));	//3input and gate
_or3 U11_or3(.a(g[1]),.b(w0_c2),.c(w1_c2),.y(c2));		//3input pr gate

// c3 = g[2] | (p[2] & g[1]) | (p[2] & p[1] & g[0]) | (p[2] & p[1] & p[0] & ci);
_and2 U12_and2(.a(p[2]),.b(g[1]),.y(w0_c3));							//2input and gate
_and3 U13_and3(.a(p[2]),.b(p[1]),.c(ci),.y(w1_c3));				//3input and gate
_and4 U14_and4(.a(p[2]),.b(p[1]),.c(p[0]),.d(g[0]),.y(w2_c3));	//4input	and gate
_or4 U15_or4(.a(g[2]),.b(w0_c3),.c(w1_c3),.d(w2_c3),.y(c3));	//4input or gate

// co = g[3] | (p[3] & g[2]) | (p[3] & p[2] & g[1]  | (p[3] & p[2] & p[1] & g[0]) | (p[3] & p[2] & p[1] & p[0] & ci)
_and2 U16_and2(.a(p[3]),.b(g[2]),.y(w0_co));										//2input and gate
_and3 U17_and3(.a(p[3]),.b(p[2]),.c(g[1]),.y(w1_co));							//3input and gate
_and4 U18_and4(.a(p[3]),.b(p[2]),.c(p[1]),.d(g[0]),.y(w2_co));				//4input and gate
_and5 U19_and5(.a(p[3]),.b(p[2]),.c(p[1]),.d(g[0]),.e(ci),.y(w3_co));	//5input and gate
_or5 U20_or5(.a(g[3]),.b(w0_co),.c(w1_co),.d(w2_co),.e(w3_co),.y(co));	//5input or gate
endmodule	//end module

module cla4_ov(a, b, ci, s, c3, co);
input [3:0] a, b;	//input 4bit a, b
input ci;			//input carry in
output [3:0] s;	//output 4bit s
output c3, co;		//output c3, co
wire c1, c2;		//wire c1, c2
fa_v2 U0_fa (.a(a[0]),.b(b[0]),.ci(ci),.s(s[0]));		//full adder 1bit
fa_v2 U1_fa (.a(a[1]),.b(b[1]),.ci(c1),.s(s[1]));		//full adder 1bit
fa_v2 U2_fa (.a(a[2]),.b(b[2]),.ci(c2),.s(s[2]));		//full adder 1bit
fa_v2 U3_fa (.a(a[3]),.b(b[3]),.ci(c3),.s(s[3]));		//full adder 1bit
clb4 U4_clb4(.a(a), .b(b), .ci(ci), .c1(c1), .c2(c2), .c3(c3), .co(co));	//load module Clock lock ahead block
endmodule

module cla32_ov(a, b, ci, s, co_prev, co);
input [31:0] a, b;		//input 32bit a, b
input ci;					//input carry in
output [31:0] s;			//output 32bit s
output co_prev;			//output preview carry out
output co;					//output carry out
wire c1, c2, c3, c4, c5, c6, c7;	//wire c1 ~ c7
cla4 U0_cla4 (.a(a[3:0]), .b(b[3:0]), .ci(ci), .s(s[3:0]), .co(c1));			//load cla4(0~3)
cla4 U1_cla4 (.a(a[7:4]), .b(b[7:4]), .ci(c1), .s(s[7:4]), .co(c2));			//load cla4(4~7)
cla4 U2_cla4 (.a(a[11:8]), .b(b[11:8]), .ci(c2), .s(s[11:8]), .co(c3));		//load cla4(8~11)
cla4 U3_cla4 (.a(a[15:12]), .b(b[15:12]), .ci(c3), .s(s[15:12]), .co(c4));	//load cla4(12~15)
cla4 U4_cla4 (.a(a[19:16]), .b(b[19:16]), .ci(c4), .s(s[19:16]), .co(c5));	//load cla4(16~19)
cla4 U5_cla4 (.a(a[23:20]), .b(b[23:20]), .ci(c5), .s(s[23:20]), .co(c6));	//load cla4(20~23)
cla4 U6_cla4 (.a(a[27:24]), .b(b[27:24]), .ci(c6), .s(s[27:24]), .co(c7));	//load cla4(24~27)
cla4_ov U7_cla4_ov (.a(a[31:28]), .b(b[31:28]), .ci(c7), .s(s[31:28]), .c3(co_prev), .co(co));	//load cla_ov
endmodule


//---------------------make mx8_32bit----------------------------------------------

module mx2_32bits(d0, d1, s, y);
input [31:0] d0, d1;		//input 32bit do, d1
input s;						//input s
output [31:0] y;			//output 32bit y
assign y=(s==0)?d0:d1;	//y = s? d0:d1
endmodule				

module mx8_32bits(a, b, c, d, e, f, g, h, s2, s1, s0, y);
input [31:0] a, b, c, d, e, f, g, h;		//32bit input a~h
input s2, s1, s0;									//input s2, s1, s0
output [31:0] y;									//output 32bit y
wire [31:0] w0, w1, w2, w3, w4, w5;			//wire w0~w5
mx2_64bits U0_mx2_64bits(.d0(a), .d1(b), .s(s0), .y(w0));	//load module 32bit mx2
mx2_64bits U1_mx2_64bits(.d0(c), .d1(d), .s(s0),.y(w1));		//load module 32bit mx2
mx2_64bits U2_mx2_64bits(.d0(e), .d1(f), .s(s0), .y(w2));	//load module 32bit mx2
mx2_64bits U3_mx2_64bits(.d0(g), .d1(h), .s(s0),.y(w3));		//load module 32bit mx2
mx2_64bits U4_mx2_64bits(.d0(w0), .d1(w1), .s(s1),.y(w4));	//load module 32bit mx2
mx2_64bits U5_mx2_64bits(.d0(w2), .d1(w3), .s(s1),.y(w5));	//load module 32bit mx2
mx2_64bits U6_mx2_64bits(.d0(w4), .d1(w5), .s(s2),.y(y));	//load module 32bit mx2
endmodule 

//---------------------make cla4, cla8, cla32bit(MUL)----------------------------------------------

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

//-
