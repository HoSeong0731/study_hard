module _dlatch(clk, d, q, q_bar);

	input 	clk, d;
	output 	q, q_bar;
	wire 		d_bar, r, s;
	
	_inv U0_inv(.a(d), .y(d_bar));
	_and2 U1_and2(.a(clk), .b(d_bar), .y(r));
	_and2 U2_and2(.a(clk), .b(d), .y(s));
	_srlatch U3_srlatch(.r(r), .s(s), .q(q), .q_bar(q_bar));
	
endmodule