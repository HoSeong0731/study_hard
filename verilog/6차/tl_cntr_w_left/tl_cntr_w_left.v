module tl_cntr_w_left(clk, reset_n, Ta, Tal, Tb, Tbl, La, Lb);

	input clk, reset_n, Ta, Tal, Tb, Tbl;
	output	[1:0]		La, Lb;
	
	wire		[2:0]		q, d;
	
	//instance of each circuit
	ns_logic U0_ns_logic(.Ta(Ta), .Tal(Tal), .Tb(Tb), .Tbl(Tbl), .q(q[2:0]), .d(d[2:0]));
	_register3_r U1_register3_r(.clk(clk), .reset(reset_n), .q(q[2:0]), .d(d[2:0]));
	o_logic U2_o_logic(.q(q[2:0]), .La(La[1:0]), .Lb(Lb[1:0]));
	
endmodule
