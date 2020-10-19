`timescale 1ns/100ps
module tb_shifter8;	
	reg tb_clk, tb_reset_n; 		//reg clk, reset_n
	reg [2:0] tb_op;				//reg 3bit op
	reg [1:0] tb_shamt;				//reg 2bit shamt
	reg [7:0] tb_d_in;				//reg 8bit d_in
	wire [7:0] tb_d_out,tb_do_next; //wire d_out, do_next

	shifter8 test_shifter8(.clk(tb_clk),.reset_n(tb_reset_n),
							.op(tb_op),.shamt(tb_shamt),
							.d_in(tb_d_in),.d_out(tb_d_out)); 	//instance shifter8

	always	#	5 tb_clk = ~tb_clk; 							//making clock 
	
	initial
		begin																//start test
				  tb_clk=0; tb_op=0; tb_shamt=0; tb_d_in=0; tb_reset_n=0; 		
			#13;  tb_reset_n=1;
			#10;  tb_op=3'b001; tb_d_in=8'b01110111;
			#10; tb_op=3'b010;
			#10;
			#10; tb_shamt=2'b01;
			#10; #10;
			#10; tb_op=3'b011;
			#10; tb_op=3'b010; tb_shamt=2'b11; tb_d_in=01110111;
			#10; tb_op=3'b011; tb_d_in=8'b10000111;
			#10; #10;
			#10; tb_op=3'b100; tb_shamt=2'b01;
			#10; #10;
			#10; tb_shamt=2'b11;
			#10; #10;
			#10; tb_reset_n=0;
			#10;
			$stop;
		end																	//end test
		
endmodule
