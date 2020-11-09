`timescale 1ns/100ps
module tb_multiplier;
	
	reg clk, reset_n;								// tb input & output List
	reg [63:0] multiplier,multiplicand;
	reg op_start,op_clear;
	wire op_done ;
	wire [127:0] result;


														//multiplier insatnce
 multiplier U0(.clk(clk),.reset_n(reset_n),.multiplier(multiplier),.multiplicand(multiplicand),
						.op_start(op_start),.op_clear(op_clear),.op_done(op_done),.result(result));
						
						
parameter STEP = 10;								//step is 10

initial forever #(STEP/2) clk = ~clk;		//clk is 5
initial
begin													//Set Initial Value
clk = 0; reset_n = 0; op_start = 0; op_clear = 0; multiplier = ~(64'b10011) + 64'b1; multiplicand = ~(64'b10011) + 64'b1; 
#STEP reset_n = 1; op_start = 1;  			//opstart1 => Calculation start
#1000
//#300
//#STEP op_clear = 1; op_start = 0; 		//Clearing #1000 and clearing this annotation will stop the operation and move it to the idle state.
//#STEP op_clear = 0;
//#200
$stop;
end
endmodule

	
	