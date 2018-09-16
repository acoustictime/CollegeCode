`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:53:50 04/05/2012 
// Design Name: 
// Module Name:    i_fetch 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module i_fetch(output [31:0] instr_out,npc ,
					 input [31:0] Ex_mem_latch,
					 input        PCSrc);
	
	wire [31:0] mux_pc,pc_out, adder_out,data_out;
	
	mux mux_unit1(.in0(adder_out), .in1(Ex_mem_latch),.sel(PCSrc), .out(mux_pc));
	incr adder(.pcin(pc_out),.pcout(adder_out));
	pc pc_unit(.PC_in(mux_pc),.PC_out(pc_out));
	mem mem_unit(.mem_addr(pc_out),.mem_data(data_out));
	buff #(.SIZE(32)) npc_buf(.in(adder_out),.out(npc));
	buff #(.SIZE(32)) instr_buf(.in(data_out),.out(instr_out));
	

endmodule
