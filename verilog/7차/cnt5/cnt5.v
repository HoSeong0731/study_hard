module cnt5(cnt,clk,reset_n,inc);
	input clk,reset_n,inc;	
	output [2:0] cnt;

	parameter zero=3'b000;		//naming 0~5 and separate the case to make the counter by parameter
	parameter one=3'b001;
	parameter two=3'b010;
	parameter three=3'b011;
	parameter four=3'b100;

	reg [2:0] cnt;				//setting 3bit count
	reg [2:0] next_cnt;			//setting 3bit next count
	
	always@(posedge clk or negedge reset_n)
		begin
			if(reset_n==1'b0)//reset =1  -> count is zero.
				cnt<=zero;
			else
				cnt<=next_cnt;	//if not, count is next count,
		end

	always@(inc or cnt)//when inc and cnt is setting
		begin
			case({cnt,inc})
				{zero,1'b0} : next_cnt<=four;
				{zero,1'b1} : next_cnt<=one;
				{one,1'b0} : next_cnt<=zero;
				{one,1'b1} : next_cnt<=two;
				{two,1'b0} : next_cnt<=one;
				{two,1'b1} : next_cnt<=three;
				{three,1'b0} : next_cnt<=two;
				{three,1'b1} : next_cnt<=four;
				{four,1'b0} : next_cnt<=three;
				{four,1'b1} : next_cnt<=zero;		//state is 4 and inc is 1 goes to 0(similiar to reset.)
				default : next_cnt<=3'bx;			/exception control
			endcase
		end
		
endmodule
