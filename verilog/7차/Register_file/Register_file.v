module Register_file(clk,reset_n,wAddr,wData,we,rAddr,rData);
	input clk,reset_n,we;		//input clk, reset_n, we
	input [2:0]wAddr, rAddr;	//input 3bit wAddr, rAddr
	input [31:0]wData;			//input 32bit wData
	output [31:0]rData;			//output 32bit rData
	
	wire[7:0]to_reg;			//wire 8bit to_reg
	wire[31:0]from_reg[7:0];	//wire 32bit from_reg 8bit (32bit register * 8)
	
	register32_8 U0_register32_8(.clk(clk),.reset_n(reset_n),.en(to_reg),.d_in(wData),.d_out0(from_reg[0]),.d_out1(from_reg[1]),.d_out2(from_reg[2]),.d_out3(from_reg[3]),.d_out4(from_reg[4]),.d_out5(from_reg[5]),.d_out6(from_reg[6]),.d_out7(from_reg[7]));
	//register32_8 instance

	write_operation U1(.Addr(wAddr),.we(we),.to_reg(to_reg));
	//instance write operation
	
	read_operation U2(.Addr(rAddr),.Data(rData),.from_reg0(from_reg[0]),.from_reg1(from_reg[1]),.from_reg2(from_reg[2]),.from_reg3(from_reg[3]),.from_reg4(from_reg[4]),.from_reg5(from_reg[5]),.from_reg6(from_reg[6]),.from_reg7(from_reg[7]));	
	//instance read_operation
endmodule
