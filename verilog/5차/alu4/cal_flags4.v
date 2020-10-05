module cal_flags4(op, result, co_add, c3_add, co_sub, c3_sub, c, n, z, v);
input [2:0] op;			//3input operation
input [3:0] result;		//4input result
input co_add, c3_add, co_sub, c3_sub;	//input add and sug
output c, n, z, v;		//output c, n, z, v

assign c=(op[2:1]!=2'b11) ? 1'b0 : ((op[0]==1'b0) ? co_add:co_sub); 	//c= carry
assign n=result[3];    																//n = negative
assign z=(result==4'b0) ? 1'b1:1'b0;  											//z = zero
assign v=(op[2:1] != 2'b11) ? 1'b0 : ((op[0]==1'b0) ? (co_add^c3_add) : (co_sub^c3_sub)); //v = overflow
endmodule

