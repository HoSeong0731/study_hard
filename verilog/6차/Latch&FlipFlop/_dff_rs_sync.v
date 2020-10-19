	module _dff_rs_sync(clk, set_n, reset_n, d, q);		

	input		clk, set_n, reset_n, d;		//input clk, set_n, reset_n, d
	output	q;								//output q
	reg	q;									//reg q
	
	always@(posedge clk)
	begin
		if(reset_n == 0)		q <= 1'b0;
		else if(set_n == 0)	q <= 1'b1;
		else						q <= d;
	end
	
endmodule
