module tb_TOP();
	reg tb_clk, tb_reset_n;
	reg tb_m_req, tb_m_wr;
	reg [15:0]tb_m_addr;
	reg [31:0]tb_m_dout;
	wire tb_m_grant;
	wire tb_interrupt_out;
	wire [63:0]tb_m_din;
	wire [2:0] tb_state;
	TOP U0(.clk(tb_clk), .reset_n(tb_reset_n), .m_req(tb_m_req), .m_wr(tb_m_wr), .m_addr(tb_m_addr), .m_dout(tb_m_dout), .m_grant(tb_m_grant), .interrupt_out(tb_interrupt_out), .m_din(tb_m_din),.state(tb_state));

	parameter STEP=10;
	always#(STEP/2)tb_clk=~tb_clk;
	
	initial
		begin
		tb_clk = 1;tb_reset_n = 0;
		tb_m_req = 1;
		tb_m_wr = 1;
		
		#8
		tb_reset_n = 1;
		tb_m_addr = 16'h0100;
		tb_m_dout = 32'h0000_0000;
		#2
		
		#8
		tb_m_addr = 16'h0101;
		tb_m_dout = 32'h0000_0001;
		#2
		
		#8
		tb_m_addr = 16'h0102;
		tb_m_dout = 32'h0000_0002;
		#2
		
		#8
		tb_m_addr = 16'h0103;
		tb_m_dout = 32'h0000_0003;
		#2
		
		#8
		tb_m_addr = 16'h0104;
		tb_m_dout = 32'h0000_0004;
		#2
		
		#8
		tb_m_addr = 16'h0105;
		tb_m_dout = 32'h0000_0005;
		#2
		
		#8
		tb_m_addr = 16'h0106;
		tb_m_dout = 32'h0000_0006;
		#2
		
		#8
		tb_m_addr = 16'h0107;
		tb_m_dout = 32'h0000_0007;
		#2
		
		#8
		tb_m_addr = 16'h0108;
		tb_m_dout = 32'h0000_0008;
		#2
		
		
		#8
		tb_m_addr = 16'h0109;
		tb_m_dout = 32'h0000_0009;
		#2
		///////////////////////////////////////////////
		#8
		tb_m_addr = 16'h0110;
		tb_m_dout = 32'h1111_0011;
		#2
		
		#STEP
		#8 tb_m_addr = 16'h0111;
		tb_m_dout = 32'h1111_1112;
		#2
		
		
		#8 tb_m_addr = 16'h0112;
		tb_m_dout = 32'h1111_2213;
		#2
		
		#8 tb_m_addr = 16'h0113;
		tb_m_dout = 32'h1111_3314;
		#2
		
		#8 tb_m_addr = 16'h0114;
		tb_m_dout = 32'h1111_4415;
		#2
		
		#8 tb_m_addr = 16'h0115;
		tb_m_dout = 32'h1111_5516;
		#2
		
		#8 tb_m_addr = 16'h0116;
		tb_m_dout = 32'h1111_6617;
		#2
		
		#8 tb_m_addr = 16'h0117;
		tb_m_dout = 32'h1111_7718;
		#2
		
		#8 tb_m_addr = 16'h0118;
		tb_m_dout = 32'h1111_8819;
		#2
		
		#8 tb_m_addr = 16'h0119;
		tb_m_dout = 32'h1111_8920;
		#2
		
		#8 tb_m_addr = 16'h1111;
		tb_m_dout = 32'h1111_1413;
		
		#STEP
		
		tb_m_wr = 0;
		#8
		tb_m_addr = 16'h0100;
		#2
		
		#8
		tb_m_addr = 16'h0101;
		#2
		
		#8
		tb_m_addr = 16'h0102;
		#2
		
		#8
		tb_m_addr = 16'h0103;
		#2
		
		#8
		tb_m_addr = 16'h0104;
		#2
		
		#8
		tb_m_addr = 16'h0105;
		#2
		
		#8
		tb_m_addr = 16'h0106;
		#2
		
		#8
		tb_m_addr = 16'h0107;
		#2
		
		#8
		tb_m_addr = 16'h0108;
		#2
		
		#8
		tb_m_addr = 16'h0109;
		#2
		
		#8
		tb_m_addr = 16'h0110;
		#2
		
		#8
		tb_m_addr = 16'h0111;
		#2
		
		#8
		tb_m_addr = 16'h0112;
		#2
		
		#8
		tb_m_addr = 16'h0113;
		#2
		
		#8
		tb_m_addr = 16'h0114;
		#2
		
		#8
		tb_m_addr = 16'h0115;
		#2
		
		#8
		tb_m_addr = 16'h0116;
		#2
		
		#8
		tb_m_addr = 16'h0117;
		#2
		
		#8
		tb_m_addr = 16'h0118;
		#2
		
		#8
		tb_m_addr = 16'h0119;
		#2
		
		
		$stop;
		end
	
	
endmodule
