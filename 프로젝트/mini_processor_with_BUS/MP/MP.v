module MP(Clk, Reset_n, S_wr, S_addr, S_din, s0_sel, s_dout, Interrupt_out);

	input Clk, Reset_n, S_wr, s0_sel;
	input [15:0] S_addr;
	input [31:0] S_din;
	output [63:0] s_dout;
	output Interrupt_out;
	
	//Register_file_23 U1_RF(.clk(CLK),.reset_n(Reset_n),.wAddr(S_addr),.wData(s_dout),.we(),.rAddr(),.rData());
	Register_file_10_D U1_DATA_REG(.clk(Clk), .reset_n(Reset_n), .S_addr(S_addr), .wData(), .we(S_wr), .rData());
	
	Register_file_10_I U2_INST_REG(.clk(Clk), .reset_n(Reset_n), .S_addr(S_addr), .wData(), .we(S_wr), .rData());
	
	Register_file_3 U3_CONT_REG(.clk(Clk), .reset_n(Reset_n), .S_addr(S_addr), .wData(), .we(S_wr), .rData());
	
	ALU U4_ALU(.a(), .b(), .op(), .ALU_result(), .c(), .n(), .z(), .v());
	
	MUL U5_MUL(.clk(Clk),.reset_n(Reset_n),.multiplier(),.multiplicand(),.op_start(),.op_clear(),.op_done(),.MUL_result());
	
	mx2_32bits U6_result(.d0(ALU_result), .d1(MUL_result), .s(S_addr[0]), .y(s_dout));
	
endmodule

