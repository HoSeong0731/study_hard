module _nand2(a,b,y); 
input a,b;			//two inputs
output y;			//one outputs
assign y=~(a&b);	//y = NOT(A AND B)
endmodule			//end of module
