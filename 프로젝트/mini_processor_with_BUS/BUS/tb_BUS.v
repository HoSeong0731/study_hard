`timescale 1ns/100ps

module tb_BUS();
	reg tb_clk,tb_reset_n;
	reg tb_m_req, tb_M_wr;
	reg [15:0]tb_M_address;
	reg [31:0]tb_M_dout;
	
	
	reg [31:0]tb_S_dout;

	wire tb_M_grant;
	wire [31:0]tb_M_din;
	
	wire tb_S_sel,tb_S_wr;
	wire [15:0]tb_S_address;
	wire [31:0]tb_S_din;
	
	BUS U0_bus(.clk(tb_clk),.reset_n(tb_reset_n),.m_req(tb_m_req),.m_wr(tb_M_wr),.m_addr(tb_M_address),.m_dout(tb_M_dout),.S_dout(tb_S_dout),.m_grant(tb_M_grant)
	,.m_din(tb_M_din),.s_sel(tb_S_sel),.s_addr(tb_S_address),.s_wr(tb_S_wr),.s_din(tb_S_din));

	
	parameter STEP=10;
	always#(STEP/2)tb_clk=~tb_clk;
	
	initial
		begin
		//initialize
		tb_clk=1;tb_reset_n=0;
		tb_m_req=0;tb_M_address=16'd 0;tb_M_dout=32'd 0;tb_M_wr=0;
		tb_S_dout=32'd 0;
		
		//step1
		#STEP
		
		//step2
		#8	tb_reset_n=1;
		#2
		
		//setp3
		#8	tb_S_dout=32'd 11111111;tb_m_req=1;
		#2
		
		//step4
		#8	tb_M_wr=1;
		#2
		
		//step5
		#8	tb_M_address=16'h 0100;tb_M_dout=32'h 0000_0002;//0000_0000  0x00
		#2
		
		//step6
		#8	tb_M_address=16'h 010A;tb_M_dout=32'h 0000_0004;tb_S_dout=32'd 101010101;//0000_0001  0x01
		#2
		
		//step7   
		#8	tb_M_address=16'h 010F;tb_M_dout=32'h 0000_0006;//0000_0001  0x03
		#2
		
		//step8
		#8	tb_M_address=16'h 0110;tb_M_dout=32'h 0000_0020;tb_S_dout=32'd 11111111;
		#2
		
		//step9
		#8	tb_M_address=16'h 011A;tb_M_dout=32'h 0000_0022;
		#2
		
		//step10
		#8	tb_M_address=16'h 021F;tb_M_dout=32'h 0000_0024;tb_S_dout=32'd 11111111;
		#2
		
		//step11
		#8	tb_M_address=16'h 0220;tb_M_dout=32'h 0000_0026;
		#2
		
		//step12
		#8	tb_M_address=16'h 012A;tb_M_dout=32'h 0000_00ff;
		#2
		
		//step13
		#8	tb_M_address=16'h 022F;tb_M_dout=32'h 0000_0023;tb_S_dout=32'd 101010101;
		#2 
		
		
		///////////////////////////////////////////////
		///////////////////m_req = 0////////////////////
		///////////////////////////////////////////////
		
		
		//step1
		#8	tb_M_wr=0;tb_m_req=0;
		#2
		
		//step2
		#8	tb_M_address=16'h 0100;tb_M_dout=32'h 0000_0002;//0000_0000  0x00
		#2
		
		//step3
		#8	tb_M_address=16'h 010A;tb_M_dout=32'h 0000_0004;//0000_0001  0x01
		#2
		
		//step4   
		#8	tb_M_address=16'h 010F;tb_M_dout=32'h 0000_0006;//0000_0001  0x03
		#2
		
		//step5
		#8	tb_M_address=16'h 0210;tb_M_dout=32'h 0000_0020;
		#2
		
		//step6
		#8	tb_M_address=16'h 011A;tb_M_dout=32'h 0000_0022;
		#2
		
		//step7
		#8	tb_M_address=16'h 021F;tb_M_dout=32'h 0000_0024;
		#2
		
		//step8
		#8	tb_M_address=16'h 0120;tb_M_dout=32'h 0000_0026;
		#2
		
		//step9
		#8	tb_M_address=16'h 022A;tb_M_dout=32'h 0000_00ff;
		#2
		
		//step10
		#8	tb_M_address=16'h 012F;tb_M_dout=32'h 0000_0023;
		#2 tb_m_req=1;
		
		$stop;
		end
endmodule
	