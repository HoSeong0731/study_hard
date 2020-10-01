`timescale 1ns/100ps
module tb_XOR;
reg tb_a, tb_b;
wire tb_y0, tb_y1;
//named mapping
_XOR U0_XOR(.a(tb_a), .b(tb_b), .y(tb_y0));
//ordered mapping
_XOR U1_XOR(tb_a, tb_b, tb_y1);
initial begin
tb_a = 0; tb_b = 0;
#10; tb_a = 0; tb_b = 1;
#10; tb_a = 1; tb_b = 0;
#10; tb_a = 1; tb_b = 1;
#10;
end
endmodule
