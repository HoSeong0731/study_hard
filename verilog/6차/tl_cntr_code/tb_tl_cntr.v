`timescale 1ns/100ps //testbench of tl_cntr
module tb_tl_cntr;

	reg					tb_clk, tb_reset_n, tb_Ta, tb_Tb;	//reg clk, reset_n, tb_Ta, tb_Tb
	wire		[1:0]		tb_La, tb_Lb;					//wire tb_La, tb_Lb
	
	tl_cntr U0_tl_cntr(.clk(tb_clk), .reset_n(tb_reset_n), .Ta(tb_Ta), .Tb(tb_Tb), 
								.La(tb_La), .Lb(tb_Lb)); //instance of tl_cntr
	// load tl_cntr

	always #5	tb_clk = ~tb_clk; //clock changes its value every 5 seconds
	
	initial //initialize
	begin																//start test
		tb_clk = 1'b0; tb_reset_n = 1'b0; tb_Ta = 1'b0; tb_Tb = 1'b0;
		#10;	tb_Ta = 1'b1;
		#10;	tb_Tb = 1'b1;
		#10;	tb_Ta = 1'b0;
		#10;	tb_reset_n = 1'b1;
		#10;	tb_Tb = 1'b0;
		#10;	tb_Ta = 1'b1;
		#10;	tb_Tb = 1'b1;
		#10;	tb_Ta = 1'b0;
		#10;	tb_Ta = 1'b1;
		#10;	tb_Tb = 1'b0;
		#10;	$stop; //stop testbench
	end																	//end test
endmodule
