`timescale 1ns/100ps

module tb_dff_en;		// testbench of D flip-flop enable

	reg		tb_clk, tb_en, tb_d;	//reg clk, en, d	
	wire		tb_q;				//wire q
	
	parameter STEP = 10;
	
	_dff_en U0_dff_en(.clk(tb_clk), .en(tb_en), .d(tb_d), .q(tb_q));	//load D flip-flop
	
	always #(STEP / 2) tb_clk = ~tb_clk;			
	
	initial
	
	begin											//start test
		tb_clk = 1'b0; tb_en = 1'b1; tb_d = 1'b0;
		#3;	tb_d = 1'b1;
		#(STEP); tb_d = 1'b0;
		#(STEP); tb_d = 1'b1;
		#(STEP); tb_d = 1'b0;
		#(STEP); tb_d = 1'b1;
		#(STEP); tb_d = 1'b0; tb_en = 1'b0;
		#(STEP); tb_d = 1'b1;
		#(STEP); tb_d = 1'b0;
		#(STEP); tb_d = 1'b1;
		#(STEP); tb_d = 1'b0;
		#(STEP); tb_d = 1'b1;
		#(STEP); tb_d = 1'b0;
		#(STEP); $stop;
	end												//end test
endmodule
