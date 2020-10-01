`timescale 1ns/100ps	//unit: 1ns, precision: 100ps
module tb_ha;			//start test bench of half adder
reg a;					// reg a = input a of ha
reg b;					// reg b = input b of ha
wire s;					// wire s = output s of ha
wire co;					// wire co = output co of ha
ha U0_ha(.a(a), .b(b), .s(s),.co(co)); //load module half adder
initial			//start test bench
begin
a=1'b0; b=1'b0;		// input a = 0, b = 1 0~10
#10 a=1'b0; b=1'b1;	// input a = 0, b = 1 10~20
#10 a=1'b1; b=1'b0;	// input a = 1, b = 0 20~30
#10 a=1'b1; b=1'b1;	// input a = 1, b = 1 30~40
#10 $stop;				// tb is 30~40 (see a = 1, b = 1)
end						// end test bench
endmodule				// end test bench of half adder
