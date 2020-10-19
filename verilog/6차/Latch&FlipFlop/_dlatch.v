module _dlatch(clk, d, q, q_bar);

	input 	clk, d;				//input clk, d
	output 	q, q_bar;			//output q, q_bar
	wire 		d_bar, r, s;	//wire d_bar, r, s
	
	_inv U0_inv(.a(d), .y(d_bar));				//load inverter
	_and2 U1_and2(.a(clk), .b(d_bar), .y(r));	//load 2 input and gate
	_and2 U2_and2(.a(clk), .b(d), .y(s));		//load 2 input and gate
	_srlatch U3_srlatch(.r(r), .s(s), .q(q), .q_bar(q_bar));	//load SR Latch
	
endmodule