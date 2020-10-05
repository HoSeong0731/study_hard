module alu32(a, b, op, result, c, n, z, v);
input [31:0] a, b;		//input 32bit a, b
input [2:0] op;			//input 3bit operation
output [31:0] result;	//32bit result
output c, n, z, v;		//output condition register
wire [31:0] w_not_a, w_not_b, w_and, w_or, w_xor, w_xnor, w_add, w_sub;	//wire logic
wire co_prev_add, co_add, co_prev_sub, co_sub;									//wire Add, Sub
_inv_32bits U0_inv_32bits (.a(a), .y(w_not_a));									//load 32bit not gate
_inv_32bits U1_inv_32bits (.a(b), .y(w_not_b));									//load 32bit not gate
_and2_32bits U2_and2_32bits (.a(a), .b(b), .y(w_and));						//load 32bit 2input and gate
_or2_32bits U3_or2_32bits (.a(a), .b(b), .y(w_or));							//load 32bit 2input or gate
_xor2_32bits U4_xor2_32bits (.a(a), .b(b), .y(w_xor));						//load 32bit 2input xor gate
_xnor2_32bits U5_xnor2_32bits (.a(a), .b(b), .y(w_xnor));					//load 32bit 2input xnor gate
cla32_ov U6_add (.a(a), .b(b), .ci(1'b0), .s(w_add), .co_prev(co_prev_add), .co(co_add));			//load 32bit add
cla32_ov U7_sub (.a(a), .b(w_not_b), .ci(1'b1), .s(w_sub), .co_prev(co_prev_sub), .co(co_sub));	//load 32bit sub(A + (-B))
mx8_32bits U8_mx8_32bits (.y(result), .a(w_not_a), .b(w_not_b), .c(w_and), .d(w_or), .e(w_xor),.f(w_xnor), .g(w_add), .h(w_sub), .s2(op[2]), .s1(op[1]), .s0(op[0]));
//load 32bit mux8
cal_flags32 U9_cal_flags32(.op(op), .result(result),.co_add(co_add), .co_prev_add(co_prev_add),.co_sub(co_sub), .co_prev_sub(co_prev_sub),.c(c), .n(n), .z(z), .v(v));
//load condition register calculate
endmodule
