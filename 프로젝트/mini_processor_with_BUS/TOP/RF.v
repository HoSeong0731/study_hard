
//--------------------------------------------make_Register_file Data_REG--------------------------------------
module Register_file_10_D(clk, reset_n, W_addr, R_addr2, R_addr3, wData, we, rData, rData2);
	input clk, reset_n, we;
	input [15:0]W_addr, R_addr2, R_addr3;
	input [63:0] wData;
	output [63:0] rData, rData2;
	
	wire [9:0] to_reg;
	wire [63:0] from_reg[9:0];
	
	register64_10 U0_register64_10(.clk(clk),.reset_n(reset_n),.en(to_reg),.d_in(wData),.d_out0(from_reg[0]),.d_out1(from_reg[1]),.d_out2(from_reg[2]),.d_out3(from_reg[3]),.d_out4(from_reg[4]),.d_out5(from_reg[5]),.d_out6(from_reg[6]),.d_out7(from_reg[7]),.d_out8(from_reg[8]),.d_out9(from_reg[9]));
	
	write_operation_10_D U1_write_operation(.clk(clk), .reset_n(reset_n),.Addr(W_addr),.we(we),.to_reg(to_reg));
	
	read_operation_10_D U2_read_operation1(.Addr(R_addr2),.Data(rData),.from_reg0(from_reg[0]),.from_reg1(from_reg[1]),.from_reg2(from_reg[2]),.from_reg3(from_reg[3]),.from_reg4(from_reg[4]),.from_reg5(from_reg[5]),.from_reg6(from_reg[6]),.from_reg7(from_reg[7]),.from_reg8(from_reg[8]),.from_reg9(from_reg[9]));
	
	read_operation_10_D U3_read_operation2(.Addr(R_addr3),.Data(rData2),.from_reg0(from_reg[0]),.from_reg1(from_reg[1]),.from_reg2(from_reg[2]),.from_reg3(from_reg[3]),.from_reg4(from_reg[4]),.from_reg5(from_reg[5]),.from_reg6(from_reg[6]),.from_reg7(from_reg[7]),.from_reg8(from_reg[8]),.from_reg9(from_reg[9]));
	
endmodule

module _16_to_10_decoder_D(d, q);
	input [15:0]d;				//input 16bit d
	output reg [9:0]q;		//output reg 10bit q
	
	always@(d) begin
		case(d)							
			16'b0000_0001_0000_0000 : q = 10'b00_0000_0001;//DATA_REG
			16'b0000_0001_0000_0001 : q = 10'b00_0000_0010;
			16'b0000_0001_0000_0010 : q = 10'b00_0000_0100;
			16'b0000_0001_0000_0011 : q = 10'b00_0000_1000;
			16'b0000_0001_0000_0100 : q = 10'b00_0001_0000;
			16'b0000_0001_0000_0101 : q = 10'b00_0010_0000;
			16'b0000_0001_0000_0110 : q = 10'b00_0100_0000;
			16'b0000_0001_0000_0111 : q = 10'b00_1000_0000;
			16'b0000_0001_0000_1000 : q = 10'b01_0000_0000;
			16'b0000_0001_0000_1001 : q = 10'b10_0000_0000;
			default : q = 10'hx;
		endcase
	end
endmodule

module write_operation_10_D(clk, reset_n, Addr, to_reg, we);
	input we, clk, reset_n;				//input we
	input [15:0]Addr;		//input 4bit Addr	
	output [9:0]to_reg;	//output 10bit to_reg
	
	wire[9:0] write_wire;	//wire
	
	_16_to_10_decoder_D U0(.d(Addr),.q(write_wire));	//instance 16 to 10
	_and2 U1(.a(write_wire[0]),.b(we),.y(to_reg[0]));	//intstance and gate
	_and2 U2(.a(write_wire[1]),.b(we),.y(to_reg[1]));	//and gate instance
	_and2 U3(.a(write_wire[2]),.b(we),.y(to_reg[2]));
	_and2 U4(.a(write_wire[3]),.b(we),.y(to_reg[3]));
	_and2 U5(.a(write_wire[4]),.b(we),.y(to_reg[4]));
	_and2 U6(.a(write_wire[5]),.b(we),.y(to_reg[5]));
	_and2 U7(.a(write_wire[6]),.b(we),.y(to_reg[6]));
	_and2 U8(.a(write_wire[7]),.b(we),.y(to_reg[7]));
	_and2 U9(.a(write_wire[8]),.b(we),.y(to_reg[8]));
	_and2 U10(.a(write_wire[9]),.b(we),.y(to_reg[9]));	//---DATA_REG---
	
endmodule

