module MUL(clk,reset_n,multiplier,multiplicand,op_start,op_clear,op_done,MUL_result);
	input clk, reset_n;
	input [31:0] multiplier,multiplicand;
	input op_start,op_clear;		//input List
	output op_done ;
	output [63:0] MUL_result;		//output List
	
	wire [5:0] co;						// wire List
	wire [1:0] state;
	wire [63:0] sub, add;
											//next state logic instance
	
	MUL_NS U0(.counter(co), .clk(clk), .reset_n(reset_n), .state(state), .op_start(op_start),
					.op_clear(op_clear),.op_done(op_done));
					
					
					
											//output logic insatnce
	MUL_OUT U1(.clk(clk), .reset_n(reset_n),.multiplier(multiplier), .multiplicand(multiplicand), .counter(co), .state(state),
						.op_done(op_done),.result(MUL_result));
	
	
endmodule

//--------------------------------make Multiplier next state----------------------------------

module MUL_NS(counter, clk, reset_n, state, op_start,op_clear,op_done);
	parameter	IDLE	=	2'b00;					//parameter by state
	parameter 	EXEC	=	2'b01;
	parameter	DONE	=	2'b10;
	
	input		clk, reset_n;							//input List
	input		op_start, op_clear, op_done;
	output reg	[1:0] state;						//output List
	output reg 	[5:0] counter;
	reg [1:0] next_state;							//reg List
	reg [5:0] next_counter;
	reg [5:0] temp;
	wire [6:0] temp_counter;						//wire List
	wire co;
															//CLA instance to raise counter
	cla8 UP(.a({2'b00,next_counter}), .b(8'b1), .ci(1'b0), .s(temp_counter), .co(co));	//need resave
	
	always @ (posedge clk or negedge reset_n)	//Sequential to change counter value when clk jumps 
	begin
	if(!reset_n) temp = 5'b0;
	else temp = temp_counter[5:0]; 				//Results calculated as CLA are put in reg called temp
	end
	
	always @ (posedge clk or negedge reset_n)	//if clk is posedge => change state and counter
	begin
		if(!reset_n) 
		begin
		state <= IDLE;									//if reset = 0 => idle
		counter = 6'b000000;							//counter = 0
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
		next_counter <= 6'b0;						//counter = 0
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
			else 											//else		
			begin
			next_state <= IDLE;						//next state => IDLE
			next_counter <= counter;				//next counter = 0
			end
		end
		EXEC : begin									//EXEC start
			if(counter == 6'b100000) 				//if counter == full
			begin
			next_state <= DONE;						//next state => DONE
			next_counter <= counter;				//next counter => counter
			end
			else if(op_clear)							//if op clear = 1
			begin
			next_state <= IDLE;						//next state => IDLE
			next_counter <= 6'b000000;				//next counter = 0
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
			next_counter <= 6'b000000;				//next counter = 0
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
		next_counter =6'bx;
		end
		endcase
	end	
	end
endmodule

//--------------------------------make Multiplier Output----------------------------------

module MUL_OUT(clk, reset_n, multiplier, multiplicand, counter, state, op_done, result);
	parameter	IDLE	=	2'b000;
	parameter 	EXEC	=	2'b001;
	parameter	DONE	=	2'b010;							//parameter
	input clk, reset_n;
	input [31:0] multiplier, multiplicand;
	input [5:0] counter;
	input [1:0] state;										//input list
	wire [31:0] sub, add;									//wire list
	output reg op_done;
	output reg [63:0] result;								//output list
	
	reg [63:0] temp;											//reg list
	reg [31:0] ad1, su1;
	reg [63:0] next_result;
	reg result_behind;
																	//cla64 instnce to compute addition and subtraction in the process of creating results
	cla32 ADD(.a(next_result[63:32]), .b(multiplicand[31:0]), .ci(1'b0), .s(add), .co());
	cla32 SUB(.a(next_result[63:32]), .b(~multiplicand[31:0]), .ci(1'b1), .s(sub), .co());
	
	always @ (posedge clk or negedge reset_n)			//Insert the calculation result into reg according to clk.
	begin
	if(!reset_n) 
		begin
		ad1 = 32'b0;
		su1 = 32'b0;
		end
	else
		ad1 = add;
		su1 = sub;
	end
	
	
	always @ (posedge clk or negedge reset_n)			//Next_result to result according to clk
	begin
		if(!reset_n) result = 64'b0;
		else result <= next_result;
	end
																	//combinational circuit for creating result values
	always @ (multiplier,multiplicand, temp, next_result, result_behind, result, su1,ad1, counter, state)
	begin
	case(state)
		IDLE : begin
		next_result = {32'b0,multiplier};				//In case of IDLE, reset 64 bits to multiplier
		op_done = 0;											//setting 0
		result_behind = 0;
		temp = 64'b0;
		end
		DONE : begin											//In case of DONE done state is 1, else 0
		next_result = result;
		op_done = 1;
		result_behind = 0;
		temp = 64'b0;
		end
		
		EXEC : begin
		if(counter == 6'b100000)							//if calculate is DONE
		begin
		op_done = 1;											//DONE = 1 state => DONE
		next_result = result;								//next_result => result
		result_behind = 0;									//else 0
		temp = 64'b0;
		end
		else														//if calculate is not DONE
		begin
		op_done = 0;											//DONE = 0 state => STATE
		if(result[0] == 0 && result_behind == 0)		//if 00
		begin
		temp = result;											//temp = result 
		result_behind = result[0];							//result behind = result[0]
		next_result= {result[63],result[63:1]};		//shift!
		end
		else if(result[0] == 1 && result_behind == 0)//else if result = ??????...??10 
		begin
		temp[63:32] = su1;									//temp[127:64] = sub[64]
		temp[32:0] = result[32:0];							//temp[63:0] = result[64]
		result_behind = result[0];							//result behind= result[0]
		next_result= {temp[63],temp[63:1]};				//shift!
		end
		else if(result[0]==0 && result_behind== 1)	//else if 01
		begin
		temp[63:32] = ad1;									//temp[127:64] = add[64]
		temp[31:0] = result[31:0];							//temp[63:0] = result[64]
		result_behind = result[0];							//result behind = result[0]
		next_result={temp[63],temp[63:1]};				//shift!
		end
		else if(result[0] == 1 && result_behind == 1)//else if 11 
		begin
		temp = result;											//temp= result
		result_behind = result[0];							//result behind = result
		next_result={result[63],result[63:1]};			//shift!
		end
		else														//else
		begin
		next_result = 64'b0;									//setting 0
		op_done = 1'b0;
		result_behind = 1'b0;
		temp = result;
		end
		end
	end
	
		default : 												//default(setting 0)
		begin
		next_result = 64'b0;
		op_done = 1'b0;
		result_behind = 1'b0;
		temp = result;
		end
	endcase
end
endmodule

	
		