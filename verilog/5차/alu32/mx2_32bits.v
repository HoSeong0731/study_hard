module mx2_32bits(d0, d1, s, y);
input [31:0] d0, d1;		//input 32bit do, d1
input s;						//input s
output [31:0] y;			//output 32bit y
assign y=(s==0)?d0:d1;	//y = s? d0:d1
endmodule				