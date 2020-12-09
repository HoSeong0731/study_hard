`timescale 1ns/100ps
module tb_ALU;					//module tb_alu4
reg [31:0] tb_a, tb_b;			//4bit reg tb_a, tb_b
reg [3:0] tb_op;					//3bit reg tb_op
wire [31:0] tb_result;			//4bit tb_result
ALU U0_alu32(.a(tb_a), .b(tb_b), .op(tb_op), .ALU_result(tb_result));

initial begin
tb_a = 4'b0000; tb_b = 4'b0000; tb_op = 4'b0000; #1;					//NOP = 32'b0
#9; tb_a = 4'b11111111111111111111111111111100; #1;					//NOT exchange
#9; tb_a = 4'b0000000000000000000000000011; tb_op = 4'b0001;	#1;//NOT A = 11111...1100
#9; tb_a = 4'b0101; tb_b = 4'b1001; tb_op = 4'b0010; #1;				//A AND B = 0001
#9; tb_a = 4'b0101; tb_b = 4'b1010; tb_op = 4'b0011; #1;				//A OR B = 1111
#9; tb_a = 4'b0011; tb_b = 4'b0101; tb_op = 4'b0100; #1;				//A XOR B = 0110
#9; tb_op = 3'b101; #1;															//A XNOR B = 1001
#9; tb_a = 4'b0000; tb_b = 4'b0000; tb_op = 4'b0110; #1;				//A ADD B = 0000
#9; tb_a = 4'hffffffff; tb_b = 4'hf; #1;									//A ADD B =	
#9; tb_a = 4'ha; tb_b = 4'h3; #1;											//A ADD B = 
#9; tb_a = 4'b0001; tb_b = 4'b1000; #1;									//A ADD B =
#9; tb_a = 4'h7; tb_b = 4'h7; #1;											//A ADD B =
#9; tb_a = 4'h3; tb_b = 4'h3; #1;											//A ADD B =
#9; tb_a = 4'hf; tb_b = 4'h5; tb_op = 4'b0111; #1;						//A SUB B =
#9; tb_a = 4'h5; tb_b = 4'h7; #1;											//A SUB B = 						
#9; tb_a = 4'ha; tb_b = 4'ha; #1;											//A SUB B =
#9; tb_a = 4'h7; tb_b = 4'h9; #1;											//A SUB B =

#9; 

$stop;
end
endmodule