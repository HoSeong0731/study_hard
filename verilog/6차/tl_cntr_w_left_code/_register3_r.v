module _register3_r(clk, reset, q, d); //3 bit register_r

	input 				clk, reset;		//input clk, reset
	input		[2:0]		d;			//input 3bit d
	output	[2:0]		q;				//output 3bit q
	
	//3 registers share 1 clk and move simultaneously
	_dff_r_async U0_dff_r_async(.clk(clk), .reset(reset), .d(d[0]), .q(q[0]));		//load D flip-flop_r_async
	_dff_r_async U1_dff_r_async(.clk(clk), .reset(reset), .d(d[1]), .q(q[1]));		//load D flip-flop_r_async
	_dff_r_async U2_dff_r_async(.clk(clk), .reset(reset), .d(d[2]), .q(q[2]));		//load D flip-flop_r_async
	
endmodule
