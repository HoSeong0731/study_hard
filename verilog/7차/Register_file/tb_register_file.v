`timescale 1ns/100ps

module tb_register_file;
	reg tb_clk,tb_reset_n,tb_we;		//input oclk, reset_n, we
	reg [2:0]tb_wAddr, tb_rAddr;		//input wAddr, rAddr
	reg [31:0]tb_wData;					//input wData
	wire [31:0]tb_rData;				//output 32bit rData
	
	Register_file U0(.clk(tb_clk),.reset_n(tb_reset_n),.wAddr(tb_wAddr),.wData(tb_wData),.we(tb_we),.rAddr(tb_rAddr),.rData(tb_rData));
	//load Register_file

	initial forever #10 tb_clk = ~tb_clk;
	initial
	begin																					//start test
		  tb_clk = 0; tb_reset_n = 0; tb_we = 0; tb_wAddr = 3'b000; tb_rAddr = 3'b000; tb_wData = 32'h0000_0000;
	#15; tb_reset_n = 1; tb_we = 1; tb_wData = 32'h1111_1111;
	#20; tb_wAddr = 3'b001; tb_wData = 32'hff00_ff00;
	#20; tb_wAddr = 3'b010; 
	#20; tb_wAddr = 3'b011; tb_wData = 32'h00ff_00ff;
	#10; tb_we = 0;
	#10; tb_rAddr = 3'b001;
	#10; tb_rAddr = 3'b010;
	#10; tb_rAddr = 3'b011;
	#10; tb_rAddr = 3'b101;
	#10; tb_rAddr = 3'b111;
	#10; $stop;
end																							//end test

endmodule