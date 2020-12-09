module BUS(	clk,reset_n,m_req,m_wr,m_addr,m_dout,S_dout,m_grant,m_din,s_sel,s_addr,s_wr,s_din);

	input clk,reset_n;
	input m_req, m_wr;			//master request signal, write signal
	input [15:0]m_addr;			//operation adrress
	input [31:0]m_dout;			//output value
	input [63:0]S_dout;			//slave output value

	output m_grant;				//master grant
	output [63:0]m_din;
	
	output s_sel,s_wr;			//slave select signal , write operation signal
	output [15:0]s_addr;			//slave address
	output [63:0]s_din;			//slave input value
	
	
	
	wire [7:0] upper;

	assign m_grant = m_req;
	assign s_wr = m_wr;
	assign s_addr = m_addr;
	assign s_din = m_dout;
	assign m_din = S_dout;
	assign upper = m_addr[15:8];
	assign s_sel = (upper == 8'h01)? 1'b1 : 1'b0;
	
endmodule

/*
//aribiter
module arbiter(clk, reset_n, m_req, m_grant);
	input clk,reset_n;
	input m_req;				//master request
	
	output reg m_grant;		//master grant
	
	reg next_M_grant;			//next_master grant
	
	always@(posedge clk)
	begin
		m_grant = next_M_grant;
	end
	
	always@(reset_n,m_req)
		begin
		if(reset_n==0)						// initialize --> M0--grant
			begin
				next_M_grant = 1;
			end
		
		else if(reset_n==1)
			begin
				case(m_req)
					1'b 1:begin			//when m_req = 1
								next_M_grant = 1;
							end
					1'b 0:begin			//when m_req = 0
								next_M_grant = 0;
							end
				endcase
			end
		
		end
endmodule

//decoder
module address_decoder(address, s_sel);
	input [7:0]address;
	output reg s_sel;
	
	always@(address)
		begin
			if(address==8'b 0000_0001)			//upper 8bit 
				s_sel = 1;
			else										//the other case---> not select
				s_sel = 0;
		end
endmodule

module mux2_32bits(d0,d1,s,y);						//32bits mux2 
	input [31:0]d0,d1;
	input s;
	output [31:0]y;
  	assign y=(s==0)? d0:d1;								//s=0->d0 / s=1->d1  
endmodule

module mux2_16bits(d0,d1,s,y);							//8bits mux2 
	input [15:0]d0,d1;
	input s;
	output [15:0]y;
	assign y=(s==0)? d0:d1;								//s=0->d0 / s=1->d1
endmodule

module mux2(d0,d1,s,y);									//2bits mux2 
	input d0,d1;
	input s;
	output y;
	assign y=(s==0)? d0:d1;								//s=0->d0 / s=1->d1
endmodule

module _dff2_r(clk,reset_n,d,q);						//resetable d flip-flop
 input clk,reset_n;
 input d;
 output reg q;
 always@(posedge clk or negedge reset_n)			//rising edge clk or flling reset_n
 begin
  if(~reset_n)												//reset when reset_n is falling
   q<=1'b 0;
  else
   q<=d;
 end
endmodule 

*/

