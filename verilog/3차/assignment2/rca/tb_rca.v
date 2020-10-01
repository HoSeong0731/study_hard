`timescale 1ns/100ps	//unit: 1ns, precision: 100ps	
module tb_rca;			//start test bench of ripple carry adder
reg[3:0] tb_a, tb_b;	//rea tb_a = input a of rca, tb_b = input b of rca
reg tb_ci;				//reg tb_ci = input carry in of rca
wire[3:0] tb_s;		//wire tb_s = output Sum of rca
wire tb_co;				//wire tb_co = output Carry out of rca
wire [4:0] tb_result;//tb_result = tb_co+tb_s
rca U0_rca(.a(tb_a), .b(tb_b), .ci(tb_ci), .s(tb_s), .co(tb_co));	//load module ripple carry adder
initial			//start test bench	
begin
tb_a=4'b0; tb_b=4'b0; tb_ci=0;	// input a = 0, b = 0, carry in = 0
#10; tb_a=4'b0101; tb_b=4'b0100;	//	input a = 5, b = 4, carry in = 0
#10; tb_a=4'b1111; tb_b=4'b1111;	// input a = 15, b = 15, carry in = 0
#10; tb_ci=1;							//	input a = 15, b = 15, carry in = 1
#10; $stop;								// tb is 30~40(see a = 15, b = 15, c = 1)
end										// end
assign tb_result = {tb_co,tb_s};	// result = carry out + Sum
endmodule								// end test bench of ripple carry adder
