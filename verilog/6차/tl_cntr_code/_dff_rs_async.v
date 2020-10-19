module _dff_rs_async(clk, set_n, reset_n, d, q);

	input		clk, set_n, reset_n, d;	//input clk, set_n, reset_n, d
	output	q;							//output q
	reg	q;								//reg q
	
	always@(posedge clk or negedge set_n or negedge reset_n)
	begin
		if(reset_n == 0)			q <= 1'b0;
		else if(set_n == 0)		q <= 1'b1;
		else							q <= d;
	end
	
endmodule
