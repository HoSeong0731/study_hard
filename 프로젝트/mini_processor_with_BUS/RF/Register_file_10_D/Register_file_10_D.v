module Register_file_10_D(clk, reset_n, W_addr, R_addr2, R_addr3, wData, we, rData, rData2);
	input clk, reset_n, we;
	input [15:0]W_addr, R_addr2, R_addr3;
	input [63:0] wData;
	output [63:0] rData, rData2;
	
	wire [9:0] to_reg;
	wire [63:0] from_reg[9:0];
	
	register64_10 U0_register64_10(.clk(clk),.reset_n(reset_n),.en(to_reg),.d_in(wData),.d_out0(from_reg[0]),.d_out1(from_reg[1]),.d_out2(from_reg[2]),.d_out3(from_reg[3]),.d_out4(from_reg[4]),.d_out5(from_reg[5]),.d_out6(from_reg[6]),.d_out7(from_reg[7]),.d_out8(from_reg[8]),.d_out9(from_reg[9]));
	
	write_operation_10_D U1_write_operation(.Addr(W_addr),.we(we),.to_reg(to_reg));
	
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

