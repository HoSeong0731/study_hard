`timescale 1ns/100ps //precision is 100ps, unit 1ns
module tb_mx2;

	reg d0, d1, s;
	wire y;
	
_mx2 U0_mx2(.d0(d0), .d1(d1), .s(s), .y(y));	//load _mx2

initial
begin	//Proceed in order of truth.
	#0		d0 = 0; d1 = 0; s = 0;
	#10	d0 = 1; d1 = 0; s = 0;
	#10	d0 = 0; d1 = 1; s = 0;
	#10	d0 = 1; d1 = 1; s = 0;
	#10	d0 = 0; d1 = 0; s = 1;
	#10	d0 = 1; d1 = 0; s = 1;
	#10	d0 = 0; d1 = 1; s = 1;
	#10	d0 = 1; d1 = 1; s = 1;
	#10;
end
endmodule	//end of module