module _10_to_1_MUX_D(a,b,c,d,e,f,g,h,i,j,sel,d_out);
	input [63:0]a,b,c,d,e,f,g,h,i,j;		//input 64bit a~w
	input [15:0]sel;							//input 16bit sel
	output reg[63:0]d_out;					//output reg 64bit d_out
	
	always@(sel,a,b,c,d,e,f,g,h,i,j)		//select
	begin
		case(sel) //choose one.
			16'b0000_0001_0000_0000 : d_out = a;
			16'b0000_0001_0000_0001 : d_out = b;
			16'b0000_0001_0000_0010 : d_out = c;
			16'b0000_0001_0000_0011 : d_out = d;
			16'b0000_0001_0000_0100 : d_out = e;
			16'b0000_0001_0000_0101 : d_out = f;
			16'b0000_0001_0000_0110 : d_out = g;
			16'b0000_0001_0000_0111 : d_out = h;
			16'b0000_0001_0000_1000 : d_out = i;
			16'b0000_0001_0000_1001 : d_out = j;
			default : d_out = 64'hx;
		endcase
	end
endmodule

module read_operation_10_D(Addr,Data,from_reg0,from_reg1,from_reg2,from_reg3,from_reg4,from_reg5,from_reg6,from_reg7,from_reg8,from_reg9);
	input [63:0] from_reg0,from_reg1,from_reg2,from_reg3,from_reg4,from_reg5,from_reg6,from_reg7,from_reg8,from_reg9;
									//input 64bit reg0 ~ reg9
	input [15:0] Addr;		//input 16bit Addr
	output [63:0] Data;		//output 64bit Data
	
	_10_to_1_MUX_D U0(.a(from_reg0),.b(from_reg1),.c(from_reg2),.d(from_reg3),.e(from_reg4),.f(from_reg5),.g(from_reg6),.h(from_reg7),.i(from_reg8),.j(from_reg9),.sel(Addr),.d_out(Data));
endmodule


//--------------------------------------------make_Register_file INST_REG--------------------------------------
module Register_file_10_I(clk, reset_n, W_addr,  wData, we, R_addr, rData);
	input clk, reset_n, we;
	input [15:0]W_addr, R_addr;
	input [63:0] wData;
	output [63:0] rData;
	
	wire [9:0] to_reg;
	wire [63:0] from_reg[9:0];
	
	register64_10 U0_register64_10(.clk(clk),.reset_n(reset_n),.en(to_reg),.d_in(wData),.d_out0(from_reg[0]),.d_out1(from_reg[1]),.d_out2(from_reg[2]),.d_out3(from_reg[3]),.d_out4(from_reg[4]),.d_out5(from_reg[5]),.d_out6(from_reg[6]),.d_out7(from_reg[7]),.d_out8(from_reg[8]),.d_out9(from_reg[9]));
	
	write_operation_10_I U1_write_operation(.clk(clk), .reset_n(reset_n),.Addr(W_addr),.we(we),.to_reg(to_reg));
	
	read_operation_10_I U2_read_operation(.Addr(R_addr),.Data(rData),.from_reg0(from_reg[0]),.from_reg1(from_reg[1]),.from_reg2(from_reg[2]),.from_reg3(from_reg[3]),.from_reg4(from_reg[4]),.from_reg5(from_reg[5]),.from_reg6(from_reg[6]),.from_reg7(from_reg[7]),.from_reg8(from_reg[8]),.from_reg9(from_reg[9]));
	
endmodule

module _16_to_10_decoder_I(d, q);
	input [15:0]d;				//input 16bit d
	output reg [9:0]q;		//output reg 10bit q
	
	always@(d) begin
		case(d)							
			16'b0000_0001_0001_0000 : q = 10'b00_0000_0001;//INST_REG
			16'b0000_0001_0001_0001 : q = 10'b00_0000_0010;
			16'b0000_0001_0001_0010 : q = 10'b00_0000_0100;
			16'b0000_0001_0001_0011 : q = 10'b00_0000_1000;
			16'b0000_0001_0001_0100 : q = 10'b00_0001_0000;
			16'b0000_0001_0001_0101 : q = 10'b00_0010_0000;
			16'b0000_0001_0001_0110 : q = 10'b00_0100_0000;
			16'b0000_0001_0001_0111 : q = 10'b00_1000_0000;
			16'b0000_0001_0001_1000 : q = 10'b01_0000_0000;
			16'b0000_0001_0001_1001 : q = 10'b10_0000_0000;
			default : q = 10'hx;
		endcase
	end
endmodule

