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
_and3 U13_and3(.a(p[2]),.b(p[1]),.c(g[0]),.y(w1_c3));				//3input and gate
_and4 U14_and4(.a(p[2]),.b(p[1]),.c(p[0]),.d(g[0]),.y(w2_c3));	//4input	and gate
_or4 U15_or4(.a(g[2]),.b(w0_c3),.c(w1_c3),.d(w2_c3),.y(c3));	//4input or gate

// co = g[3] | (p[3] & g[2]) | (p[3] & p[2] & g[1]  | (p[3] & p[2] & p[1] & g[0]) | (p[3] & p[2] & p[1] & p[0] & ci)
_and2 U16_and2(.a(p[3]),.b(g[2]),.y(w0_co));										//2input and gate
_and3 U17_and3(.a(p[3]),.b(p[2]),.c(g[1]),.y(w1_co));							//3input and gate
_and4 U18_and4(.a(p[3]),.b(p[2]),.c(p[1]),.d(g[0]),.y(w2_co));				//4input and gate
_and5 U19_and5(.a(p[3]),.b(p[2]),.c(p[1]),.d(g[0]),.e(ci),.y(w3_co));	//5input and gate
_or5 U20_or5(.a(g[3]),.b(w0_co),.c(w1_co),.d(w2_co),.e(w3_co),.y(co));	//5input or gate
endmodule	//end module
