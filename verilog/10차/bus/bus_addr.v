module address_decoder(address,S0_sel,S1_sel);
	input [7:0]address;
	output reg S0_sel,S1_sel;
	
	always@(address)
		begin
			if(address[7:5]==3'b 000)			//upper 3bit 
				{S0_sel,S1_sel}=2'b 10;
			else if(address[7:5]==3'b 001)	//upper 3bit
				{S0_sel,S1_sel}=1'b 01;
			else										//the other case---> not select
				{S0_sel,S1_sel}=3'b 000;
		end
endmodule

module mux3_32bits(d0,d1,d2,s,y);					//32bits mux3 
	input [31:0]d0,d1,d2;
	input [1:0]s;
	output [31:0]y;
	assign y=(s==2'b 00)? d2:(s==2'b 10)? d0:d1;	//s==00 : d2, s==10 : d0, s==01 : d1
endmodule

module mux2_32bits(d0,d1,s,y);						//32bits mux2 
	input [31:0]d0,d1;
	input s;
	output [31:0]y;
  	assign y=(s==0)? d0:d1;								//s=0->d0 / s=1->d1  
endmodule

module mux2_8bits(d0,d1,s,y);							//8bits mux2 
	input [7:0]d0,d1;
	input s;
	output [7:0]y;
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
 input [1:0] d;
 output reg [1:0] q;
 always@(posedge clk or negedge reset_n)			//rising edge clk or flling reset_n
 begin
  if(~reset_n)												//reset when reset_n is falling
   q<=2'b 00;
  else
   q<=d;
 end
endmodule 