module write_operation_10_I(clk, reset_n, Addr, to_reg, we);
	input we, clk, reset_n;				//input we
	input [15:0]Addr;		//input 4bit Addr	
	output [9:0]to_reg;	//output 10bit to_reg
	
	wire[9:0] write_wire;	//wire
	
	_16_to_10_decoder_I U0(.d(Addr),.q(write_wire));	//instance 16 to 10
	_and2 U1(.a(write_wire[0]),.b(we),.y(to_reg[0]));	//intstance and gate
	_and2 U2(.a(write_wire[1]),.b(we),.y(to_reg[1]));	//and gate instance
	_and2 U3(.a(write_wire[2]),.b(we),.y(to_reg[2]));
	_and2 U4(.a(write_wire[3]),.b(we),.y(to_reg[3]));
	_and2 U5(.a(write_wire[4]),.b(we),.y(to_reg[4]));
	_and2 U6(.a(write_wire[5]),.b(we),.y(to_reg[5]));
	_and2 U7(.a(write_wire[6]),.b(we),.y(to_reg[6]));
	_and2 U8(.a(write_wire[7]),.b(we),.y(to_reg[7]));
	_and2 U9(.a(write_wire[8]),.b(we),.y(to_reg[8]));
	_and2 U10(.a(write_wire[9]),.b(we),.y(to_reg[9]));	//---DATA_REG---
	
	
endmodule

module _10_to_1_MUX_I(a,b,c,d,e,f,g,h,i,j,sel,d_out);
	input [63:0]a,b,c,d,e,f,g,h,i,j;		//input 64bit a~w
	input [15:0]sel;							//input 16bit sel
	output reg[63:0]d_out;					//output reg 64bit d_out
	
	always@(sel,a,b,c,d,e,f,g,h,i,j)		//select
	begin
		case(sel) //choose one.
			16'b0000_0001_0001_0000 : d_out = a;
			16'b0000_0001_0001_0001 : d_out = b;
			16'b0000_0001_0001_0010 : d_out = c;
			16'b0000_0001_0001_0011 : d_out = d;
			16'b0000_0001_0001_0100 : d_out = e;
			16'b0000_0001_0001_0101 : d_out = f;
			16'b0000_0001_0001_0110 : d_out = g;
			16'b0000_0001_0001_0111 : d_out = h;
			16'b0000_0001_0001_1000 : d_out = i;
			16'b0000_0001_0001_1001 : d_out = j;
			default : d_out = 64'hx;
		endcase
	end
endmodule

module read_operation_10_I(Addr,Data,from_reg0,from_reg1,from_reg2,from_reg3,from_reg4,from_reg5,from_reg6,from_reg7,from_reg8,from_reg9);
	input [63:0] from_reg0,from_reg1,from_reg2,from_reg3,from_reg4,from_reg5,from_reg6,from_reg7,from_reg8,from_reg9;
									//input 64bit reg0 ~ reg9
	input [15:0] Addr;		//input 16bit Addr
	output [63:0] Data;		//output 64bit Data
	
	_10_to_1_MUX_I U0(.a(from_reg0),.b(from_reg1),.c(from_reg2),.d(from_reg3),.e(from_reg4),.f(from_reg5),.g(from_reg6),.h(from_reg7),.i(from_reg8),.j(from_reg9),.sel(Addr),.d_out(Data));
endmodule





//--------------------------------------------make_Register_file CONT_REG--------------------------------------
module Register_file_3_C(clk, reset_n, W_addr, R_addr, wData, we, rData);
	input clk, reset_n, we;
	input [15:0] W_addr, R_addr;
	input [63:0] wData;
	output [63:0] rData;
	
	wire [2:0] to_reg;
	wire [63:0] from_reg[2:0];
	
	register64_3 U0_register64_3(.clk(clk),.reset_n(reset_n),.en(to_reg),.d_in(wData),.d_out0(from_reg[0]),.d_out1(from_reg[1]),.d_out2(from_reg[2]));
	
	write_operation_3 U1_write_operation(.clk(clk), .reset_n(reset_n),.Addr(W_addr),.we(we),.to_reg(to_reg));
	
	read_operation_3 U2_read_operation(.Addr(R_addr),.Data(rData),.from_reg0(from_reg[0]),.from_reg1(from_reg[1]),.from_reg2(from_reg[2]));

endmodule

module _16_to_3_decoder(d, q);
	input [15:0]d;				//input 16bit d
	output reg [2:0]q;		//output reg 10bit q
	
	always@(d) begin
		case(d)							
			16'b0000_0001_0010_0000 : q = 3'b001;//CONT_REG
			16'b0000_0001_0010_0001 : q = 3'b010;
			16'b0000_0001_0010_0010 : q = 3'b100;
			default : q = 3'hx;
		endcase
	end
