module _dff(clk, d, q, q_bar);

	input 	clk, d;				//input CLK, D
	output	q, q_bar;			//output q, q_bar
	wire		clk_bar, w_q;	//wire clk_bar, w_q
	
	_inv U0_inv(.a(clk), .y(clk_bar));		//load inverter
	_dlatch U1_dlatch(.clk(clk_bar), .d(d), .q(w_q), .q_bar());		//load D Latch
	_dlatch U2_dlatch(.clk(clk), .d(w_q), .q(q), .q_bar(q_bar));	//load D Latch
	
endmodule
