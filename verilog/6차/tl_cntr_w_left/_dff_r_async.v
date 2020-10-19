module _dff_r_async(clk, reset, d, q);	//Asynchronous D Flip flop

	input clk, reset, d;
	output q;
	reg q;
	
	always @ (posedge clk or negedge reset)	//clk on positive edge or reset on
	begin
		if(reset == 0) q <= 1'b0;	//if reset is 0, q is 0
		else q <= d;	//else, q is d
	end
endmodule