`timescale 1ns/100ps //test bench for cla_clk

module tb_cla_clk; //Declare name of module
   reg clock;
   reg [31:0] tb_a, tb_b; //Declare regs
   reg tb_ci;
   wire [31:0] tb_s_cla; //Declare wires
   wire tb_co_cla;

   parameter STEP = 10; //initial for clock

   cla_clk U0_cla_clk(.clock(clock), .a(tb_a), .b(tb_b),
                        .ci(tb_ci), .s_cla(tb_s_cla), .co_cla(tb_co_cla)); //instance

   always#(STEP/2) clock = ~clock;  //clock 0 5 and 1 5

   initial
      begin //start content
      clock=1'b1; tb_a=32'h0;				 tb_b=32'h0;           tb_ci=1'b0; //put the 32bit number in the test bench variable
      #(STEP-2);	tb_a=32'hFFFF_FFFF;   tb_b=32'h0;           tb_ci=1'b1;
      #(STEP);    tb_a=32'h0000_FFFF;   tb_b=32'hFFFF_0000;   tb_ci=1'b0;
      #(STEP);    tb_a=32'h135f_a562;   tb_b=32'h3561_4642;   tb_ci=1'b0;
      #(STEP*2);  $stop;
      end //end of content
endmodule //Declare end of moudle