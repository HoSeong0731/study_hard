module register8_r_en(clk,reset_n,d_in,d_out,en);
	input clk,reset_n,en;	//input clk, reset_n, en
	input [7:0]d_in;		//input 8bit d_in
	output [7:0]d_out;		//output 8bit d_out
	
	_dff_r_en U0(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[0]),.q(d_out[0]));//instance en able d flip flop
	_dff_r_en U1(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[1]),.q(d_out[1]));//instance en able d flip flop
	_dff_r_en U2(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[2]),.q(d_out[2]));//instance en able d flip flop
	_dff_r_en U3(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[3]),.q(d_out[3]));//instance en able d flip flop
	_dff_r_en U4(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[4]),.q(d_out[4]));//instance en able d flip flop
	_dff_r_en U5(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[5]),.q(d_out[5]));//instance en able d flip flop
	_dff_r_en U6(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[6]),.q(d_out[6]));//instance en able d flip flop
	_dff_r_en U7(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[7]),.q(d_out[7]));//instance en able d flip flop
endmodule