`timescale 1ns/100ps

module tb_bus();
	reg tb_clk,tb_reset_n;
	reg tb_M0_req, tb_M0_wr;
	reg [7:0]tb_M0_address;
	reg [31:0]tb_M0_dout;
	
	reg tb_M1_req,tb_M1_wr;
	reg [7:0]tb_M1_address;
	reg [31:0]tb_M1_dout;
	
	reg [31:0]tb_S0_dout,tb_S1_dout;

	wire tb_M0_grant,tb_M1_grant;
	wire [31:0]tb_M_din;
	
	wire tb_S0_sel,tb_S1_sel,tb_S_wr;
	wire [7:0]tb_S_address;
	wire [31:0]tb_S_din;
	
	bus U0_bus(.clk(tb_clk),.reset_n(tb_reset_n),.M0_req(tb_M0_req),.M0_wr(tb_M0_wr),.M0_address(tb_M0_address),
				  .M0_dout(tb_M0_dout),.M1_req(tb_M1_req),.M1_wr(tb_M1_wr),.M1_address(tb_M1_address),.M1_dout(tb_M1_dout),
				  .S0_dout(tb_S0_dout),.S1_dout(tb_S1_dout),.M0_grant(tb_M0_grant),.M1_grant(tb_M1_grant),.M_din(tb_M_din),
				  .S0_sel(tb_S0_sel),.S1_sel(tb_S1_sel),.S_address(tb_S_address),.S_wr(tb_S_wr),.S_din(tb_S_din));
	
	parameter STEP=10;
	always#(STEP/2)tb_clk=~tb_clk;
	
	initial
		begin
		//initialize
		tb_clk=1;tb_reset_n=0;
		tb_M0_req=0;tb_M0_address=8'd 0;tb_M0_dout=32'd 0;tb_M0_wr=0;
		tb_M1_req=0;tb_M1_address=8'd 0;tb_M1_dout=32'd 0;tb_M1_wr=0;
		tb_S0_dout=32'd 0;tb_S1_dout=32'd 0;
		
		//step1
		#STEP
		
		//step2
		#8	tb_reset_n=1;
		#2
		
		//setp3
		#8	tb_S0_dout=32'd 1;tb_S1_dout=32'd 2;tb_M0_req=1;
		#2
		
		//step4
		#8	tb_M0_wr=1;
		#2
		
		//step5
		#8	tb_M0_address=8'h 00;tb_M0_dout=32'h 0000_0002;tb_M1_dout=32'h 1111_0002;//0000_0000  0x00
		#2
		
		//step6
		#8	tb_M0_address=8'h 0A;tb_M0_dout=32'h 0000_0004;tb_M1_dout=32'h 1111_0004;//0000_0001  0x01
		#2
		
		//step7   
		#8	tb_M0_address=8'h 0F;tb_M0_dout=32'h 0000_0006;tb_M1_dout=32'h 1111_0006;//0000_0001  0x03
		#2
		
		//step8
		#8	tb_M0_address=8'h 10;tb_M0_dout=32'h 0000_0020;tb_M1_dout=32'h 1111_0020;
		#2
		
		//step9
		#8	tb_M0_address=8'h 1A;tb_M0_dout=32'h 0000_0022;tb_M1_dout=32'h 1111_0022;
		#2
		
		//step10
		#8	tb_M0_address=8'h 1F;tb_M0_dout=32'h 0000_0024;tb_M1_dout=32'h 1111_0024;
		#2
		
		//step11
		#8	tb_M0_address=8'h 20;tb_M0_dout=32'h 0000_0026;tb_M1_dout=32'h 1111_0026;
		#2
		
		//step12
		#8	tb_M0_address=8'h 2A;tb_M0_dout=32'h 0000_00ff;tb_M1_dout=32'h 1111_00ff;
		#2
		
		//step13
		#8	tb_M0_address=8'h 2F;tb_M0_dout=32'h 0000_0023;tb_M1_dout=32'h 1111_0023;
		#2 tb_M0_req=0;
		
		
		///////////////////////////////////////////////
		///////////////////grant-M1////////////////////
		///////////////////////////////////////////////
		
		
		//step1
		#8	tb_M0_wr=0;tb_M1_wr=1;tb_M1_req=1;
		#2
		
		//step2
		#8	tb_M1_address=8'h 00;tb_M0_dout=32'h 0000_0002;tb_M1_dout=32'h 1111_0002;//0000_0000  0x00
		#2
		
		//step3
		#8	tb_M1_address=8'h 0A;tb_M0_dout=32'h 0000_0004;tb_M1_dout=32'h 1111_0004;//0000_0001  0x01
		#2
		
		//step4   
		#8	tb_M1_address=8'h 0F;tb_M0_dout=32'h 0000_0006;tb_M1_dout=32'h 1111_0006;//0000_0001  0x03
		#2
		
		//step5
		#8	tb_M1_address=8'h 10;tb_M0_dout=32'h 0000_0020;tb_M1_dout=32'h 1111_0020;
		#2
		
		//step6
		#8	tb_M1_address=8'h 1A;tb_M0_dout=32'h 0000_0022;tb_M1_dout=32'h 1111_0022;
		#2
		
		//step7
		#8	tb_M1_address=8'h 1F;tb_M0_dout=32'h 0000_0024;tb_M1_dout=32'h 1111_0024;
		#2
		
		//step8
		#8	tb_M1_address=8'h 20;tb_M0_dout=32'h 0000_0026;tb_M1_dout=32'h 1111_0026;
		#2
		
		//step9
		#8	tb_M1_address=8'h 2A;tb_M0_dout=32'h 0000_00ff;tb_M1_dout=32'h 1111_00ff;
		#2
		
		//step10
		#8	tb_M1_address=8'h 2F;tb_M0_dout=32'h 0000_0023;tb_M1_dout=32'h 1111_0023;
		#2 tb_M1_req=0;
		
		
		////////////////////////////////////////////////
		///////////////////grant-M0/////////////////////
		////////////////////////////////////////////////

		
		//step1
		#8	tb_M0_wr=0;tb_M0_req=1;
		#2
		
		//step2
		#8	tb_M0_address=8'h 00;tb_M0_dout=32'h 0000_0002;tb_M1_dout=32'h 1111_0002;//0000_0000  0x00
		#2
		
		//step3
		#8	tb_M0_address=8'h 0A;tb_M0_dout=32'h 0000_0004;tb_M1_dout=32'h 1111_0004;//0000_0001  0x01
		#2
		
		//step4   
		#8	tb_M0_address=8'h 0F;tb_M0_dout=32'h 0000_0006;tb_M1_dout=32'h 1111_0006;//0000_0001  0x03
		#2
		
		//step5
		#8	tb_M0_address=8'h 10;tb_M0_dout=32'h 0000_0020;tb_M1_dout=32'h 1111_0020;
		#2
		
		//step6
		#8	tb_M0_address=8'h 1A;tb_M0_dout=32'h 0000_0022;tb_M1_dout=32'h 1111_0022;
		#2
		
		//step7
		#8	tb_M0_address=8'h 1F;tb_M0_dout=32'h 0000_0024;tb_M1_dout=32'h 1111_0024;
		#2
		
		//step8
		#8	tb_M0_address=8'h 20;tb_M0_dout=32'h 0000_0026;tb_M1_dout=32'h 1111_0026;
		#2
		
		//step9
		#8	tb_M0_address=8'h 2A;tb_M0_dout=32'h 0000_00ff;tb_M1_dout=32'h 1111_00ff;
		#2
		
		//step10
		#8	tb_M0_address=8'h 2F;tb_M0_dout=32'h 0000_0023;tb_M1_dout=32'h 1111_0023;
		#2
		
		$stop;
		end
endmodule
	