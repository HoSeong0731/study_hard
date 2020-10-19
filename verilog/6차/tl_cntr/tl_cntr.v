module tl_cntr(clk, reset_n, Ta, Tb, La, Lb);

	input					clk, reset_n, Ta, Tb;
	output	[1:0]		La, Lb;

	wire		[1:0]		d, q;
	
	ns_logic U0_ns_logic(.Ta(Ta), .Tb(Tb), .q(q[1:0]), .d(d[1:0]));
	_register2_r U1_register2_r(.clk(clk), .reset_r(reset_n), .d(d[1:0]), .q(q[1:0]));
	o_logic U2_o_logic(.Q(q[1:0]), .La(La[1:0]), .Lb(Lb[1:0]));
	
endmodule
