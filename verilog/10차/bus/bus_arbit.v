
//arbiter
module arbiter(clk,reset_n,M0_request,M1_request,M0_grant,M1_grant);
	
	input clk,reset_n;
	input M0_request,M1_request;		//master request
	
	output reg M1_grant,M0_grant;		//master grant
	
	reg next_M1_grant,next_M0_grant;	//next_master grant
	
	always@(posedge clk)
	begin
		M1_grant=next_M1_grant;
		M0_grant=next_M0_grant;
	end
	
	always@(reset_n,M0_request,M1_request)
		begin
		if(reset_n==0)						// initialize --> M0--grant
			begin
				next_M0_grant=1;
				next_M1_grant=0;
			end
		
		else if(reset_n==1)
			begin
				case({M0_request,M1_request})
					2'b 10:begin			//when grant is M0
								if(M0_request==0&&M1_request==0||M0_request==1)	//request M0_self or initial state
									{next_M0_grant,next_M1_grant}=2'b 10;
								else if(M0_request==0&&M1_request==1)				//request not M0, but M1
									{next_M0_grant,next_M1_grant}=2'b 01;
							end
					2'b 01:begin			//when grant is M1
								if(M1_request==1)// request M1_self
									{next_M0_grant,next_M1_grant}=2'b 01;
								else if(M1_request==0)									//request M1 --0    ---> turn grant to M0
									{next_M0_grant,next_M1_grant}=2'b 10;
							end
				endcase
			end
		
		end
endmodule 