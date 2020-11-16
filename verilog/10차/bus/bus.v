module bus(clk,reset_n,M0_req,M0_wr,M0_address,M0_dout,M1_req,M1_wr,M1_address,M1_dout,S0_dout,S1_dout,M0_grant,M1_grant,M_din,S0_sel,S1_sel,S_address,S_wr,S_din);
	input clk,reset_n;
	input M0_req, M0_wr;			//master request signal, write signal
	input [7:0]M0_address;		//operation adrress
	input [31:0]M0_dout;			//output value
	
	input M1_req,M1_wr;
	input [7:0]M1_address;
	input [31:0]M1_dout;
	
	input [31:0]S0_dout,S1_dout;	//slave output value

	output M0_grant,M1_grant;		//master grant
	output [31:0]M_din;
	
	output S0_sel,S1_sel,S_wr;		//slave select signal , write operation signal
	output [7:0]S_address;			//slave address
	output [31:0]S_din;				//slave input value
	
	
	
	wire [2:0]dff_to_mux3;			// d_flip_flop  -> mux3
	
	//arbiter
	arbiter U0_arbiter(.clk(clk),.reset_n(reset_n),.M0_request(M0_req),.M1_request(M1_req),.M0_grant(M0_grant),.M1_grant(M1_grant));
	
	//mux write signal
	mux2 U1_mx2_wr(.d0(M0_wr),.d1(M1_wr),.s(M1_grant),.y(S_wr));
	
	//mux address 
	mux2_8bits U2_mx2_addr(.d0(M0_address),.d1(M1_address),.s(M1_grant),.y(S_address));
	
	//mux dout
	mux2_32bits U3_mx2_U_dout(.d0(M0_dout),.d1(M1_dout),.s(M1_grant),.y(S_din));
	
	//address_decoder
	address_decoder U4_address_decoder(.address(S_address),.S0_sel(S0_sel),.S1_sel(S1_sel));

	//d - flipflop
	_dff2_r U5_dff2_r(.clk(clk),.reset_n(reset_n),.d({S0_sel,S1_sel}),.q(dff_to_mux3));
	
	//mux3 slave dout
	mux3_32bits U6_mx3_S_dout(.d0(S0_dout),.d1(S1_dout),.d2(0),.s(dff_to_mux3),.y(M_din));


endmodule



