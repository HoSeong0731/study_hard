module cc_logic(op, shamt, d_in, d_out, d_next);
	input	[2:0]	op;			//input 3bit op
	input	[1:0]	shamt;		//input 2bit shmat
	input	[7:0]	d_in;		//input 8bit d_in 
	input	[7:0]	d_out;		//input 8bit d_out
	output[7:0]	d_next;			//output 8bit d_next
	reg [7:0] d_next;			//reg 8bit d_next

	wire [7:0] d_lsl;			//wire 8bit d_lsl
	wire [7:0] d_lsr;			//wire 8bir d_lsr
	wire [7:0] d_asr;			//wire 8bit d_asr
		
	parameter NOP 	= 3'b000;	//set the opcode with the parameter.
	parameter LOAD = 3'b001;
	parameter LSL 	= 3'b010;
	parameter LSR	= 3'b011;
	parameter ASR	= 3'b100;
		
	always @ (op, shamt, d_in, d_out, d_lsl, d_lsr, d_asr)		//always opearte
		begin
			case(op)
			NOP		:	d_next = d_out;
			LOAD		:	d_next = d_in;	
			LSL		:	d_next = d_lsl;
			LSR		:	d_next = d_lsr;
			ASR		:	d_next = d_asr;	
			default	:	d_next = 8'bx;	
			endcase
		end

	LSL8 U0_LSL8(.d_in(d_out), .shamt(shamt), .d_out(d_lsl));	//instance LSL8
	LSR8 U1_LSR8(.d_in(d_out), .shamt(shamt), .d_out(d_lsr));	//instance LSR8
	ASR8 U2_ASR8(.d_in(d_out), .shamt(shamt), .d_out(d_asr));	//instance ASR8
	
endmodule