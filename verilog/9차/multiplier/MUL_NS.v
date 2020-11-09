module MUL_NS(counter, clk, reset_n, state, op_start,op_clear,op_done);
	parameter	IDLE	=	2'b000;					//parameter by state
	parameter 	EXEC	=	2'b001;
	parameter	DONE	=	2'b010;
	
	input		clk, reset_n;							//input List
	input		op_start, op_clear, op_done;
	output reg	[1:0] state;						//output List
	output reg 	[6:0] counter;
	reg [1:0] next_state;							//reg List
	reg [6:0] next_counter;
	reg [6:0] temp;
	wire [7:0] temp_counter;						//wire List
	wire co;
															//CLA instance to raise counter
	cla8 UP(.a({1'b0,next_counter}), .b(8'b1), .ci(1'b0), .s(temp_counter), .co(co));
	
	always @ (posedge clk or negedge reset_n)	//Sequential to change counter value when clk jumps 
	begin
	if(!reset_n) temp = 7'b0;
	else temp = temp_counter[6:0]; 				//Results calculated as CLA are put in reg called temp
	end
	
	always @ (posedge clk or negedge reset_n)	//if clk is posedge => change state and counter
	begin
		if(!reset_n) 
		begin
		state <= IDLE;									//if reset = 0 => idle
		counter = 7'b0000000;						//counter = 0
		end
		else												//else
		begin
		state <= next_state;							//state => next_state
		counter <= next_counter;					//counter => next counter
		end
	end
															//combinational
	always @ (counter, state, op_start, op_clear, op_done, temp)
	begin
	if(op_clear)										//if clear = 1
	begin
		next_state <= IDLE;							//next state => IDLE
		next_counter <= 7'b0;						//counter = 0
	end
	else
	begin
		case(state)										
		IDLE : begin									//IDLE start
			if(op_start && !op_clear && !op_done)
			begin
			next_state <= EXEC;						//next state => EXEC
			next_counter <= counter;				//next counter => counter
			end
			else 											//elxe		
			begin
			next_state <= IDLE;						//next state => IDLE
			next_counter <= counter;				//next counter = 0
			end
		end
		EXEC : begin									//EXEC start
			if(counter == 7'b1000000) 				//if counter == full
			begin
			next_state <= DONE;						//next state => DONE
			next_counter <= counter;				//next counter => counter
			end
			else if(op_clear)							//if op clear = 1
			begin
			next_state <= IDLE;						//next state => IDLE
			next_counter <= 7'b0000000;			//next counter = 0
			end
			else 											//else op clear = 0
			begin
			next_state <= EXEC;						//next state => EXEC
			next_counter = temp;						//next counter = temp(result)
			end
		end
		DONE : begin									//DONE start
			if(op_clear) 								//if op clear = 1
			begin
			next_state <= IDLE;						//next state => IDLE
			next_counter <= 7'b0000000;			//next counter = 0
			end
			else 											//else op clear = 0
			begin
			next_state <= DONE;						//next state => DONE
			next_counter <= counter;				//next counter = counter
			end
		end
		default : 
		begin												//default
		next_state = 2'bx;
		next_counter =7'bx;
		end
		endcase
	end	
	end
endmodule
