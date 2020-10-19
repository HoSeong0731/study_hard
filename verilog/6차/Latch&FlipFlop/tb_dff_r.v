`timescale 1ns/100ps

module tb_dff_r;		//testbench of D flip-flop resettable

	reg	tb_clk, tb_reset_n, tb_d;	//reg clk, reset_n, d
	wire	tb_q;					//wire q
	
	parameter STEP = 10;
	
	_dff_r U0_dff_r(.clk(tb_clk), .reset_n(tb_reset_n), .d(tb_d), .q(tb_q));	//load D flip-flop resettable
	
	always #(STEP / 2) tb_clk = ~tb_clk;
	
	initial
	
	begin															//start test
		tb_clk = 1'b0; tb_reset_n = 1'b0; tb_d = 1'b0;
		#(STEP / 3);	tb_d = 1'b1;
		#(STEP);			tb_reset_n = 1'b1; tb_d = 1'b0;
		#(STEP); tb_d = 1'b1;	#(STEP); tb_d = 1'b0; #(STEP); tb_d = 1'b1;	#(STEP); tb_d = 1'b0;
		#(STEP); tb_d = 1'b1;	#(STEP); tb_d = 1'b0; #(STEP); tb_d = 1'b1;	#(STEP); tb_d = 1'b0;
		#(STEP); tb_d = 1'b1;	#(STEP); tb_d = 1'b0;
		#(STEP * 2); tb_reset_n = 1'b0; tb_d = 1'b1;
		#(STEP); tb_d = 1'b0; #(STEP); tb_d = 1'b1;
		#(STEP); $stop;
	end																//end test
endmodule
