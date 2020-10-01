`timescale 1ns/100ps //test bench for cla_clk

module tb_rca_clk; //Declare name of module
	reg clock;
	reg [31:0] tb_a, tb_b; //Declare regs
	reg tb_ci;
	wire [31:0] tb_s_rca; //Declare wires
	wire tb_co_rca;

	parameter STEP = 10; //initial for clock

	rca_clk U0_rca_clk(.clock(clock), .a(tb_a), .b(tb_b), .ci(tb_ci),
								.s_rca(tb_s_rca), .co_rca(tb_co_rca)); //instance

	always#(STEP/2) clock = ~clock; //clock 0 5 and 1 5

	initial
	begin //start content
			clock=1; //clock setting
			tb_a=32'h00000000; tb_b=32'h00000000; tb_ci=0; //put the 32bit number in the test bench variable
	#STEP	tb_a=32'hffffffff;
	#STEP	tb_a=32'h0000ffff; tb_b=32'hffff0000;
	#STEP	tb_a=32'h123fa562; tb_b=32'h35614642;
	#STEP	tb_a=32'h123fa562; tb_b=32'h35614642;
	#STEP	$stop;
	end //end of content

endmodule //Declare end of moudle
