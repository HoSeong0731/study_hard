module Register_file_3_C(clk, reset_n, W_addr, R_addr, wData, we, rData);
	input clk, reset_n, we;
	input [15:0] W_addr, R_addr;
	input [63:0] wData;
	output [63:0] rData;
	
	wire [2:0] to_reg;
	wire [63:0] from_reg[2:0];
	
	register64_3 U0_register64_3(.clk(clk),.reset_n(reset_n),.en(to_reg),.d_in(wData),.d_out0(from_reg[0]),.d_out1(from_reg[1]),.d_out2(from_reg[2]));
	
	write_operation_3 U1_write_operation(.Addr(W_addr),.we(we),.to_reg(to_reg));
	
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

module write_operation_3(Addr, to_reg, we);
	input we;				//input we
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
module register64_3(clk,reset_n,en,d_in,d_out0,d_out1,d_out2);
	input clk,reset_n;						//input clk, reset_n
	input [2:0]en;								//input 3bit en
	input [63:0]d_in;							//input 64bit d_in
	output [63:0]d_out0,d_out1,d_out2;	//output 64bit 0~2, CONT_REG
	
	register64_r_en U0_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out0),.en(en[0]));//instance register64_r_en
	register64_r_en U1_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out1),.en(en[1]));//instance register64_r_en
	register64_r_en U2_register64_r_en(.clk(clk),.reset_n(reset_n),.d_in(d_in),.d_out(d_out2),.en(en[2]));//instance register64_r_en, CONT_REG
	
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
