module TOP(clk, reset_n, m_req, m_wr, m_addr, m_dout, m_grant, interrupt_out, m_din, state);
	input clk, reset_n, m_req, m_wr;
	input [15:0] m_addr;
	input [31:0] m_dout;
	output m_grant, interrupt_out;
	output [63:0] m_din;
	output [2:0] state;
	wire [63:0] wire_to_S_dout, wire_to_S_din;
	wire wire_to_s_sel, wire_to_S_wr;
	wire [15:0]wire_to_s_addr;
	BUS U0_BUS(.clk(clk), .reset_n(reset_n), .m_req(m_req), .m_wr(m_wr), .m_addr(m_addr), .m_dout(m_dout), .S_dout(wire_to_S_dout), .m_grant(m_grant), .m_din(m_din),.s_sel(wire_to_s_sel), .s_addr(wire_to_s_addr), .s_wr(wire_to_S_wr), .s_din(wire_to_S_din));
	
	MP U1_MP(.Clk(clk), .Reset_n(reset_n), .S_wr(wire_to_S_wr), .S_addr(wire_to_s_addr), .s_din(wire_to_S_din[31:0]), .s0_sel(wire_to_s_sel), .s_dout(wire_to_S_dout), .Interrupt_out(interrupt_out),.state(state));



endmodule
