module cal_flags32(op, result, co_add, co_prev_add, co_sub, co_prev_sub, c, n, z, v);
input [2:0] op;		//input 3bit operation select
input [31:0] result;	//input 32bit result
input co_add, co_prev_add, co_sub, co_prev_sub;	//input carryout_add, carryout_preview_add, carryout_subtract, carryout_preview_subtract
output c, n, z, v;			//output C, N, Z, V
assign c = (op[2:1] != 2'b11) ? 1'b0 : ((op[0] == 1'b0) ? co_add : co_sub );										// C = carry
assign n = result[31];																												// N = negative	
assign z = (result == 32'b0) ? 1'b1 : 1'b0;																					// Z = zero
assign v = (op[2:1] != 2'b11) ? 1'b0 : ((op[0] == 1'b0) ? (co_add^co_prev_add) :	(co_sub^co_prev_sub));	// V = overflow
endmodule