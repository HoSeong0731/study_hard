`timescale 1ns/100ps	//unit: 1ns, precision: 100ps	
module tb_fa;			//start test bench of full adder
reg a, b, ci;			//reg a = input a of full adder, b = input b of full adder, ci = input carry in of full adder
wire s, co;				//reg s = output Sum of full adder, c = Carry out of full adder
fa U0_fa(.a(a), .b(b), .ci(ci), .s(s), .co(co));	//load module full adder
initial					//start test bench
begin		
ci=1'b0; a=1'b0; b=1'b0;		//input a = 0, b = 0, carry in = 0
#10 ci=1'b1; a=1'b0; b=1'b0;	//input a = 0, b = 0, carry in = 1
#10 ci=1'b0; a=1'b0; b=1'b1;	//input a = 0, b = 1, carry in = 0
#10 ci=1'b1; a=1'b0; b=1'b1;  //input a = 0, b = 1, carry in = 1
#10 ci=1'b0; a=1'b1; b=1'b0;	//input a = 1, b = 0, carry in = 0
#10 ci=1'b1; a=1'b1; b=1'b0; 	//input a = 1, b = 0, carry in = 1
#10 ci=1'b0; a=1'b1; b=1'b1;	//input a = 1, b = 1, carry in = 0
#10 ci=1'b1; a=1'b1; b=1'b1;	//input a = 1, b = 1, carry in = 1
#10 $stop;							//tb is70~80 (see a = 1, b = 1, carry in = 1)
end									// end test bench
endmodule							// end test bench of full adder
