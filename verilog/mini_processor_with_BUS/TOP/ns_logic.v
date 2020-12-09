/*
module ns_logic(state,next_state,Reset_n,s0_sel,S_wr,S_addr,s_din,op_start,opcode,op_done, intterupt, we);
	input Reset_n, s0_sel, S_wr, op_start, op_done, s_din, we;
	input [15:0] S_addr;
	input [3:0] opcode;
	
	input [2:0] state;				//input 3bit state
	output reg [2:0] next_state;	//output reg 3bit next_state
	
	reg [3:0] count;
	reg [3:0] next_count;
	reg next_op_start;
	output intterupt;
	
	parameter INIT_STATE = 3'b000;
	parameter READ_WRITE_STATE = 3'b001;
	parameter EXEC_STATE = 3'b010;
	parameter MUL_STATE = 3'b011;
	parameter IDLE_STATE = 3'b100;
	parameter INT_STATE = 3'b101; 	//make the case with parameter
	parameter END_STATE = 3'b110;
	
	always@(posedge clk or negedge Reset_n)
	begin
		if(!Reset_n)
			state = INIT_STATE;
		else
			state = next_state;
			count = next_count;
			op_start = next_op_start;
	end
	
	
	
	always@(state) 		//control the movement.
		begin

			case(state)
			
			INIT_STATE :
			begin
				if(!Reset_n)
					next_state = INIT_STATE;
				else if (Reset_n)
					next_state = READ_WRITE_STATE;
				else
					next_state = 3'bxxx;
			end
			
			READ_WRITE_STATE :
			begin
				if(s0_sel == 1 && S_wr == 1 && S_addr == 16'h0120 && s_din==1)
					next_state = EXEC_STATE;
				else if(s0_sel == 1 && S_wr == 1 && S_addr == 16'h0120 && s_din == 0)
					next_state = IDLE_STATE;
				else
					next_state=3'bxxx;
			end
 
			EXEC_STATE :
			begin
				if(opcode == 4'b1000)
					next_state = MUL_STATE;
				else if(op_start == 0)
					next_state = IDLE_STATE;
				else if(next_count == 10)
					next_state = INT_STATE;
				else
					next_state=3'bxxx;
			end	
			 
			MUL_STATE :
			begin
				if(op_start == 0)
					next_state = IDLE_STATE;
				else if(op_done == 1)
					next_state = EXEC_STATE;
				else if(op_done == 1 && next_count == 10)
					next_state = INT_STATE;
				else
					next_state=3'bxxx;
			end
			 
			IDLE_STATE :
			begin
				if(op_start == 1)
					next_state = EXEC_STATE;
				else
					next_state = IDLE_STATE;
			end

			INT_STATE : 
			begin
			if(intterupt == 1)
				next_state = END_STATE;
			else
				next_state = INT_STATE;
			end
			
			END_STATE : 
			begin
				next_state = END_STATE;
			end

			endcase
		end
		
		
		
		
		
		
	
	
	always@(state) 		//control the movement.
		begin	
		case(state)
			INIT_STATE : begin
				we <= 1'b0;
				
			end
			
			READ_WRITE_STATE : begin
			
			end
			
			EXEC_STATE : begin
			
			end
			
			MUL_STATE : begin
			
			end
			
			IDLE_STATE : begin
			
			end
			
			INT_STATE : begin
			
			end
			
			END_STATE : begin
			
			end

		endcase
		end
		
endmodule
*/