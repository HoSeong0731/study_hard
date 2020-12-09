module MP(Clk, Reset_n, S_wr, S_addr, s_din, s0_sel, s_dout, Interrupt_out, state);

	input Clk, Reset_n, S_wr, s0_sel;
	input [15:0] S_addr;
	input [31:0] s_din;
	output reg [63:0] s_dout;
	output reg Interrupt_out;
	
	wire [31:0]ALU_Result;
	wire [63:0]MUL_Result;
	wire [63:0]INST_REG_DATA, DATA_REG_DATA,DATA_REG_DATA2, CONT_REG_DATA;
	
	reg [3:0] OPcode, Ra, Rb, Rd; 
	reg [15:0] D_W_addr, D_R_addr2, D_R_addr3, I_W_addr, I_R_addr, C_W_addr, C_R_addr;
	reg [63:0] D_W_DATA, I_W_DATA, C_W_DATA;
	reg D_EN, I_EN, C_EN;
	wire [63:0]D_R_DATA, D_R_DATA2, I_R_DATA, C_R_DATA;
	
	reg [31:0] A, B;
	
	reg op_start, op_clear;
	wire op_done;
	
	wire [63:0]SSSSS_dout;
	
	//Register_file_23 U1_RF(.clk(CLK),.reset_n(Reset_n),.wAddr(S_addr),.wData(s_dout),.we(),.rAddr(),.rData());
	
	Register_file_10_D U1_DATA_REG(.clk(Clk), .reset_n(Reset_n), .W_addr(D_W_addr), .R_addr2(D_R_addr2), .R_addr3(D_R_addr3), .wData(D_W_DATA), .we(D_EN), .rData(D_R_DATA), .rData2(D_R_DATA2));
	
	Register_file_10_I U2_INST_REG(.clk(Clk), .reset_n(Reset_n), .W_addr(I_W_addr), .wData(I_W_DATA), .R_addr(I_R_addr),.we(I_EN), .rData(I_R_DATA));
	
	Register_file_3_C U3_CONT_REG(.clk(Clk), .reset_n(Reset_n), .W_addr(C_W_addr), .wData(C_W_DATA), .R_addr(C_R_addr),.we(C_EN), .rData(C_R_DATA));
	
	ALU U4_ALU(.a(A), .b(B), .op(OPcode), .ALU_result(ALU_Result));
	
	//MUL U5_MUL(.clk(Clk),.reset_n(Reset_n),.multiplier(A),.multiplicand(B),.op_start(op_start),.op_clear(op_clear),.op_done(op_done),.MUL_result(MUL_Result));
	
	mx2_64bits U6_result(.d0({32'b0,ALU_Result}), .d1(MUL_Result), .s(OPcode[3]), .y(SSSSS_dout));
	
	
	
	
	
	
	output reg [2:0] state;				//input 3bit state
	reg [2:0] next_state;		//output reg 3bit next_state
	
	reg [3:0] count;
	reg [3:0] next_count;
	reg next_op_start;
	
	
	parameter INIT_STATE = 3'b000;
	parameter READ_WRITE_STATE = 3'b001;
	parameter EXEC_STATE = 3'b010;
	parameter MUL_STATE = 3'b011;
	parameter IDLE_STATE = 3'b100;
	parameter INT_STATE = 3'b101; 	//make the case with parameter
	parameter END_STATE = 3'b110;
	
	always@(posedge Clk or negedge Reset_n)
	begin
		if(!Reset_n)
			state = INIT_STATE;
		else
			state = next_state;
			count = next_count;
			op_start = next_op_start;
	end
	
	
	
	always@(*) 		//control the movement.
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
					next_state=READ_WRITE_STATE;
			end
 
			EXEC_STATE :
			begin
				if(OPcode == 4'b1000)
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
			if(Interrupt_out == 1)
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
		
		
		
		
		
		
	
	
	always@(*) 		//control the movement.
		begin	
		case(state)
			INIT_STATE : begin
				OPcode <= 4'b0;
				Ra <= 4'b0;
				Rb <= 4'b0;
				Rd <= 4'b0;
				D_W_addr <= 0;
				D_R_addr2 <= 0;
				D_R_addr3<= 0;
				I_W_addr<= 0;
				I_R_addr<= 0;
				C_W_addr<= 0;
				C_R_addr<= 0;
				D_W_DATA<= 0;
				I_W_DATA<= 0;
				C_W_DATA<= 0;
				D_EN<= 0;
				I_EN<= 0;
				C_EN<= 0;
				A<= 0;
				B<= 0;
				op_clear<= 0;
			end
			
			READ_WRITE_STATE : begin
				if(!s0_sel)begin
					D_EN = 0;
					I_EN = 0;
					C_EN = 0;
					end
				else if(s0_sel)begin
					if(S_wr)begin
						D_W_addr <= {32'b0,S_addr};
						I_W_addr <= {32'b0,S_addr};
						C_W_addr <= {32'b0,S_addr};
						D_W_DATA <= s_din;
						I_W_DATA <= s_din;
						C_W_DATA <= s_din;
						D_EN <= 1;
						I_EN <= 1;
						C_EN <= 1;
						end
					else begin
						if(S_addr[15:4]==12'h010)begin
						D_R_addr2 <= S_addr;
						s_dout <= D_R_DATA;
						end
						if(S_addr[15:4]==12'h011)begin
						I_R_addr <= S_addr;
						s_dout <= I_R_DATA;
						end
						if(S_addr[15:4]==12'h012)begin
						C_R_addr <= S_addr;
						s_dout <= C_R_DATA;
						end
						end
					end
			end
			
			EXEC_STATE : begin
			/*
				next_count = count + 1'b1;
				I_R_addr = {12'h011, count};
				OPcode = I_R_DATA[15:12];
				Rd = I_R_DATA[11:8];
				Ra = I_R_DATA[7:4];
				Rb = I_R_DATA[3:0];
				D_R_addr2 = {12'h010, Ra};
				D_R_addr3 = {12'h010, Rb};
				D_W_addr = {12'h010, Rd};
				
				A = D_R_DATA;
				B = D_R_DATA2;
				
				op_clear = 1'b1;
				if(OPcode == 4'b1000)begin
					we = 1'b0;
					s_dout = MUL_Result;
					next_op_start = 1'b1;
				end
				
				if(OPcode <= 4'b0111)begin
					s_dout = ALU_Result;
					next_op_start = 1'b1;
				end
*/
					
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

