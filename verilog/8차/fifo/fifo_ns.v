
// next_state logic
 module fifo_ns(wr_en,rd_en,data_count,state,next_state);
	input wr_en;
	input rd_en;				//input signal wr_en--write, rd_en--read 
	input [3:0]data_count;
	input[2:0]state;
									//current data_count, state
	output reg[2:0]next_state;
									//next state
	
	
	parameter INIT = 3'b000;
	parameter WRITE = 3'b001;
	parameter READ = 3'b010;
	parameter WR_ERROR = 3'b011;
	parameter RD_ERROR= 3'b100;
	parameter NO_OP = 3'b101; 
	
	
	//conditional logic
	//FSM
	always@(state,wr_en,rd_en,data_count)
		begin
		case(state)
			INIT:begin
					if(wr_en==1'b1&&rd_en==1'b0&&data_count==4'b1000)next_state=WR_ERROR;
					else if(wr_en==1'b0&&rd_en==1'b1&&data_count==4'b0000)next_state=RD_ERROR;
					else next_state=NO_OP;
					end
				  
			WRITE:begin
					if(wr_en==1'b0&&rd_en==1'b0)next_state=NO_OP;
					else if(wr_en==1'b0&&rd_en==1'b1&&data_count>4'b0000)next_state=READ;
					else if(wr_en==1'b1&&rd_en==1'b0&&data_count==4'b1000)next_state=WR_ERROR;//WRITE operation but data_count is 8. -->full
					else next_state=state;
					end
					
			READ:begin
					if(wr_en==1'b0&&rd_en==1'b0)next_state=NO_OP;
					else if(wr_en==1'b1&&rd_en==1'b0&&data_count<4'b1000)next_state=WRITE;
					else if(wr_en==1'b0&&rd_en==1'b1&&data_count==4'b0000)next_state=RD_ERROR;//WRITE operation but data_count is 0. -->empty
					else next_state=state;
					end
					
			WR_ERROR:begin			//full
					if(wr_en==1'b0&&rd_en==1'b0)next_state=NO_OP;
					else if(wr_en==1'b0&&rd_en==1'b1&&data_count>4'b0000)next_state=READ;
					else next_state=state;
					end

			RD_ERROR:begin			//empty
					if(wr_en==1'b0&&rd_en==1'b0)next_state=NO_OP;
					else if(wr_en==1'b1&&rd_en==1'b0&&data_count<4'b1000)next_state=WRITE;
					else next_state=state;
					end
			
			NO_OP:begin
					if(wr_en==1'b0&&rd_en==1'b1&&data_count==4'b0000)next_state=RD_ERROR;
					else if(wr_en==1'b1&&rd_en==1'b0&&data_count==4'b1000)next_state=WR_ERROR;
					else if(wr_en==1'b1&&rd_en==1'b0&&data_count<4'b1000)next_state=WRITE;
					else if(wr_en==1'b0&&rd_en==1'b1&&data_count>4'b0000)next_state=READ;
					end
			
			default 
					next_state=3'bx;
					
		endcase
	end
endmodule