`timescale 1ns/100ps

module tb_dlatch;		//testbench of D Latch

	reg tb_clk, tb_d;		//reg clk, d
	wire tb_q, tb_q_bar;	//wire q, q_bar
	
	_dlatch U0_dlatch(.clk(tb_clk), .d(tb_d), .q(tb_q), .q_bar(tb_q_bar));
	//load D Latch

	initial
	
	begin										//start test
		tb_clk = 1'b0; tb_d = 1'b0;
		#15;	tb_clk = 1'b0; tb_d = 1'b1;
		#10;	tb_clk = 1'b1; tb_d = 1'b1;
		#5;	tb_clk = 1'b1; tb_d = 1'b0;
		#20;	tb_clk = 1'b0; tb_d = 1'b0;
		#10;	tb_clk = 1'b0; tb_d = 1'b1;
		#10;	tb_clk = 1'b0; tb_d = 1'b0;
		#5;	tb_clk = 1'b1; tb_d = 1'b0;
		#15;	tb_clk = 1'b1; tb_d = 1'b1;
		#10;	tb_clk = 1'b0; tb_d = 1'b1;
		#10;	tb_clk = 1'b0; tb_d = 1'b0;
		#15;	tb_clk = 1'b1; tb_d = 1'b0;
		#20;	$stop;
	end											//end test

endmodule
	