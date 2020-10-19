module _register2_r(clk, reset_r, d, q);

	input 				clk, reset_r;
	input		[1:0]		d;
	output	[1:0]		q;
	
	_dff_rs_async U0_dff_rs_async(.clk(clk), .reset_n(reset_r), .d(d[0]), .q(q[0]));
	_dff_rs_async U1_dff_rs_async(.clk(clk), .reset_n(reset_r), .d(d[1]), .q(q[1]));
	
	endmodule
