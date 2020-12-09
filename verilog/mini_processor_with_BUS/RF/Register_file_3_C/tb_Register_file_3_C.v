`timescale 1ns/100ps

module tb_Register_file_3_C;
	reg tb_clk,tb_reset_n,tb_we;		//input oclk, reset_n, we
	reg [15:0]tb_S_addr, tb_r_addr;		//input wAddr, rAddr
	reg [63:0]tb_wData;					//input wData
	wire [63:0]tb_rData;				//output 32bit rData
	
	Register_file_3_C U0(.clk(tb_clk), .reset_n(tb_reset_n), .W_addr(tb_S_addr), .R_addr(tb_r_addr),.wData(tb_wData), .we(tb_we), .rData(tb_rData));
	//load Register_file

	initial forever #10 tb_clk = ~tb_clk;
	initial
	begin																					//start test
		  tb_clk = 0; tb_reset_n = 0; tb_we = 0; tb_S_addr = 16'h0120; tb_r_addr = 16'h0120;  tb_wData = 64'hffff_ffff_0000_0000;
	#15; tb_reset_n = 1; tb_we = 1; tb_wData = 64'h1111_1111;
	#20; tb_S_addr = 16'h0120; tb_wData = 64'hffff_ffff_ff00_ff00;
	#20; tb_S_addr = 16'h0121; 
	#20; tb_S_addr = 16'h0122; tb_wData = 64'hffff_ffff_00ff_00ff;
	#20; tb_S_addr = 16'h0123;
	#10; tb_we = 0;
	#10; tb_r_addr = 16'h0120;
	#10; tb_r_addr = 16'h0121;
	#10; tb_r_addr = 16'h0122;
	#10; tb_r_addr = 16'h0123;
	#10; $stop;
end																							//end test

endmodule