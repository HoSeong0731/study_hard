
//output logic
 module fifo_out(state,data_count,full,empty,wr_ack,wr_err,rd_ack,rd_err);
	parameter INIT=3'b000;
	parameter WRITE=3'b001;
	parameter READ=3'b010;
	parameter WR_ERROR =3'b011;
	parameter RD_ERROR=3'b100;
	parameter NO_OP = 3'b101;
	
	input [2:0]state;
	input [3:0]data_count;
	//current state,next data_count.
	
	output reg full,empty;
	output reg wr_ack,wr_err,rd_ack,rd_err;


	
	
	always @(state,data_count)
	begin
	case(state)
		INIT: begin
			if(data_count==4'b0000) begin	//it's input state is IDLE, but it can be WRITE or READ state data_count.
				full<=0;empty<=1;//empty  	//so it divide two condition
				wr_ack<=0;wr_err<=0;
				rd_ack<=0;rd_err<=0;
			end
			
			else begin
				full<=0;empty<=0;
				wr_ack<=0;wr_err<=0;
				rd_ack<=0;rd_err<=0;
			end
			
		end
		
		
		WRITE: begin
		if(data_count==4'b1000) begin		//full
			full<=1;empty<=0;
			wr_ack<=1;wr_err<=0;
			rd_ack<=0;rd_err<=0;
		end
		
		else begin								//write success
			full<=0;empty<=0;
			wr_ack<=1;wr_err<=0;
			rd_ack<=0;rd_err<=0;
		end
		
		end
		
		
		READ:begin
		if(data_count==4'b0000) begin		//empty
			full<=0;empty<=1;
			wr_ack<=0;wr_err<=0;
			rd_ack<=1;rd_err<=0;
		end
		
		else begin
			full<=0;empty<=0;					//read success
			wr_ack<=0;wr_err<=0;
			rd_ack<=1;rd_err<=0;
		end
		
		end
		
		
		WR_ERROR:begin	
			full<=1;empty<=0;					//full
			wr_ack<=0;wr_err<=1;
			rd_ack<=0;rd_err<=0;
			end
			
			
		RD_ERROR:begin
			full<=0;empty<=1;					//empty
			wr_ack<=0;wr_err<=0;
			rd_ack<=0;rd_err<=1;
			end
			
			
		NO_OP:begin
		if(data_count==4'b0000) begin		//empty
			full<=0;empty<=1;
			wr_ack<=0;wr_err<=0;
			rd_ack<=0;rd_err<=1;
		end
			
		if(data_count==4'b1000) begin		//full
			full<=1;empty<=0;
			wr_ack<=0;wr_err<=1;
			rd_ack<=0;rd_err<=0;
		end
		
			end
	
	endcase
	
end
	
endmodule
