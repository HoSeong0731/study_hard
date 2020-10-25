 module fifo(clk, reset_n,rd_en,wr_en,din,dout,data_count,full,empty,wr_ack,wr_err,rd_ack,rd_err);//fifo top module
	input clk, reset_n, rd_en,wr_en;
	input [31:0]din;							//input data ->at write operation
	output [31:0]dout;						//output data ->at read operation
	output full,empty;						//signal (data_count==8 -> full  ,data_count==0 -> empty) 
	output wr_ack,wr_err,rd_ack,rd_err;	//write success = wr_ack, write false = wr_err , read success = rd_ack, read false = rd_err
	output[3:0]data_count;					//data_count
	
	wire [2:0] head, next_head;
	wire [2:0] tail, next_tail;
	wire [2:0] state, next_state;
	wire [3:0] next_data_count;
	wire we,re;
	wire[31:0] to_mux,to_ff;// mux-if signal(re) is 1, input(data) is out to to_ff.
									// to_ff out to output of top module
									
	fifo_ns U0_next_stage_Logic(.wr_en(wr_en),.rd_en(rd_en),.data_count(data_count),.state(state),.next_state(next_state));
	//FSM state logic
	
	fifo_cal U1_Caluculate_Address_Logic(.state(next_state),.data_count(data_count),.head(head),.tail(tail),.re(re),.we(we),.next_data_count(next_data_count),.next_head(next_head),.next_tail(next_tail));
	//calculate next_property. with condition of current state, data_count, re, we.
	
	
	fifo_out U2_Output_Loigc(.state(state),.data_count(data_count),.full(full),.empty(empty),.wr_ack(wr_ack),.wr_err(wr_err),.rd_ack(rd_ack),.rd_err(rd_err));
	// output logic. 
	
	//flip-flop of state, data_count, head, tail
	_dff3_r U3_state(.clk(clk),.reset_n(reset_n),.d(next_state),.q(state));
	_dff4_r U4_data_count(.clk(clk),.reset_n(reset_n),.d(next_data_count),.q(data_count));
	_dff3_r U5_head(.clk(clk),.reset_n(reset_n),.d(next_head),.q(head));
	_dff3_r U6_tail(.clk(clk),.reset_n(reset_n),.d(next_tail),.q(tail));

	//register_file to write, read operation
	Register_file U7_Register_file(.clk(clk),.reset_n(reset_n),.wAddr(tail),.wData(din),.we(we),.rAddr(head),.rData(to_mux));

	//mux. if 're' is 1, to_mux out to to_ff
	mx2_32bits U8_mx2_32bits(.d0(32'b0),.d1(to_mux),.s(re),.y(to_ff));
	
	//last output to dout.      reset_n is 0,do not out to dout
	_dff32_r U9_dout(.clk(clk),.reset_n(reset_n),.d(to_ff),.q(dout));
	
	endmodule
	

	