endmodule

module write_operation_3(clk, reset_n, Addr, to_reg, we);
	input we, clk, reset_n;				//input we
	input [15:0]Addr;		//input 4bit Addr	
	output [2:0]to_reg;	//output 10bit to_reg
	
	wire[2:0] write_wire;	//wire
	
	_16_to_3_decoder U0(.d(Addr),.q(write_wire));	//instance 16 to 10
	_and2 U1(.a(write_wire[0]),.b(we),.y(to_reg[0]));	//intstance and gate
	_and2 U2(.a(write_wire[1]),.b(we),.y(to_reg[1]));	//and gate instance
	_and2 U3(.a(write_wire[2]),.b(we),.y(to_reg[2]));
endmodule

module read_operation_3(Addr,Data,from_reg0,from_reg1,from_reg2);
	input [63:0] from_reg0,from_reg1,from_reg2;
									//input 64bit reg0 ~ reg9
	input [15:0] Addr;		//input 16bit Addr
	output [63:0] Data;		//output 64bit Data
	
	_3_to_1_MUX U0(.a(from_reg0),.b(from_reg1),.c(from_reg2),.sel(Addr),.d_out(Data));

endmodule

module _3_to_1_MUX(a,b,c,sel,d_out);
	input [63:0]a,b,c;						//input 64bit a~c
	input [15:0]sel;							//input 16bit sel
	output reg[63:0]d_out;					//output reg 64bit d_out
	
	always@(sel,a,b,c)		//select
	begin
		case(sel) //choose one.
			16'b0000_0001_0010_0000 : d_out = a;
			16'b0000_0001_0010_0001 : d_out = b;
			16'b0000_0001_0010_0010 : d_out = c;
			default : d_out = 64'hx;
		endcase
	end
endmodule





//--------------------------------------------make_Register_file----------------------------------------------
module _dff_r_en(clk, reset_n, en, d, q);
	input clk, reset_n, en, d;		//input clk, reset_n, en, d
	output reg q;						//output reg q
	
	always @ (posedge clk or negedge reset_n) begin
		if(~reset_n) q<=1'b0;
		else if(en) q<=d;
		else q<=q;
	end			//setting
endmodule

module register8_r_en(clk,reset_n,d_in,d_out,en);
	input clk,reset_n,en;	//input clk, reset_n, en
	input [7:0]d_in;			//input 8bit d_in
	output [7:0]d_out;		//output 8bit d_out
	
	_dff_r_en U0(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[0]),.q(d_out[0]));//instance en able d flip flop
	_dff_r_en U1(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[1]),.q(d_out[1]));//instance en able d flip flop
	_dff_r_en U2(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[2]),.q(d_out[2]));//instance en able d flip flop
	_dff_r_en U3(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[3]),.q(d_out[3]));//instance en able d flip flop
	_dff_r_en U4(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[4]),.q(d_out[4]));//instance en able d flip flop
	_dff_r_en U5(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[5]),.q(d_out[5]));//instance en able d flip flop
	_dff_r_en U6(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[6]),.q(d_out[6]));//instance en able d flip flop
	_dff_r_en U7(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[7]),.q(d_out[7]));//instance en able d flip flop
endmodule

module register64_r_en(clk,reset_n,d_in,d_out,en);
	input clk, reset_n, en;		//input clk, reset_n, en
	input [63:0]d_in;				//input 32bit d_in
	output [63:0]d_out;			//output 32bit d_out
	
	register8_r_en U0(.clk(clk),.reset_n(reset_n),.d_in(d_in[7:0]),.d_out(d_out[7:0]),.en(en));			//instance register8_r_en
	register8_r_en U1(.clk(clk),.reset_n(reset_n),.d_in(d_in[15:8]),.d_out(d_out[15:8]),.en(en));		//instance register8_r_en
	register8_r_en U2(.clk(clk),.reset_n(reset_n),.d_in(d_in[23:16]),.d_out(d_out[23:16]),.en(en));		//instance register8_r_en
	register8_r_en U3(.clk(clk),.reset_n(reset_n),.d_in(d_in[31:24]),.d_out(d_out[31:24]),.en(en));		//instance register8_r_en
	register8_r_en U4(.clk(clk),.reset_n(reset_n),.d_in(d_in[39:32]),.d_out(d_out[39:32]),.en(en));		//instance register8_r_en
	register8_r_en U5(.clk(clk),.reset_n(reset_n),.d_in(d_in[47:40]),.d_out(d_out[47:40]),.en(en));		//instance register8_r_en
	register8_r_en U6(.clk(clk),.reset_n(reset_n),.d_in(d_in[55:48]),.d_out(d_out[55:48]),.en(en));		//instance register8_r_en
	register8_r_en U7(.clk(clk),.reset_n(reset_n),.d_in(d_in[63:56]),.d_out(d_out[63:56]),.en(en));		//instance register8_r_en
