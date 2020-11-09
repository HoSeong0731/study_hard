module MUL_OUT(clk, reset_n, multiplier, multiplicand, counter, state, op_done, result);
	parameter	IDLE	=	2'b000;
	parameter 	EXEC	=	2'b001;
	parameter	DONE	=	2'b010;							//parameter
	input clk, reset_n;
	input [63:0] multiplier, multiplicand;
	input [6:0] counter;
	input [1:0] state;										//input list
	wire [63:0] sub, add;									//wire list
	output reg op_done;
	output reg [127:0] result;								//output list
	
	reg [127:0] temp;											//reg list
	reg [63:0] ad1, su1;
	reg [127:0] next_result;
	reg result_behind;
																	//cla64 instnce to compute addition and subtraction in the process of creating results
	cla64 ADD(.a(next_result[127:64]), .b(multiplicand[63:0]), .ci(1'b0), .s(add), .co());
	cla64 SUB(.a(next_result[127:64]), .b(~multiplicand[63:0]), .ci(1'b1), .s(sub), .co());
	
	always @ (posedge clk or negedge reset_n)			//Insert the calculation result into reg according to clk.
	begin
	if(!reset_n) 
		begin
		ad1 = 64'b0;
		su1 = 64'b0;
		end
	else
		ad1 = add;
		su1 = sub;
	end
	
	
	always @ (posedge clk or negedge reset_n)			//Next_result to result according to clk
	begin
		if(!reset_n) result = 128'b0;
		else result <= next_result;
	end
																	//combinational circuit for creating result values
	always @ (multiplier,multiplicand, temp, next_result, result_behind, result, su1,ad1, counter, state)
	begin
	case(state)
		IDLE : begin
		next_result = {64'b0,multiplier};				//In case of IDLE, reset 64 bits to multiplier
		op_done = 0;											//setting 0
		result_behind = 0;
		temp = 128'b0;
		end
		DONE : begin											//In case of DONE done state is 1, else 0
		next_result = result;
		op_done = 1;
		result_behind = 0;
		temp = 128'b0;
		end
		EXEC : begin
		if(counter == 7'b1000000)							//if calculate is DONE
		begin
		op_done = 1;											//DONE = 1 state => DONE
		next_result = result;								//next_result => result
		result_behind = 0;									//else 0
		temp = 128'b0;
		end
		else														//if calculate is not DONE
		begin
		op_done = 0;											//DONE = 0 state => STATE
		if(result[0] == 0 && result_behind == 0)		//if 00
		begin
		temp = result;											//temp = result 
		result_behind = result[0];							//result behind = result[0]
		next_result= {result[127],result[127:1]};		//shift!
		end
		else if(result[0] == 1 && result_behind == 0)//else if result = ??????...??10 
		begin
		temp[127:64] = su1;									//temp[127:64] = sub[64]
		temp[63:0] = result[63:0];							//temp[63:0] = result[64]
		result_behind = result[0];							//result behind= result[0]
		next_result= {temp[127],temp[127:1]};			//shift!
		end
		else if(result[0]==0 && result_behind== 1)	//else if 01
		begin
		temp[127:64] = ad1;									//temp[127:64] = add[64]
		temp[63:0] = result[63:0];							//temp[63:0] = result[64]
		result_behind = result[0];							//result behind = result[0]
		next_result={temp[127],temp[127:1]};			//shift!
		end
		else if(result[0] == 1 && result_behind == 1)//else if 11 
		begin
		temp = result;											//temp= result
		result_behind = result[0];							//result behind = result
		next_result={result[127],result[127:1]};		//shift!
		end
		else														//else
		begin
		next_result = 128'b0;								//setting 0
		op_done = 1'b0;
		result_behind = 1'b0;
		temp = result;
		end
		end
	end
		default : 												//default(setting 0)
		begin
		next_result = 128'b0;
		op_done = 1'b0;
		result_behind = 1'b0;
		temp = result;
		end
	endcase
end
endmodule

	
		