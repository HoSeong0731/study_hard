`timescale 1ns/100ps

module tb_ram();
	reg tb_clk;
	reg tb_cen, tb_wen;
	reg [4:0] tb_addr;
	reg [31:0] tb_din;
	
	wire [31:0] tb_dout;
	
	ram U0_ram(.clk(tb_clk),.cen(tb_cen),.wen(tb_wen),.addr(tb_addr),.din(tb_din),.dout(tb_dout));
	
	parameter STEP = 10;
	always#(STEP/2)tb_clk=~tb_clk;
	
	initial
		begin
		//initialize
		tb_clk = 1; 
		tb_cen = 0; 
		tb_wen = 0; 
		tb_addr = 5'b0; 
		tb_din = 32'b0; 
		
		//step1
		#STEP
		
		//step2 [Write]
		#8 tb_cen = 1; tb_wen = 1;
		#2
		
		//step3
		#8 tb_addr = 5'b00000; tb_din = 32'h 0000_0001;
		#2
		
		//step4
		#8 tb_addr = 5'b00001; tb_din = 32'h 0000_0002;
		#2
		
		//step5
		#8 tb_addr = 5'b00010; tb_din = 32'h 0000_0003;
		#2
		
		//step6
		#8 tb_addr = 5'b00011; tb_din = 32'h 0000_0004;
		#2
		
		//step7
		#8 tb_addr = 5'b00100; tb_din = 32'h 0000_0005;
		#2
		
		//step8
		#8 tb_addr = 5'b00101; tb_din = 32'h 0000_0006;
		#2
		
		//step9
		#8 tb_addr = 5'b00110; tb_din = 32'h 0000_0007;
		#2
		
		//step10
		#8 tb_addr = 5'b00111; tb_din = 32'h 0000_0008;
		#2
		
		//step11
		#8 tb_addr = 5'b01000; tb_din = 32'h 0000_0008;
		#2
		
		//step12
		#8 tb_addr = 5'b01001; tb_din = 32'h 0000_0009;
		#2
		
		//step13
		#8 tb_addr = 5'b01010; tb_din = 32'h 0000_00010;
		#2
		
		//step14
		#8 tb_addr = 5'b01011; tb_din = 32'h 0000_0011;
		#2
		
		//step15
		#8 tb_addr = 5'b01100; tb_din = 32'h 0000_0012;
		#2
		
		//step16
		#8 tb_addr = 5'b01101; tb_din = 32'h 0000_0013;
		#2
		
		//step17
		#8 tb_addr = 5'b01110; tb_din = 32'h 0000_0014;
		#2
		
		//step18
		#8 tb_addr = 5'b01111; tb_din = 32'h 0000_0015;
		#2
		
		//step19
		#8 tb_addr = 5'b10000; tb_din = 32'h 0000_0016;
		#2
		
		//step20 [Read]
		#8 tb_wen = 0;
		#2
		
		//step21
		#8 tb_addr = 5'b01111;
		#2
		
		//step22
		#8 tb_addr = 5'b01110;
		#2
		
		//step23
		#8 tb_addr = 5'b01101;
		#2
		
		//step24
		#8 tb_addr = 5'b01100;
		#2
		
		//step25
		#8 tb_addr = 5'b01011;
		#2
		
		//step26
		#8 tb_addr = 5'b01010;
		#2
		
		//step27
		#8 tb_addr = 5'b01001;
		#2
		
		//step28
		#8 tb_addr = 5'b01000;
		#2
		
		//step29
		#8 tb_addr = 5'b00111;
		#2
		
		//step30
		#8 tb_addr = 5'b00110;
		#2
		
		//step31
		#8 tb_addr = 5'b00101;
		#2
		
		//step32
		#8 tb_addr = 5'b00100;
		#2
		
		//step33
		#8 tb_addr = 5'b00011;
		#2
		
		//step34
		#8 tb_addr = 5'b00010;
		#2
		
		//step35
		#8 tb_addr = 5'b00001;
		#2
		
		//step36
		#8 tb_addr = 5'b00000;
		#2
		
		//step 37 [Initialization]
		#8 tb_cen = 0;
		#2
		
		#8
		#2
		
		//step 38 [Read]	//addr = 5'b00000
		#8 tb_cen = 1;
		#2
		
		#8
		#2
		
		//step 39 [Write] //addr = 5'b00000
		#8 tb_wen = 1;
		#2
		
		#8
		#2
		$stop;
		end
endmodule
		
		