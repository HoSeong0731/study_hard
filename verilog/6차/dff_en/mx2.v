module mx2(d0, d1, s, y); //2 input mux
input		d0, d1;
input		s;
output	y;
wire	sb, w0, w1;

_inv U0_inv(.a(s), .y(sb));
_nand2 U1_nand2(.a(sb), .b(d0), .y(w0));
_nand2 U2_nand2(.a(s), .b(d1), .y(w1));
_nand2 U3_nand2(.a(w0), .b(w1), .y(y));

endmodule
