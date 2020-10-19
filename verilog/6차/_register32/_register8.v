module _register8(clk, d, q);

	input					clk;
	input		[7:0]		d;
	output	[7:0]		q;
	
	_dff U0_dff(.clk(clk), .d(d[7]), .q(q[7]), .q_bar());
	_dff U1_dff(.clk(clk), .d(d[6]), .q(q[6]), .q_bar());
	_dff U2_dff(.clk(clk), .d(d[5]), .q(q[5]), .q_bar());
	_dff U3_dff(.clk(clk), .d(d[4]), .q(q[4]), .q_bar());
	_dff U4_dff(.clk(clk), .d(d[3]), .q(q[3]), .q_bar());
	_dff U5_dff(.clk(clk), .d(d[2]), .q(q[2]), .q_bar());
	_dff U6_dff(.clk(clk), .d(d[1]), .q(q[1]), .q_bar());
	_dff U7_dff(.clk(clk), .d(d[0]), .q(q[0]), .q_bar());
	
endmodule
