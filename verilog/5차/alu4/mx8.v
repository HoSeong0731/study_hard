module mx8(a, b, c, d, e, f, g, h, s2, s1, s0, y);
input a, b, c, d, e, f, g, h;		//input a, b, c, d, e, f, g, h
input s2, s1, s0;						//input s2, s1, s0
output y;								//output y
wire w0, w1, w2, w3, w4, w5;		//wire w0, w1, w2, w3, w4, w5
mx2 U0_mx2(.d0(a), .d1(b), .s(s0), .y(w0));		//load module mx2
mx2 U1_mx2(.d0(c), .d1(d), .s(s0), .y(w1));		//load module mx2
mx2 U2_mx2(.d0(e), .d1(f), .s(s0), .y(w2));		//load module mx2
mx2 U3_mx2(.d0(g), .d1(h), .s(s0), .y(w3));		//load module mx2
mx2 U4_mx2(.d0(w0), .d1(w1), .s(s1), .y(w4));	//load module mx2
mx2 U5_mx2(.d0(w2), .d1(w3), .s(s1), .y(w5));	//load module mx2
mx2 U6_mx2(.d0(w4), .d1(w5), .s(s2), .y(y));		//load module mx2
endmodule