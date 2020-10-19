module mx2(d0, d1, s, y); 
input		d0, d1;     //input d0, d1
input		s;          //input s
output	y;              //output y
wire	sb, w0, w1;     //wire sb, w0, w1

_inv U0_inv(.a(s), .y(sb));                 //load invertor
_nand2 U1_nand2(.a(sb), .b(d0), .y(w0));    //load 2 input nand gate
_nand2 U2_nand2(.a(s), .b(d1), .y(w1));     //load 2 input nand gate
_nand2 U3_nand2(.a(w0), .b(w1), .y(y));     //load 2 input nand gate

endmodule
