module ns_logic(Ta, Tal, Tb, Tbl, q, d); //next state logic

	input 				Ta, Tal, Tb, Tbl;	//input Ta, Tal, Tb, Tbl
	input		[2:0]		q;				//input 3bit q
	
	output	[2:0]		d;					//output 3bit d
	
	wire	[9:0] w; //number of the wire needed in this circuit is 10
	
	//next state D2's code
	_and3 U0_and3(.a(~q[2]), .b(q[1]), .c(q[0]), .y(w[0])); //Q2_bar * Q1 * Q0
	_and2 U1_and2(.a(q[2]), .b(~q[1]), .y(w[1])); //Q2 * Q1_bar
	_and3 U2_and3(.a(q[2]), .b(q[1]), .c(~q[0]), .y(w[2])); //Q2 * Q1 * Q0_bar
	_or3	U3_or3(.a(w[0]), .b(w[1]), .c(w[2]), .y(d[2]));
	
	//next state D1's code
	_and3 U4_and3(.a(~q[2]), .b(~q[1]), .c(q[0]), .y(w[3])); //Q2_bar * Q1_bar * Q0
	_and2 U5_and2(.a(q[1]), .b(~q[0]), .y(w[4])); //Q1 * Q0_bar
	_and3 U6_and3(.a(q[2]), .b(~q[1]), .c(q[0]), .y(w[5])); //Q2 * Q1_bar * Q0
	_or3	U7_or3(.a(w[3]), .b(w[4]), .c(w[5]), .y(d[1]));
	
	//next state D0's code
	_and4 U8_and4(.a(~q[2]), .b(~q[1]), .c(~q[0]), .d(~Ta), .y(w[6])); //Q2_bar * Q1_bar * Q0_bar * Ta_bar
	_and4 U9_and4(.a(~q[2]), .b(q[1]), .c(~q[0]), .d(~Tal), .y(w[7])); //Q2_bar * Q1 * Q0_bar * Tal_bar
	_and4 U10_and4(.a(q[2]), .b(~q[1]), .c(~q[0]), .d(~Tb), .y(w[8])); //Q2 * Q1_bar * Q0_bar * Tb_bar
	_and4 U11_and4(.a(q[2]), .b(q[1]), .c(~q[0]), .d(~Tbl), .y(w[9])); //Q2 * Q1 * Q0_bar * Tbl*bar
	_or4	U12_or4(.a(w[6]), .b(w[7]), .c(w[8]), .d(w[9]), .y(d[0]));
	
endmodule
