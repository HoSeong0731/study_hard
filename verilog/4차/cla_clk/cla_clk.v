module cla_clk(clock, a, b, ci, s_cla, co_cla);
input clock;					//input clock
input [31:0] a, b;			//input 32*1 a and b
input ci;						//carry in
output [31:0] s_cla;			//output 32*1 Sum Carry Look Ahead
output co_cla;					//output Carry out Carry Look Ahead
reg [31:0] reg_a, reg_b;	//reg 32*1 a and b
reg reg_ci;						//reg carry in
reg [31:0] reg_s_cla;		//rea sum Carry Look Ahead
reg reg_co_cla;				//reg Carry out Carry Look Ahead
wire [31:0] wire_s_cla;		//wire sum Carry Look Ahead
wire wire_co_cla;				//wire Carry out Carry Look Ahead

always @ (posedge clock)	//only get the variabla at the rising edge.
begin								
reg_a <= a;						//start the content
reg_b <= b;
reg_ci <= ci;
reg_s_cla <= wire_s_cla;
reg_co_cla <= wire_co_cla;	//end the content
end

cla32 U0_cla32(.a(reg_a), .b(reg_b), .ci(reg_ci), .s(wire_s_cla), .co(wire_co_cla));	//load module CLA32
assign s_cla = reg_s_cla;		//y = sum
assign co_cla = reg_co_cla;	//x = carry out
endmodule							//end module