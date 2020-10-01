`timescale 1ns/100ps
module tb_inv;
reg tb_a;
wire tb_y0, tb_y1;
//named mapping
_inv U0_inv(.a(tb_a), .y(tb_y0));
//ordered mapping
_inv U1_inv(tb_a, tb_y1);
initial begin
tb_a = 0;
#10; tb_a = 0;
#10; tb_a = 1;
#10; tb_a = 1;
#10;
end
endmodule
