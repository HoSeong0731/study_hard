
`timescale 1ns/100ps

module tb_tl_cntr_w_left;	 //testbench of tl_cntr_w_left

	reg 				tb_clk, tb_reset_n, tb_Ta, tb_Tal, tb_Tb, tb_Tbl;		//reg clk, reset_n, Ta, Tal, Tb, Tbl
	wire	[1:0]		tb_La, tb_Lb;											//wire 2bit La, Lb
	
	tl_cntr_w_left U0_tl_cntr_w_left(.clk(tb_clk), .reset_n(tb_reset_n), .Ta(tb_Ta), .Tal(tb_Tal), 
												.Tb(tb_Tb), .Tbl(tb_Tbl), .La(tb_La[1:0]), .Lb(tb_Lb[1:0])); //instance of tl_cntr_w_left
	//load tl_cntr_w_left											

	always #5	tb_clk = ~tb_clk; //clk changes every 5 seconds
	
	initial
	begin																						//start test
	tb_clk = 1'b0; tb_reset_n = 1'b0; tb_Ta = 1'b0; tb_Tal = 1'b0; tb_Tb = 1'b0; tb_Tbl = 1'b0;
	#10;	tb_Ta = 1'b1; tb_Tb = 1'b1;
	#10;	tb_Tal = 1'b1;
	#10;	tb_Ta = 1'b0; tb_Tbl = 1'b1;
	#10;	tb_Tb = 1'b0;
	#10;	tb_Tbl = 1'b0;
	#10;	tb_reset_n = 1'b1;
	#10;	tb_Ta = 1'b1; tb_Tb = 1'b1;
	#10;	tb_Tal = 1'b1;
	#10;	tb_Ta = 1'b0; tb_Tbl = 1'b1;
	#10;	tb_Tb = 1'b0;
	#10;	tb_Tbl = 1'b0;
	#10;	tb_Ta = 1'b1; tb_Tb = 1'b1;
	#10;	tb_Tal = 1'b1; tb_Tbl = 1'b1;
	#10;	tb_Ta = 1'b0; tb_Tb = 1'b0;
	#10;	tb_Tal = 1'b0; tb_Tbl = 1'b0;
	#10;  tb_Tb = 1'b1;  tb_Tbl = 1'b1;
	#50;  tb_Tb = 1'b0;
	#50;	tb_Tbl = 1'b0;
	#50; 	tb_reset_n = 1'b0;
	#10;	$stop;
	end																							//end test
endmodule
