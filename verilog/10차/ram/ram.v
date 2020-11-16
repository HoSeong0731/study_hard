module ram(clk, cen, wen, addr, din, dout);
	input clk;
   input cen, wen;
   input [4:0] addr;
   input [31:0] din;
   output reg [31:0] dout;
   
   reg [31:0] mem [0:31];
   integer i;
	 
   initial begin
		for(i=0;i<32;i=i+1)
		mem[i]= 0;										//memory initialization
   end
     
   always @(posedge clk)begin
   if(cen & wen)begin
		mem[addr]  <= din;							//write
      dout   <= 32'b0;
   end
   else if(cen & !wen) 	dout <= mem[addr];	//read
   else if(!cen)   		dout <= 32'b0;			//dout initialization
   else      				dout <= 32'bx;
   end 
endmodule
