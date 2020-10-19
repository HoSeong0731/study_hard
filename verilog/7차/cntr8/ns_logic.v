module ns_logic(load,inc,state,next_state); 
	input load,inc;					//input load, inc	
	input [2:0] state;				//input 3bit state
	output reg [2:0] next_state;	//output reg 3bit next_state
	
	parameter IDLE_STATE = 3'b000;
	parameter LOAD_STATE = 3'b001;
	parameter INC_STATE = 3'b010;
	parameter INC2_STATE = 3'b011;
	parameter DEC_STATE = 3'b100;
	parameter DEC2_STATE = 3'b101; 	//make the case with parameter

	always@(load,inc,state) 		//control the movement.
		begin
			case(state)
			
			IDLE_STATE :
			begin
				if(load==1)	
					next_state=LOAD_STATE;
				else if(inc==1)
					next_state=INC_STATE;
				else if(inc==0)
					next_state=DEC_STATE;
				else	
					next_state=3'bxxx; //exception control
			end
			
			LOAD_STATE :
			begin
				if(load==1)
					next_state=LOAD_STATE;
				else if(inc==1)
					next_state=INC_STATE;
				else if(inc==0)
					next_state=DEC_STATE;
				else
					next_state=3'bxxx; //exception control
				end
 
			INC_STATE :
			begin
				if(load==1)	
					next_state=LOAD_STATE;
				else if(inc==1)
					next_state=INC2_STATE;
				else if(inc==0)
					next_state=DEC_STATE;
				else
					next_state=3'bxxx; //exception control
			end	
			 
			INC2_STATE :
			begin
				if(load==1)	
					next_state=LOAD_STATE;
				else if(inc==1)
					next_state=INC_STATE;
				else if(inc==0)
					next_state=DEC_STATE; 
				else
					next_state=3'bxxx; //exception control
				end
			 
			DEC_STATE :
			begin
				if(load==1)
					next_state=LOAD_STATE;
			else if(inc==1)
				next_state=INC_STATE;
			else if(inc==0)	
				next_state=DEC2_STATE;
			else
				next_state=3'bxxx; //exception control
			end

			DEC2_STATE : 
			begin
				if(load==1)	
					next_state=LOAD_STATE;
				else if(inc==1)
					next_state=INC_STATE;
				else if(inc==0)
					next_state=DEC_STATE;
				else
					next_state=3'bxxx; //exception control
				end

			endcase
		end

endmodule
