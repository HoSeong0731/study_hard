module o_logic(q, La, Lb);
	
	input		[2:0]		q;
	output	[1:0]		La, Lb;
	
	wire		[1:0]		w;
	
	//output La_1's code based on Karnaugh Map
	_and2 U0_and2(.a(q[1]), .b(~q[0]), .y(w[0]));
	_or2 U1_or2(.a(w[0]), .b(q[2]), .y(La[1])); //(Q1 * Q0_bar) + Q2
	
	//output La_0's code based on Karnaugh Map
	_or2 U2_or2(.a(q[0]), .b(q[2]), .y(La[0])); //Q0 + Q2
	
	//output Lb_1's code based on Karnaugh Map
	_and2 U3_and2(.a(q[1]), .b(~q[0]), .y(w[1]));
	_or2	U4_or2(.a(~q[2]), .b(w[1]), .y(Lb[1])); //Q2_bar + (Q1 * Q0_bar)
	
	//output Lb_0's code based on Karnaugh Map
	_or2 U5_or2(.a(~q[2]), .b(q[0]), .y(Lb[0])); //Q2_bar + Q0
	
endmodule
