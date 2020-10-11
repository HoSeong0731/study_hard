`timescale 1ns/100ps
module tb_alu32;					//module tb_alu4
reg [31:0] tb_a, tb_b;			//4bit reg tb_a, tb_b
reg [2:0] tb_op;					//3bit reg tb_op
wire [31:0] tb_result;			//4bit tb_result
wire tb_c, tb_n, tb_z, tb_v;	//wire tb_c, tb_z, tb_v
alu32 U0_alu32(.a(tb_a), .b(tb_b), .op(tb_op), .result(tb_result), .c(tb_c), .n(tb_n), .z(tb_z), .v(tb_v));

initial begin
tb_a = 4'b0000; tb_b = 4'b0000; tb_op = 3'b000; #1;				//NOT A = 1111
if(tb_result !== 4'hffffffff) $display("result is error(NOT A)");	//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 1) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'b11111111111111111111111111111100; #1;													//NOT A = 0011		
if(tb_result !== 4'b00000000000000000000000000000011) $display("result is error(NOT A)");	//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 0) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_b = 4'b0000000000000000000000000011; tb_op = 3'b001;	#1;								//NOT B = 1100
if(tb_result !== 4'b11111111111111111111111111111100) $display("result is error(NOT B)");	//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 1) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'b0101; tb_b = 4'b1001; tb_op = 3'b010; #1;			//A AND B = 0001
if(tb_result !== 4'b0001) $display("result is error(AND)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 0) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'b0101; tb_b = 4'b1010; tb_op = 3'b011; #1;			//A OR B = 1111
if(tb_result !== 4'b1111) $display("result is error(OR)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 1) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'b0011; tb_b = 4'b0101; tb_op = 3'b100; #1;			//A XOR V = 0110
if(tb_result !== 4'b0110) $display("result is error(XOR)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 0) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_op = 3'b101; #1;													//A XNOR B = 1001
if(tb_result !== 4'b11111111111111111111111111111001) $display("result is error(XNOR)");	//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 1) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'b0000; tb_b = 4'b0000; tb_op = 3'b110; #1;			//A ADD B = 0000
if(tb_result !== 4'b0000) $display("result is error(ADD)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 0) $display("negative is error");						//negative error check
if(tb_z !== 1) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'hffffffff; tb_b = 4'hf; #1;										//A ADD B = 11110		
if(tb_result !== 4'b1110) $display("result is error(ADD)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 0) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'ha; tb_b = 4'h3; #1;										//A ADD B = 1101
if(tb_result !== 4'b1101) $display("result is error(ADD)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 0) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'b0001; tb_b = 4'b1000; #1;								//A ADD B = 1001
if(tb_result !== 4'b1001) $display("result is error(ADD)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 0) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'h7; tb_b = 4'h7; #1;										//A ADD B = 11110(over flow)
if(tb_result !== 4'b1110) $display("result is error(ADD)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 0) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'h3; tb_b = 4'h3; #1;										//A ADD B = 0110
if(tb_result !== 4'b0110) $display("result is error(ADD)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 0) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'hf; tb_b = 4'h5; tb_op = 3'b111; #1;					//A SUB B = 1010
if(tb_result !== 4'b11111111111111111111111100001010) $display("result is error(SUB)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 1) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'h5; tb_b = 4'h7; #1;										//A SUB B = 1110
if(tb_result !== 4'b11111111111111111111111111111110) $display("result is error(SUB)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 1) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 0) $display("overflow is error");						//overflow error

#9; tb_a = 4'ha; tb_b = 4'ha; #1;										//A SUB B = 0000(over flow)
if(tb_result !== 4'b0000) $display("result is error(SUB)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 0) $display("negative is error");						//negative error check
if(tb_z !== 1) $display("zero is error");								//zero error
if(tb_v !== 1) $display("overflow is error");						//overflow error

#9; tb_a = 4'h7; tb_b = 4'h9; #1;										//A SUB B = 1110(over flow)
if(tb_result !== 4'b1110) $display("result is error(SUB)");		//result error check
if(tb_c !== 0) $display("carry is error");							//carry error check
if(tb_n !== 1) $display("negative is error");						//negative error check
if(tb_z !== 0) $display("zero is error");								//zero error
if(tb_v !== 1) $display("overflow is error");						//overflow error

#9; 

$stop;
end
endmodule