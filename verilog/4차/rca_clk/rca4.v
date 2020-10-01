module rca4(a,b,ci,s,co);	//2input
input [3:0] a,b;		//4*1 input a and b
input ci;				//input carry in
output [3:0] s;		//output 4*1 Sum
output co;				//output carry out
wire [2:0] c;			//wire 2*1 c
fa U0_fa(.a(a[0]), .b(b[0]), .ci(ci),.s(s[0]), .co(c[0]));		//load module 1bit full adder
fa U1_fa(.a(a[1]), .b(b[1]), .ci(c[0]),.s(s[1]), .co(c[1]));	//load module 1bit full adder
fa U2_fa(.a(a[2]), .b(b[2]), .ci(c[1]),.s(s[2]), .co(c[2]));	//load module 1bit full adder
fa U3_fa(.a(a[3]), .b(b[3]), .ci(c[2]),.s(s[3]), .co(co));		//load module 1bit full adder
endmodule				//end module
