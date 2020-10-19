module _register3_r(clk,reset_n,d,q);
	input clk,reset_n;		//input clk, reset_n
	input [2:0] d;			//input 3bit d
	output [2:0] q;			//output 3bit q

	//instance 3 _dff_r to make _register3_r
	_dff_r U0_dff_r(.clk(clk),.reset_n(reset_n),.d(d[0]),.q(q[0]));	
	_dff_r U1_dff_r(.clk(clk),.reset_n(reset_n),.d(d[1]),.q(q[1]));
	_dff_r U2_dff_r(.clk(clk),.reset_n(reset_n),.d(d[2]),.q(q[2]));

endmodule
	