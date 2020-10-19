module _dff_r(clk, reset_n, d, q);

	input		clk, reset_n, d;
	output	q;
	
	wire		w_d;
	
	_and2 U0_and2(.a(d), .b(reset_n), .y(w_d));
	_dff U0_dff(.clk(clk), .d(w_d), .q(q), .q_bar());
	
	endmodule
	