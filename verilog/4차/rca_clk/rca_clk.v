module rca_clk(clock, a, b, ci, s_rca, co_rca);  //make a rca_clk by flip-flop
	input clock; 					//use clock for flip-flop
	input [31:0] a, b; 			//Declare inputs
	input ci;
	output [31:0] s_rca; 		//Declare outputs
	output co_rca;

	reg [31:0] reg_a, reg_b; 	//Declare regs
	reg reg_ci;
	reg [31:0] reg_s_rca;
	reg reg_co_rca;
	
	wire [31:0] wire_s_rca; 	//Declare wires
	wire wire_co_rca;

	always @ (posedge clock) 	//repeat the function when rising clock
	begin //start content
		reg_a <= a;
		reg_b <= b;
		reg_ci <= ci;
		reg_s_rca <= wire_s_rca;
		reg_co_rca <= wire_co_rca;
	end //end of content

	rca32 U0_rca32(.a(reg_a), .b(reg_b), .ci(reg_ci), .s(wire_s_rca), .co(wire_co_rca));

	assign s_rca = reg_s_rca;
	assign co_rca = reg_co_rca;

endmodule //end module
