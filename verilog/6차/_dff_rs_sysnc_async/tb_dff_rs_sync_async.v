`timescale 1ns/100ps

module tb_dff_rs_sync_async;

	reg	tb_clk, tb_set_n, tb_reset_n, tb_d;
	wire	tb_q_sync, tb_q_async;
	
	_dff_rs_sync_async	U0_dff_rs_sync_async(.clk(tb_clk), .set_n(tb_set_n), .reset_n(tb_reset_n), .d(tb_d), .q_sync(tb_q_sync), .q_async(tb_q_async));
															
always
begin
	tb_clk=1'b0; #5; tb_clk=1'b1; #5;
end												

initial
begin
	tb_d=1'b0; tb_set_n=1'b0; tb_reset_n=1'b0;
	#10 tb_d=1'b1; #10 tb_d=1'b0;
	#10 tb_d=1'b1;
	#10 tb_reset_n=1'b1;
	#10 tb_d=1'b0; #10 tb_d=1'b1;
	#10 tb_d=1'b0; #10 tb_d=1'b1;
	#10 tb_set_n=1'b1;
	#10 tb_d=1'b0; #10 tb_d=1'b1;
	#10 tb_d=1'b0; #10 tb_d=1'b1;
	#10 tb_reset_n=1'b0;
	#10 tb_d=1'b0; #10 tb_d=1'b1;
	#10 tb_d=1'b0; #10 tb_d=1'b1;							
	#10 $stop;
end

endmodule
