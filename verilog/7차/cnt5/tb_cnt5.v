`timescale 1ns/100ps
module tb_cnt5;
   reg  tb_clk,tb_reset_n, tb_inc; 		//reg clk, reset_n, inc
	wire [2:0] tb_cnt;					//wire 3bit cnt
	
	cnt5 U0_cnt5(.cnt(tb_cnt),.clk(tb_clk), 
					.reset_n(tb_reset_n),.inc(tb_inc));//instance cnt5
	//load cnt5

	parameter STEP=10; 				//parameter #10
	
	always # STEP tb_clk = ~tb_clk;
	
	//start test
	initial
		begin
					 tb_clk=0; tb_reset_n=1; tb_inc=0;
			#STEP; tb_reset_n=0;
			#STEP; tb_reset_n=1;	tb_inc=1;
			#STEP; tb_inc=1; 
			#STEP; tb_inc=0;
			#STEP; tb_inc=1;
			#STEP; tb_inc=0;
			#STEP; tb_inc=1;
			#STEP; tb_inc=1;
			#STEP; tb_inc=0; 
			#STEP; tb_inc=0;
			#STEP; tb_inc=1;
			#STEP; tb_reset_n=0;
			#(STEP*2); $stop; //do the cases.
	end
		//end test
endmodule
