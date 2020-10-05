module alu4(a, b, op, result, c, n, z, v);
input [3:0] a, b;			//input 4bit a, b
input [2:0] op;			//input 3bit op
output [3:0] result;		//output 4bit result
output c, n, z, v;		//output c, n, z, v


wire [3:0] w_not_a,w_not_b, w_and, w_or, w_xor, w_xnor, w_add, w_sub;	//wire 4bit operations
wire c3_add, co_add, c3_sub, co_sub;												//wire 1bit operations
_inv_4bits U0_inv_4bits (.a(a), .y(w_not_a));									//load module 4bit not gate
_inv_4bits U1_inv_4bits (.a(b), .y(w_not_b));									//load module 4bit not gate
_and2_4bits U2_and2_4bits (.a(a), .b(b), .y(w_and));							//load module 4bit 2input and gate
_or2_4bits U3_or2_4bits (.a(a), .b(b), .y(w_or));								//load module 4bit 2input or gate
_xor2_4bits U4_xor2_4bits (.a(a), .b(b), .y(w_xor));							//load module 4bit 2input xor gate
_xnor2_4bits U5_xnor2_4bits (.a(a), .b(b), .y(w_xnor));						//load module 4bit 2input xnor gate
cla4_ov U6_add (.a(a), .b(b), .ci(1'b0), .s(w_add), .c3(c3_add), .co(co_add));		//load module add operation
cla4_ov U7_sub (.a(a), .b(w_not_b), .ci(1'b1), .s(w_sub), .c3(c3_sub), .co(co_sub));//load module syb operation(= and operation(A +(-B))
mx8_4bits U8_mx8_4bits (.a(w_not_a), .b(w_not_b), .c(w_and), .d(w_or), .e(w_xor), .f(w_xnor),.g(w_add), .h(w_sub), .s2(op[2]), .s1(op[1]), .s0(op[0]), .y(result));
//decoder: it will be selected by each operation
cal_flags4 U9_cal_flags4 (.op(op), .result(result), .co_add(co_add), .c3_add(c3_add),.co_sub(co_sub), .c3_sub(c3_sub),.c(c), .n(n), .z(z), .v(v));
//calculate conditional register
endmodule