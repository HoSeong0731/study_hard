`timescale 1ns/100ps

module tb_Register_file_10_I;
	reg tb_clk,tb_reset_n,tb_we;		//input oclk, reset_n, we
	reg [15:0]tb_S_addr, tb_R_addr ;		//input wAddr, rAddr
	reg [63:0]tb_wData;					//input wData
	wire [63:0]tb_rData;				//output 32bit rData
	
	Register_file_10_I U0(.clk(tb_clk), .reset_n(tb_reset_n), .W_addr(tb_S_addr),.wData(tb_wData), .we(tb_we), .R_addr(tb_R_addr),.rData(tb_rData));
	//load Register_file

	initial forever #10 tb_clk = ~tb_clk;
	initial
	begin																					//start test
		  tb_clk = 0; tb_reset_n = 0; tb_we = 0; tb_S_addr = 16'h0120;  tb_wData = 64'hffff_ffff_0000_0000;
	#15; tb_reset_n = 1; tb_we = 1; tb_wData = 64'h1111_1111;
	#20; tb_S_addr = 16'h0110; tb_wData = 64'hffff_ffff_ff00_ff00;
	#20; tb_S_addr = 16'h0111; tb_wData = 64'hffff_ffff_ff00_ff01;
	#20; tb_S_addr = 16'h0112; tb_wData = 64'hffff_ffff_00ff_00ff;	
	#20; tb_S_addr = 16'h0113; tb_wData = 64'hffff_ffff_ff00_ff02;
	#20; tb_S_addr = 16'h0114; tb_wData = 64'hffff_ffff_ff00_ff03;
	#20; tb_S_addr = 16'h0115; tb_wData = 64'hffff_ffff_ff00_ff04;
	#20; tb_S_addr = 16'h0116; tb_wData = 64'hffff_ffff_ff00_ff05;
	#20; tb_S_addr = 16'h0117; tb_wData = 64'hffff_ffff_ff00_ff06;
	#20; tb_S_addr = 16'h0118; tb_wData = 64'hffff_ffff_ff00_ff07;
	#20; tb_S_addr = 16'h0119; tb_wData = 64'hffff_ffff_ff00_ff08;
	#20; tb_S_addr = 16'h011a; tb_wData = 64'hffff_ffff_ff00_ff09;
	#20; tb_S_addr = 16'h011b; tb_wData = 64'hffff_ffff_ff00_ff0a;
	
	#10; tb_we = 0;
	#10; tb_R_addr = 16'h0110;
	#10; tb_R_addr = 16'h0111;
	#10; tb_R_addr = 16'h0112;
	#10; tb_R_addr = 16'h0113;
	#10; tb_R_addr = 16'h0114;
	#10; tb_R_addr = 16'h0115;
	#10; tb_R_addr = 16'h0116;
	#10; tb_R_addr = 16'h0117;
	#10; tb_R_addr = 16'h0118;
	#10; tb_R_addr = 16'h0119;
	#10; tb_R_addr = 16'h011a;
	#10; tb_R_addr = 16'h011b;
	#10; $stop;
end																							//end test

endmodule
