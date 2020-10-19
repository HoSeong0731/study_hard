module shifter8(clk, reset_n, op, shamt, d_in, d_out);
	input clk, reset_n;		//input clk, reset_n
	input [2:0] op; 		//3bit op
	input [1:0] shamt; 		//2bit shamt
	input [7:0] d_in; 		//8bit d_in
	output [7:0] d_out; 	//8bit d_out
	wire  [7:0] d_next;		//8bit d_next
	
	_register8_r U0_register_r(.clk(clk), .reset_n(reset_n), 
								.d(d_next), .q(d_out));	 
								//instance register8
	
	cc_logic	U1_cc_logic(.op(op), .shamt(shamt), .d_in(d_in), 
								.d_out(d_out), .d_next(d_next)); 
								//instacne cc_logic

endmodule
