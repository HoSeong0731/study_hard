module _dff(clk, d, q, q_bar);

	input 	clk, d;
	output	q, q_bar;
	wire		clk_bar, w_q;
	
	_inv U0_inv(.a(clk), .y(clk_bar));
	_dlatch U1_dlatch(.clk(clk_bar), .d(d), .q(w_q), .q_bar());
	_dlatch U2_dlatch(.clk(clk), .d(w_q), .q(q), .q_bar(q_bar));
	
endmodule