endmodule

module register64_10(clk,reset_n,en,d_in,d_out0,d_out1,d_out2,d_out3,d_out4,d_out5,d_out6,d_out7,d_out8,d_out9);

	input clk,reset_n;		//input clk, reset_n
	input [9:0]en;				//input 23bit en
	input [63:0]d_in;			//input 64bit d_in
	output [63:0]d_out0,d_out1,d_out2,d_out3,d_out4,d_out5,d_out6,d_out7,d_out8,d_out9;	//output 64bit 0~9, DATA_REG, INST_REG
	
	register64_r_en U0_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out0),.en(en[0]));//instance register64_r_en
	register64_r_en U1_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out1),.en(en[1]));//instance register64_r_en
	register64_r_en U2_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out2),.en(en[2]));//instance register64_r_en
	register64_r_en U3_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out3),.en(en[3]));//instance register64_r_en
	register64_r_en U4_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out4),.en(en[4]));//instance register64_r_en
	register64_r_en U5_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out5),.en(en[5]));//instance register64_r_en
	register64_r_en U6_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out6),.en(en[6]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out7),.en(en[7]));//instance register64_r_en
	register64_r_en U8_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out8),.en(en[8]));//instance register64_r_en
	register64_r_en U9_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out9),.en(en[9]));//instance register64_r_en, DATA_REG, INST_REG
	
endmodule 

module register64_3(clk,reset_n,en,d_in,d_out0,d_out1,d_out2);
	input clk,reset_n;						//input clk, reset_n
	input [2:0]en;								//input 3bit en
	input [63:0]d_in;							//input 64bit d_in
	output [63:0]d_out0,d_out1,d_out2;	//output 64bit 0~2, CONT_REG
	
	register64_r_en U0_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out0),.en(en[0]));//instance register64_r_en
	register64_r_en U1_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out1),.en(en[1]));//instance register64_r_en
	register64_r_en U2_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out2),.en(en[2]));//instance register64_r_en, CONT_REG
	
endmodule









