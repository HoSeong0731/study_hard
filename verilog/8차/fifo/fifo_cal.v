 
 //calculate logic
 module fifo_cal(state,data_count,head,tail,re,we,next_data_count,next_head,next_tail);
	input [2:0]state;
	input [3:0]data_count;
	input [2:0]head,tail;
	//current state, data_count, head, tail
	
	output reg re,we;
	output reg [3:0]next_data_count;
	output reg [2:0]next_head,next_tail;
	//output:  next_data_count, next_head, next_tail
	//         signal we, re
	
	parameter INIT=3'b000;
	parameter WRITE=3'b001;
	parameter READ=3'b010;
	parameter WR_ERROR =3'b011;
	parameter RD_ERROR=3'b100;
	parameter NO_OP = 3'b101;
	
	always@(state,data_count, head,tail)
		begin
		case(state)
			INIT:begin
					next_head<=head;
					next_tail<=tail;
					next_data_count<=data_count;					//reset fsm
					we<=1'b0;
					re<=1'b0;
					end
				
			WRITE:begin
					we<=1;
					re<=0;
					next_data_count<=data_count+4'b0001;		//data_count++
					next_head<=head;
					next_tail<=tail+4'b0001;
					end
					
			READ:begin
					we<=0;
					re<=1;
					next_data_count<=data_count+4'b1111;		//data_count--;
					next_head<=head+4'b0001;
					next_tail<=tail;
					end
				
				
				//WR_ERROR, RD_ERROR : remain current value
			WR_ERROR:begin
					we<=0;
					re<=0;
					next_head<=head;
					next_tail<=tail;
					next_data_count<=data_count;
					end
				
			RD_ERROR:begin
					we<=0;
					re<=0;
					next_head<=head;
					next_tail<=tail;
					next_data_count<=data_count;
					end
				
			NO_OP:begin
					we<=0;
					re<=0;
					next_head<=head;
					next_tail<=tail;
					next_data_count<=data_count;
					end
					
			default:begin
				we=1'bx; re=1'bx; next_data_count=4'bx; next_head=3'bx; next_tail=3'bx;
			end
		endcase
	end
endmodule