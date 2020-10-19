module _srlatch(r, s, q, q_bar);
	input r, s;			//input r, s
	output q, q_bar;	//output q, q_bar, 
	
	_nor2 U0_nor2(.a(r), .b(q_bar), .y(q));		//load 2 input nor gate
	_nor2 U1_nor2(.a(s), .b(q), .y(q_bar));		//load 2 input nor gate
	
endmodule
