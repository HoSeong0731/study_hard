module read_operation(Addr,Data,from_reg0,from_reg1,from_reg2,
					from_reg3,from_reg4,from_reg5,from_reg6,from_reg7);
	input [31:0] from_reg0,from_reg1,from_reg2,from_reg3,from_reg4,from_reg5,from_reg6,from_reg7;
	//input 32bit reg0 ~ reg7 
	input [2:0] Addr;		//input 3bit Addr
	output [31:0] Data;		//output 32bit Data
	
	_8_to_1_MUX U0(.a(from_reg0),.b(from_reg1),.c(from_reg2),.d(from_reg3),.e(from_reg4),.f(from_reg5),.g(from_reg6),.h(from_reg7),.sel(Addr),.d_out(Data));
	//instance multiplexer
endmodule