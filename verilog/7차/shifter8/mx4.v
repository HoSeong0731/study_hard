module mx4(d0,d1,d2,d3,s,y);
	input d0,d1,d2,d3;
	input [1:0] s;
	output y;
	
	wire w0,w1;
	
	//instance 3 2-to-1 muxs to make mx4
	//d0,d1,s,y
	mx2 U0_mx2(.d0(d0), .d1(d1), .s(s[0]), .y(w0));
	mx2 U1_mx2(.d0(d2), .d1(d3), .s(s[0]), .y(w1));
	mx2 U2_mx2(.d0(w0), .d1(w1), .s(s[1]), .y(y));
	
endmodule
