module rca(a,b,ci,s,co);	//start ripple carry adder
input [3:0] a,b;				//input a and b(4bit)
input ci;						//input carry in(1bit)
output [3:0] s;				//output sum(4bit)
output co;						//output carry out(1bit)
wire [2:0] c;					//create wire c
fa U0_fa(.a(a[0]), .b(b[0]), .ci(ci), .s(s[0]),.co(c[0]));		//load module full adder
fa U1_fa(.a(a[1]), .b(b[1]), .ci(c[0]),.s(s[1]), .co(c[1]));	//load module full adder
fa U2_fa(.a(a[2]), .b(b[2]), .ci(c[1]), .s(s[2]), .co(c[2]));	//load module full adder
fa U3_fa(.a(a[3]), .b(b[3]), .ci(c[2]), .s(s[3]), .co(co));		//load module full adder
endmodule						//end ripple carry adder
