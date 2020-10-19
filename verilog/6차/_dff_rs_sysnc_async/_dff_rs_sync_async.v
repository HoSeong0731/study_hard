module _dff_rs_sync_async(clk, set_n, reset_n, d, q_sync, q_async);

	input		clk, set_n, reset_n, d;
	output	q_sync, q_async;

	_dff_rs_sync U0_dff_rs_sync(.clk(clk), .set_n(set_n), .reset_n(reset_n), .d(d), .q(q_sync));
	_dff_rs_async U1_dff_rs_async(.clk(clk), .set_n(set_n), .reset_n(reset_n), .d(d), .q(q_async));
	
	endmodule