/*

//----------------------------------------------------make Register_file23-----------------------------------------
module Register_file_23(clk,reset_n,wAddr,wData,we,rAddr,rData);
	input clk,reset_n,we;		//input clk, reset_n, we
	input [7:0]wAddr, rAddr;	//input 7bit wAddr, rAddr
	input [63:0]wData;			//input 64bit wData
	output [63:0]rData;			//output 64bit rData
	
	wire[9:0]to_reg;				//wire 10bit to_reg
	wire[63:0]from_reg[9:0];	//wire 64bit from_reg 8bit (64bit register * 10)
	
	register64_23 U0_register64_23(.clk(clk),.reset_n(reset_n),.en(to_reg),.d_in(wData),.d_out0(from_reg[0]),.d_out1(from_reg[1]),.d_out2(from_reg[2]),.d_out3(from_reg[3]),.d_out4(from_reg[4]),.d_out5(from_reg[5]),.d_out6(from_reg[6]),.d_out7(from_reg[7]),.d_out8(from_reg[8]),.d_out(from_reg[9]),
	.d_out10(from_reg[10]),.d_out11(from_reg[11]),.d_out12(from_reg[12]),.d_out13(from_reg[13]),.d_out14(from_reg[14]),.d_out15(from_reg[15]),.d_out16(from_reg[16]),.d_out17(from_reg[17]),.d_out18(from_reg[18]),.d_out19(from_reg[19]),
	.d_out20(from_reg[20]),.d_out21(from_reg[21]),.d_out22(from_reg[22]),);
	//register32_8 instance

	write_operation U1(.Addr(wAddr),.we(we),.to_reg(to_reg));
	//instance write operation
	
	read_operation U2(.Addr(rAddr),.Data(rData),.from_reg0(from_reg[0]),.from_reg1(from_reg[1]),.from_reg2(from_reg[2]),.from_reg3(from_reg[3]),.from_reg4(from_reg[4]),.from_reg5(from_reg[5]),.from_reg6(from_reg[6]),.from_reg7(from_reg[7]),.from_reg8(from_reg8[8]),.from_reg9(from_reg9[9])
	,.from_reg10(from_reg[10]),.from_reg11(from_reg[11]),.from_reg12(from_reg[12]),.from_reg13(from_reg[13]),.from_reg14(from_reg[14]),.from_reg15(from_reg[15]),.from_reg16(from_reg[16]),.from_reg17(from_reg[17]),.from_reg18(from_reg[18]),.from_reg19(from_reg[19])
	,.from_reg20(from_reg[20]),.from_reg21(from_reg[21]),.from_reg22(from_reg[22]));	
	//instance read_operation
endmodule

module _16_to_23_decoder(d,q);
	input [7:0]d;				//input 8bit d
	output reg [22:0]q;		//output reg 23bit q
	
	always@(d) begin
		case(d)							
			16'b0000_0001_0000_0000 : q = 23'b000_0000_0000_0000_0000_0001;//DATA_REG
			16'b0000_0001_0000_0001 : q = 23'b000_0000_0000_0000_0000_0010;
			16'b0000_0001_0000_0010 : q = 23'b000_0000_0000_0000_0000_0100;
			16'b0000_0001_0000_0011 : q = 23'b000_0000_0000_0000_0000_1000;
			16'b0000_0001_0000_0100 : q = 23'b000_0000_0000_0000_0001_0000;
			16'b0000_0001_0000_0101 : q = 23'b000_0000_0000_0000_0010_0000;
			16'b0000_0001_0000_0110 : q = 23'b000_0000_0000_0000_0100_0000;
			16'b0000_0001_0000_0111 : q = 23'b000_0000_0000_0000_1000_0000;
			16'b0000_0001_0000_1000 : q = 23'b000_0000_0000_0001_0000_0000;
			16'b0000_0001_0000_1001 : q = 23'b000_0000_0000_0010_0000_0000;
			
			
			16'b0000_0001_0001_0000 : q = 23'b000_0000_0000_0100_0000_0000;//INST_REG
			16'b0000_0001_0001_0001 : q = 23'b000_0000_0000_1000_0000_0000;
			16'b0000_0001_0001_0010 : q = 23'b000_0000_0001_0000_0000_0000;
			16'b0000_0001_0001_0011 : q = 23'b000_0000_0010_0000_0000_0000;
			16'b0000_0001_0001_0100 : q = 23'b000_0000_0100_0000_0000_0000;
			16'b0000_0001_0001_0101 : q = 23'b000_0000_1000_0000_0000_0000;
			16'b0000_0001_0001_0110 : q = 23'b000_0001_0000_0000_0000_0000;
			16'b0000_0001_0001_0111 : q = 23'b000_0010_0000_0000_0000_0000;
			16'b0000_0001_0001_1000 : q = 23'b000_0100_0000_0000_0000_0000;
			16'b0000_0001_0001_0001 : q = 23'b000_1000_0000_0000_0000_0000;
			
			
			16'b0000_0001_0010_0000 : q = 23'b001_0000_0000_0000_0000_0000//CONT_REG
			16'b0000_0001_0010_0001 : q = 23'b010_0000_0000_0000_0000_0000
			16'b0000_0001_0010_0010 : q = 23'b100_0000_0000_0000_0000_0000
			default : q = 23'hx;
		endcase
	end
endmodule

module write_operation(Addr,we,to_reg);
	input we;				//input we
	input [7:0]Addr;		//input 4bit Addr	
	output [22:0]to_reg;	//output 23bit to_reg
	
	wire[22:0] write_wire;	//wire
	
	_16_to_23_decoder U0(.d(Addr),.q(write_wire));		//instance 16 to 23
	_and2 U1(.a(write_wire[0]),.b(we),.y(to_reg[0]));	//intstance and gate
	_and2 U2(.a(write_wire[1]),.b(we),.y(to_reg[1]));	//and gate instance
	_and2 U3(.a(write_wire[2]),.b(we),.y(to_reg[2]));
	_and2 U4(.a(write_wire[3]),.b(we),.y(to_reg[3]));
	_and2 U5(.a(write_wire[4]),.b(we),.y(to_reg[4]));
	_and2 U6(.a(write_wire[5]),.b(we),.y(to_reg[5]));
	_and2 U7(.a(write_wire[6]),.b(we),.y(to_reg[6]));
	_and2 U8(.a(write_wire[7]),.b(we),.y(to_reg[7]));
	_and2 U9(.a(write_wire[8]),.b(we),.y(to_reg[8]));
	_and2 U10(.a(write_wire[9]),.b(we),.y(to_reg[9]));	//---DATA_REG---
	
	_and2 U10(.a(write_wire[10]),.b(we),.y(to_reg[10]));
	_and2 U10(.a(write_wire[11]),.b(we),.y(to_reg[11]));
	_and2 U10(.a(write_wire[12]),.b(we),.y(to_reg[12]));
	_and2 U10(.a(write_wire[13]),.b(we),.y(to_reg[13]));
	_and2 U10(.a(write_wire[14]),.b(we),.y(to_reg[14]));
	_and2 U10(.a(write_wire[15]),.b(we),.y(to_reg[15]));
	_and2 U10(.a(write_wire[16]),.b(we),.y(to_reg[16]));
	_and2 U10(.a(write_wire[17]),.b(we),.y(to_reg[17]));
	_and2 U10(.a(write_wire[18]),.b(we),.y(to_reg[18]));
	_and2 U10(.a(write_wire[19]),.b(we),.y(to_reg[19]));	//---INST_REG---
	
	_and2 U10(.a(write_wire[20]),.b(we),.y(to_reg[20]));
	_and2 U10(.a(write_wire[21]),.b(we),.y(to_reg[21]));
	_and2 U10(.a(write_wire[22]),.b(we),.y(to_reg[22]));	//---CONT_REG---
	
endmodule


module _dff_r_en(clk, reset_n, en, d, q);
	input clk, reset_n, en, d;		//input clk, reset_n, en, d
	output reg q;					//output reg q
	
	always @ (posedge clk or negedge reset_n) begin
		if(~reset_n) q<=1'b0;
		else if(en) q<=d;
		else q<=q;
	end			//setting
endmodule

module register8_r_en(clk,reset_n,d_in,d_out,en);
	input clk,reset_n,en;	//input clk, reset_n, en
	input [7:0]d_in;			//input 8bit d_in
	output [7:0]d_out;		//output 8bit d_out
	
	_dff_r_en U0(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[0]),.q(d_out[0]));//instance en able d flip flop
	_dff_r_en U1(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[1]),.q(d_out[1]));//instance en able d flip flop
	_dff_r_en U2(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[2]),.q(d_out[2]));//instance en able d flip flop
	_dff_r_en U3(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[3]),.q(d_out[3]));//instance en able d flip flop
	_dff_r_en U4(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[4]),.q(d_out[4]));//instance en able d flip flop
	_dff_r_en U5(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[5]),.q(d_out[5]));//instance en able d flip flop
	_dff_r_en U6(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[6]),.q(d_out[6]));//instance en able d flip flop
	_dff_r_en U7(.clk(clk),.reset_n(reset_n),.en(en),.d(d_in[7]),.q(d_out[7]));//instance en able d flip flop
endmodule

module register64_r_en(clk,reset_n,d_in,d_out,en);
	input clk, reset_n, en;		//input clk, reset_n, en
	input [63:0]d_in;				//input 32bit d_in
	output [63:0]d_out;			//output 32bit d_out
	
	register8_r_en U0(.clk(clk),.reset_n(reset_n),.d_in(d_in[7:0]),.d_out(d_out[7:0]),.en(en));			//instance register8_r_en
	register8_r_en U1(.clk(clk),.reset_n(reset_n),.d_in(d_in[15:8]),.d_out(d_out[15:8]),.en(en));		//instance register8_r_en
	register8_r_en U2(.clk(clk),.reset_n(reset_n),.d_in(d_in[23:16]),.d_out(d_out[23:16]),.en(en));		//instance register8_r_en
	register8_r_en U3(.clk(clk),.reset_n(reset_n),.d_in(d_in[31:24]),.d_out(d_out[31:24]),.en(en));		//instance register8_r_en
	register8_r_en U3(.clk(clk),.reset_n(reset_n),.d_in(d_in[39:32]),.d_out(d_out[39:32]),.en(en));		//instance register8_r_en
	register8_r_en U3(.clk(clk),.reset_n(reset_n),.d_in(d_in[47:40]),.d_out(d_out[47:40]),.en(en));		//instance register8_r_en
	register8_r_en U3(.clk(clk),.reset_n(reset_n),.d_in(d_in[51:48]),.d_out(d_out[51:48]),.en(en));		//instance register8_r_en
	register8_r_en U3(.clk(clk),.reset_n(reset_n),.d_in(d_in[63:52]),.d_out(d_out[63:52]),.en(en));		//instance register8_r_en
endmodule

module register64_23(clk,reset_n,en,d_in,d_out0,d_out1,d_out2,d_out3,d_out4,d_out5,d_out6,d_out7,d_out8,d_out9
d_out10,d_out11,d_out12,d_out13,d_out14,d_out15,d_out16,d_out17,d_out18,d_out19,d_out20
d_out21,d_out22,d_out23);

	input clk,reset_n;		//input clk, reset_n
	input [22:0]en;			//input 23bit en
	input [63:0]d_in;			//input 64bit d_in
	output [63:0]d_out0,d_out1,d_out2,d_out3,d_out4,d_out5,d_out6,d_out7,d_out8,d_out9;	//output 64bit 0~9, DATA_REG
	output [63:0]d_out10,d_out11,d_out12,d_out13,d_out14,d_out15,d_out16,d_out17,d_out18,d_out19;	//output 64bit 10~19, INST_REG
	output [63:0]d_out20,d_out21,d_out22;	//output 64bit 20~22, CONT_REG
	
	register64_r_en U0_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out0),.en(en[0]));//instance register64_r_en
	register64_r_en U1_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out1),.en(en[1]));//instance register64_r_en
	register64_r_en U2_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out2),.en(en[2]));//instance register64_r_en
	register64_r_en U3_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out3),.en(en[3]));//instance register64_r_en
	register64_r_en U4_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out4),.en(en[4]));//instance register64_r_en
	register64_r_en U5_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out5),.en(en[5]));//instance register64_r_en
	register64_r_en U6_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out6),.en(en[6]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out7),.en(en[7]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out8),.en(en[8]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out9),.en(en[9]));//instance register64_r_en, DATA_REG
	
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out10),.en(en[10]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out11),.en(en[11]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out12),.en(en[12]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out13),.en(en[13]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out14),.en(en[14]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out15),.en(en[15]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out16),.en(en[16]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out17),.en(en[17]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out18),.en(en[18]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out19),.en(en[19]));//instance register64_r_en, INST_REG
	
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out20),.en(en[20]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out21),.en(en[21]));//instance register64_r_en
	register64_r_en U7_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out22),.en(en[22]));//instance register64_r_en, CONT_REG
endmodule

module _23_to_1_MUX(a,b,c,d,e,f,g,h,i,j
,k,l,m,n,o,p,q,r,s,t
,u,v,w,sel,d_out);

	input [63:0]a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w;		//input 64bit a~w
	input [7:0]sel;																//input 8bit sel
	output reg[63:0]d_out;														//output reg 64bit d_out
	
	always@(sel,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w)		//select
	begin
		case(sel) //choose one.
			8'b0000_0000 : d_out = a;
			8'b0000_0001 : d_out = b;
			8'b0000_0010 : d_out = c;
			8'b0000_0011 : d_out = d;
			8'b0000_0100 : d_out = e;
			8'b0000_0101 : d_out = f;
			8'b0000_0110 : d_out = g;
			8'b0000_0111 : d_out = h;
			8'b0000_1000 : d_out = i;
			8'b0000_1001 : d_out = j;
			
			8'b0001_0000 : d_out = k;
			8'b0001_0001 : d_out = l;
			8'b0001_0010 : d_out = m;
			8'b0001_0011 : d_out = n;
			8'b0001_0100 : d_out = o;
			8'b0001_0101 : d_out = p;
			8'b0001_0110 : d_out = q;
			8'b0001_0111 : d_out = r;
			8'b0001_1000 : d_out = s;
			8'b0001_1001 : d_out = t;
			
			8'b0010_0000 : d_out = u;
			8'b0010_0001 : d_out = v;
			8'b0010_0010 : d_out = w;
			default : d_out = 64'hx;
		endcase
	end
endmodule



module read_operation(Addr,Data,from_reg0,from_reg1,from_reg2,from_reg3,from_reg4,from_reg5,from_reg6,from_reg7,from_reg8,from_reg9,
from_reg10,from_reg11,from_reg12,from_reg13,from_reg14,from_reg15,from_reg16,from_reg17,from_reg18,from_reg19,
from_reg20,from_reg21,from_reg22);
					
	input [63:0] from_reg0,from_reg1,from_reg2,from_reg3,from_reg4,from_reg5,from_reg6,from_reg7,from_reg8,from_reg9;
	input [63:0] from_reg10,from_reg11,from_reg12,from_reg13,from_reg14,from_reg15,from_reg16,from_reg17,from_reg18,from_reg19;
	input [63:0] from_reg20,from_reg21,from_reg22;
									//input 64bit reg0 ~ reg22
	input [7:0] Addr;			//input 8bit Addr
	output [63:0] Data;		//output 64bit Data
	
	_23_to_1_MUX U0(.a(from_reg0),.b(from_reg1),.c(from_reg2),.d(from_reg3),.e(from_reg4),.f(from_reg5),.g(from_reg6),.h(from_reg7),.i(from_reg8),.j(from_reg9),
	.k(from_reg10),.l(from_reg11),.m(from_reg12),.n(from_reg13),.o(from_reg14),.p(from_reg15),.q(from_reg16),.r(from_reg17),.s(from_reg18),.t(from_reg19),
	.u(from_reg20),.v(from_reg21),.w(from_reg22)
	.sel(Addr),.d_out(Data));
									//instance multiplexer
endmodule

*/
