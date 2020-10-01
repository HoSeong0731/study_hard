`timescale 1ns/100ps						//test bench for cla_clk
module tb_cla4;							//make module of testbench
reg [3:0] tb_a, tb_b;					//Declare regs
reg tb_ci;									//reg carry in
wire [3:0] tb_s;							//Declare wire
wire tb_co;									//wire carry out of testbench
wire [4:0] tb_result;					//wire result of testbench 
assign tb_result = {tb_co, tb_s};	//y = {tb_co, tb_s}

cla4 U0_cla4(.a(tb_a), .b(tb_b), .ci(tb_ci), .s(tb_s), .co(tb_co));	//load cla4 module

initial
begin
tb_a = 0; tb_b = 0; tb_ci = 0;
#10; tb_a = 4'h3; tb_b = 4'h5; tb_ci = 0;	//put the 4bit number in the test bench variable
#10; tb_a = 4'h7; tb_b = 4'h9; tb_ci = 0;	//4'h3 => size = 4-bit, hexamode, number 3
#10; tb_a = 4'h5; tb_b = 4'h5; tb_ci = 1;	//4'hf => size = 4-bit, hexamode, number 15
#10; tb_a = 4'h8; tb_b = 4'h7; tb_ci = 1;
#10; tb_a = 4'hf; tb_b = 4'hf; tb_ci = 0;
#10; tb_a = 4'hf; tb_b = 4'hf; tb_ci = 1;
#10; $stop;
end
endmodule		//end module
