`timescale 1ns/100ps

module tb_register32;

	reg 				tb_clk;
	reg	[31:0]	tb_d;
	wire	[31:0]	tb_q;
	
	_register32 U0_register32(.clk(tb_clk), .d(tb_d), .q(tb_q));
	
	always #25 tb_clk = ~tb_clk;
	
	initial
	begin
		tb_clk = 32'h0; tb_d = 32'h12345678;
		#15; tb_d = 32'h98765432;
		#15; tb_d = 32'hffeeddcc;
		#30; tb_d = 32'hbbaa9988;
		#10; tb_d = 32'h77665544;
		#20; tb_d = 32'h33221100;
		#20; tb_d = 32'h12345678;
		#40; $stop;
	end
endmodule
