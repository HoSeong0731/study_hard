
`timescale 1ns/100ps //testbench of tl_cntr_w_left

module tb_tl_cntr_w_left;

	reg 				tb_clk, tb_reset_n, tb_Ta, tb_Tal, tb_Tb, tb_Tbl;
	wire	[1:0]		tb_La, tb_Lb;
	
	tl_cntr_w_left U0_tl_cntr_w_left(.clk(tb_clk), .reset_n(tb_reset_n), .Ta(tb_Ta), .Tal(tb_Tal), 
												.Tb(tb_Tb), .Tbl(tb_Tbl), .La(tb_La[1:0]), .Lb(tb_Lb[1:0])); //instance of tl_cntr_w_left
												
	always #5	tb_clk = ~tb_clk; //clk changes every 5 seconds
	
	initial
	begin
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
	end
endmodule


/*
`timescale 1ns/100ps

module tb_tl_cntr_w_left; // Making tb_tl_cntr_w_left module for testing 
   reg tb_clk, tb_reset_n; // Declares reg tb_clk, tb_reset_n
   reg tb_Ta, tb_Tal, tb_Tb, tb_Tbl; // Declares reg tb_Ta, tb_Tal, tb_Tb, tb_Tbl
   
   wire [1:0] tb_La, tb_Lb; // Declares 2-bit wire tb_La, tb_Lb
   
   // ordered mapping
   tl_cntr_w_left U0_tl_cntr_w_left(tb_clk, tb_reset_n, tb_Ta, tb_Tal, tb_Tb, tb_Tbl, tb_La, tb_Lb);
   
   initial forever #10 tb_clk = ~tb_clk; // repeat always
   
   initial begin // Execute internal action only once
   #0;  tb_clk = 0; tb_reset_n = 0; tb_Ta = 1; tb_Tb = 0; tb_Tal = 0; tb_Tbl = 0; // Allocated 0 to tb_clk, tb_reset_n, tb_Ta, tb_Tb, tb_Tal and tb_Tbl
   #5; tb_reset_n = 1; // Simulate as much as 5 time unit, Allocated 1 to tb_reset_n
   #10; tb_Ta = 0; // Simulate as much as 10 time unit, Allocated 0 to tb_Ta
   #10; tb_Tal = 0; // Simulate as much as 10 time unit, Allocated 0 to tb_Tal
   #10; tb_Ta = 1; tb_Tal = 1; // Simulate as much as 10 time unit, Allocated 1 to tb_Ta, tb_Tal
   #20; tb_Ta = 0; // Simulate as much as 20 time unit, Allocated 0 to tb_Ta
   #20; tb_Tal = 0; // Simulate as much as 20 time unit, Allocated 0 to tb_Tal
   #20; tb_Tb = 1;  tb_Tbl = 1; // Simulate as much as 20 time unit, Allocated 1 to tb_Tb, tb_Tbl
	
   #20; tb_Tb = 0; // Simulate as much as 20 time unit, Allocated 0 to tb_Tb
   #60; tb_Tbl = 0; //Simulate as much as 60 time unit, Allocated 0 to tb_Tbl
   #90; tb_reset_n = 0; // Simulate as much as 90 time unit, Allocated 0 to tb_reset_n
   end // End of execute internal action
endmodule // finished module
*/