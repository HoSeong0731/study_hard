module cntr8(clk,reset_n,inc,load,d_in,d_out,o_state);
	input clk,reset_n,inc,load;		//input clk, reset_n, load
	input [7:0] d_in;				//input 8bit d_in
	output [7:0] d_out;				//output 8bit d_out
	output [2:0] o_state;			//output 3bit o_state

	wire [2:0] next_state;			//wire 3bit next_state
	wire [2:0] state;				//wire 3bit state
	assign o_state=state;			// y = state

	//instance _register3_r
	_register3_r U0_reg3r (.clk(clk),.reset_n(reset_n),
								.d(next_state),.q(state));
	//instance ns_logic		
	ns_logic U1_ns_logic  (.load(load),.inc(inc),.state(o_state),
								.next_state(next_state));	
	//instance os_logic							
	os_logic U2_os_logic  (.state(state),.d_in(d_in),
								.d_out(d_out)); 

endmodule

