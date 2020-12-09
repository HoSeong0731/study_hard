`timescale 1ns/100ps

module tb_Register_file_10_D;
	reg tb_clk,tb_reset_n,tb_we;		//input oclk, reset_n, we
	reg [15:0]tb_S_addr, tb_r_addr, tb_r_addr2;		//input wAddr, rAddr
	reg [63:0]tb_wData;					//input wData
	wire [63:0]tb_rData, tb_rData2;				//output 32bit rData
	
	Register_file_10_D U0(.clk(tb_clk), .reset_n(tb_reset_n), .W_addr(tb_S_addr),.wData(tb_wData), .we(tb_we), .R_addr2(tb_r_addr),.R_addr3(tb_r_addr2),.rData(tb_rData), .rData2(tb_rData2));
	//load Register_file

	initial forever #10 tb_clk = ~tb_clk;
	initial
	begin																					//start test
		  tb_clk = 0; tb_reset_n = 0; tb_we = 0; tb_S_addr = 16'h0120; tb_r_addr = 16'h0120;  tb_wData = 64'hffff_ffff_0000_0000; tb_r_addr2 = 16'h0120;
	#15; tb_reset_n = 1; tb_we = 1; tb_wData = 64'h1111_1111;
	#20; tb_S_addr = 16'h0100; tb_wData = 64'hffff_ffff_ff00_ff00;
	#20; tb_S_addr = 16'h0101; tb_wData = 64'hffff_ffff_ff00_ff01;
	#20; tb_S_addr = 16'h0102; tb_wData = 64'hffff_ffff_00ff_00ff;	
	#20; tb_S_addr = 16'h0103; tb_wData = 64'hffff_ffff_ff00_ff02;
	#20; tb_S_addr = 16'h0104; tb_wData = 64'hffff_ffff_ff00_ff03;
	#20; tb_S_addr = 16'h0105; tb_wData = 64'hffff_ffff_ff00_ff04;
	#20; tb_S_addr = 16'h0106; tb_wData = 64'hffff_ffff_ff00_ff05;
	#20; tb_S_addr = 16'h0107; tb_wData = 64'hffff_ffff_ff00_ff06;
	#20; tb_S_addr = 16'h0108; tb_wData = 64'hffff_ffff_ff00_ff07;
	#20; tb_S_addr = 16'h0109; tb_wData = 64'hffff_ffff_ff00_ff08;
	#20; tb_S_addr = 16'h010a; tb_wData = 64'hffff_ffff_ff00_ff09;
	#20; tb_S_addr = 16'h010b; tb_wData = 64'hffff_ffff_ff00_ff0a;
	
	#10; tb_we = 0;
	#10; tb_r_addr = 16'h0100;tb_r_addr2 = 16'h0101;
	#10; tb_r_addr = 16'h0101;tb_r_addr2 = 16'h0102;
	#10; tb_r_addr = 16'h0102;tb_r_addr2 = 16'h0103;
	#10; tb_r_addr = 16'h0103;tb_r_addr2 = 16'h0104;
	#10; tb_r_addr = 16'h0104;tb_r_addr2 = 16'h0105;
	#10; tb_r_addr = 16'h0105;tb_r_addr2 = 16'h0106;
	#10; tb_r_addr = 16'h0106;tb_r_addr2 = 16'h0107;
	#10; tb_r_addr = 16'h0107;tb_r_addr2 = 16'h0108;
	#10; tb_r_addr = 16'h0108;tb_r_addr2 = 16'h0109;
	#10; tb_r_addr = 16'h0109;tb_r_addr2 = 16'h010a;
	#10; tb_r_addr = 16'h010a;tb_r_addr2 = 16'h010b;
	#10; tb_r_addr = 16'h010b;tb_r_addr2 = 16'h010c;
	#10; $stop;
end																							//end test

endmodule
