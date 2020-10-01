module ha(a,b,s,co);	//2input
input a,b;				//input a and b
output s,co;			//output sum and carry out
assign s = a^b;		//S = A xor B
assign co = a&b;		//Carry out = A and B
endmodule				//end module
