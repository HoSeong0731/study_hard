module o_logic(Q, La, Lb); 	//output logic

	input		[1:0] 	Q; 	//inputs
	output	[1:0] 	La, Lb; //outputs
	
	_and2 U0_and2(.a(~Q[1]), .b(Q[0]), .y(La[0]));	//L(a0)
	_inv	U1_inv(.a(Q[1]), .y(Lb[1]));					//L(b1)
	_and2	U2_and2(.a(Q[1]), .b(Q[0]), .y(Lb[0]));	//L(b0)
	
	assign	La[1] = Q[1];									//L(a1)
	
	endmodule
