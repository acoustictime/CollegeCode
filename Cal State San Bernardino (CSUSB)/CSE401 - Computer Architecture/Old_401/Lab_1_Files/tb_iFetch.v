`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:40:51 04/12/2011
// Design Name:   I_FETCH
// Module Name:   F:/CSE-401/Labs/Lab_1/Source Files/tb_iFetch.v
// Project Name:  Lab_1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: I_FETCH
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module tb_iFetch;

	// Inputs
	reg EX_MEM_PCSrc;
	reg [31:0] EX_MEM_NPC;

	// Outputs
	wire [31:0] IF_ID_instr;
	wire [31:0] IF_ID_npc;

	// Instantiate the Unit Under Test (UUT)
	I_FETCH uut (
		.IF_ID_instr(IF_ID_instr), 
		.IF_ID_npc(IF_ID_npc), 
		.EX_MEM_PCSrc(EX_MEM_PCSrc), 
		.EX_MEM_NPC(EX_MEM_NPC)
	);

	initial begin
		// Initialize Inputs
		EX_MEM_PCSrc = 0;
		EX_MEM_NPC = 0;

		// Wait 100 ns for global reset to finish
		#100;
      $stop;
		// Add stimulus here

	end
      
endmodule

