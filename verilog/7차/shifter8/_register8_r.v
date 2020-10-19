module _register8_r(clk, reset_n, d, q);
	input	clk, reset_n;			//input clk, reset_n
	input [7:0]	d;					//input 8bit d
	output [7:0] q;					//output 8bit q
	
	//instance 8 D flip-flop to make register 8
	_dff_r U0_dff (.clk(clk), .reset_n(reset_n), .d(d[0]), .q(q[0]));
	_dff_r U1_dff (.clk(clk), .reset_n(reset_n), .d(d[1]), .q(q[1]));
	_dff_r U2_dff (.clk(clk), .reset_n(reset_n), .d(d[2]), .q(q[2]));
	_dff_r U3_dff (.clk(clk), .reset_n(reset_n), .d(d[3]), .q(q[3]));
	_dff_r U4_dff (.clk(clk), .reset_n(reset_n), .d(d[4]), .q(q[4]));
	_dff_r U5_dff (.clk(clk), .reset_n(reset_n), .d(d[5]), .q(q[5]));
	_dff_r U6_dff (.clk(clk), .reset_n(reset_n), .d(d[6]), .q(q[6]));
	_dff_r U7_dff (.clk(clk), .reset_n(reset_n), .d(d[7]), .q(q[7]));
endmodule
	