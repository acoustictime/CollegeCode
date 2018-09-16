`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:24:58 04/05/2012 
// Design Name: 
// Module Name:    pipeline 
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
module pipeline;

	reg PCSrc;
	wire [31:0] instr_out,npc;
	
	initial
		begin
			PCSrc <=0;
			#10 $finish;
		end
	i_fetch my_i_fetch(.instr_out(instr_out),.npc(npc),.Ex_mem_latch(),.PCSrc(PCSrc));

endmodule
