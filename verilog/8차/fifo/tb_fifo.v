`timescale 1ns/100ps

module tb_fifo;

	reg tb_clk, tb_reset_n, tb_rd_en,tb_wr_en;
	reg [31:0]tb_din;
	wire [31:0]tb_dout;
	wire tb_full,tb_empty;
	wire tb_wr_ack,tb_wr_err,tb_rd_ack,tb_rd_err;
	wire[3:0]tb_data_count;
	
	
	fifo U0_fifo(.clk(tb_clk), .reset_n(tb_reset_n),.rd_en(tb_rd_en),.wr_en(tb_wr_en),.din(tb_din),.dout(tb_dout),.data_count(tb_data_count),.full(tb_full),.empty(tb_empty),.wr_ack(tb_wr_ack),.wr_err(tb_wr_err),.rd_ack(tb_rd_ack),.rd_err(tb_rd_err));
	parameter STEP=10;
	always#(STEP/2)tb_clk=~tb_clk;
	
	initial
		begin
		//initialize
		tb_clk=0;tb_reset_n=0;tb_rd_en=0;tb_wr_en=0;tb_din=32'h0000_0000;
		
		#STEP
		#2 tb_reset_n=1;
		#8
		#2 tb_rd_en=1;
		#8 
		
		#2 tb_rd_en=0;tb_wr_en=1; tb_din=32'h0000_0011;
		#8 
		//data_count=1->wr_ack
		//head=1, tail=1
		
		#2 tb_din=32'h0000_0022;
		#8 
		//data_count=2->wr_ack
		//head=1, tail=2
		
		#2 tb_din=32'h0000_0033;
		#8 
		//data_count=3->wr_ack
		//head=1, tail=3
		
		#2 tb_din=32'h0000_0044;
		#8 
		//data_count=4->wr_ack
		//head=1, tail=4
		
		#2 tb_din=32'h0000_0055;
		#8 
		//data_count=5->wr_ack
		//head=1, tail=5
		
		
		#2  tb_din=32'h0000_0066;
		#8
		//data_count=6->wr_ack
		//head=1, tail=6
		
		#2 tb_din=32'h0000_0077;
		#8 
		//data_count=7->wr_ack
		//head=1, tail=7
		
		
		#2 tb_din=32'h0000_0088;
		#8 
		//data_count=8  -----full ->wr_ack
		//head=1, tail=8
		
		#2 tb_din=32'h0000_0099;
		#8 
		//data_count=8   ----full -> wr_err
		//head=1, tail=8
		
		#2 tb_din=32'h0000_00aa;
		#8
		//data_count=8   ----full -> wr_err
		//head=1, tail=8
	
		#2 tb_din=32'h0000_00bb;
		#8
			
			
		//data_count=8   ----full -> wr_err=	
		//head=1, tail=8
		
		#2 tb_din=32'h0000_00bb;
		#8
		#2 tb_din=32'h0000_00bb;
		#2 tb_din=32'h0000_0345;
		#8
		#2 
		#8 
		
		#2 tb_wr_en=0;
		#8 
		
		#2 tb_rd_en=1;
		#8
		//data_count=7  ---rd_ack
		//head=2, tail=8
		
		
		#2
		#8
		//data_count=6  ---rd_ack
		//head=3, tail=8
		
		#2 tb_rd_en=0;tb_wr_en=1;
		#8
		//data_count=7  ---wr_ack
		//tb_din=32'h0000_0345
		//head=3, tail=10=1
		
		#2 tb_din=32'h0000_00cc;
		#8
		//data_count=8  ---wr_ack
		//head=3, tail=11=2
		
		#2 tb_rd_en=1;tb_wr_en=0;
		#8
		//data_count=7  ---rd_ack
		//head=4, tail=11=2
		
		
		
		#2
		#8
		//data_count=6  ---rd_ack
		//head=5, tail=11=2
		
		
		#2
		#8
		//data_count=5  ---rd_ack
		//head=6, tail=11=2
		
		
		#2
		#8
		//data_count=4  ---rd_ack
		//head=7, tail=11=2
		
		#2
		#8
		//data_count=3  ---rd_ack
		//head=8, tail=11=2
		
		#2
		#8
		//data_count=2  ---rd_ack
		//head=9, tail=11=2
		
		#2
		#8
		//data_count=1  ---rd_ack
		//head=10=1, tail=11=2
		
		#2
		#8
		//data_count=0  ---rd_ack
		//head=11=2, tail=11=2
		
		#2
		#8
		//data_count=0  ---rd_err
		//head=11=2, tail=11=2
		

		
		
		#10;
		//data_count=0  ---rd_err
		//head=11=2, tail=11=2
		#10;
		#10;
		#10;
		$stop;
	end
	endmodule