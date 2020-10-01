module _mx2(d0, d1, s, y);
	input d0, d1, s;	//three input
	output y;			//one output

_inv iv0(.a(s), .y(sbar));	//load _inv
_nand2 nd20(.a(d0), .b(sbar), .y(w0));	//load _nand2
_nand2 nd21(.a(d1), .b(s), .y(w1));		//load _nand2
_nand2 nd22(w0, w1, y);						//load _nand2
	
endmodule	//end of moduleL