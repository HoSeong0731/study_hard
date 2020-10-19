`timescale 1ns/100ps
module tb_cntr8;	
	reg tb_clk, tb_reset_n, tb_inc, tb_load; 
	reg  [7:0] tb_d_in;			//8bit d_in
	wire [7:0] tb_d_out;		//8bit d_out
	wire [2:0] tb_o_state;		//3bit o_state
	
	cntr8 test_cntr8(.clk(tb_clk),.reset_n(tb_reset_n),
						.inc(tb_inc),.load(tb_load),.d_in(tb_d_in),
						.d_out(tb_d_out),.o_state(tb_o_state)); //instance cntr8
	
	always #5 tb_clk = ~tb_clk;
	//starting the test
	initial
		begin																//start test
				  tb_clk=1; tb_load=0; tb_inc=0; tb_d_in=0; tb_reset_n=0;
			#10; tb_inc=1; tb_reset_n=1;	
			#10; tb_inc=1;
			#10; tb_inc=1;
			#10; tb_inc=1;
			#10; tb_inc=1;
			#10; tb_inc=0;
			#10; tb_inc=0;
			#10; tb_inc=0;
			#10; tb_inc=0;
			#10; tb_inc=0;
			#10; tb_reset_n=1; tb_inc=0; tb_load=1; tb_d_in=44;
			#10; tb_inc=1; tb_load=0;
			#10; tb_inc=1;
			#10; tb_inc=1;
			#10; tb_reset_n=0; tb_inc=0;
			#10; tb_reset_n=1;
			#10; tb_inc=0;
			#10; tb_inc=0;
			#10; tb_inc=0;
			#10; tb_inc=0;
			#10;  $stop;
		end																	//end test
		
endmodule