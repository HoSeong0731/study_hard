module ns_logic(Ta, Tb, q, d); //next state logic

	input 				Ta, Tb;		//input Ta, Tb
	input 	[1:0]		q;			//input 2bit q
	output	[1:0]		d;			//output 2bit d
	
	wire w_AND3_1, w_AND3_2;		//wire w_AND3_1, w_AND3_2
	
	//D0
	_and3 U0_and3(.a(~q[0]), .b(~q[1]), .c(~Ta), .y(w_AND3_1)); 	//instance of AND3 gate
	_and3 U1_and3(.a(q[1]), .b(~q[0]), .c(~Tb), .y(w_AND3_2)); 		//instance of AND3 gate
	_or2 U2_or2(.a(w_AND3_1), .b(w_AND3_2), .y(d[0])); 				//instance of OR2 gate
	
	//D1
	_xor2 U3_xor2(.a(q[1]), .b(q[0]), .y(d[1])); 						//instance of XOR2 gate
	
endmodule

	