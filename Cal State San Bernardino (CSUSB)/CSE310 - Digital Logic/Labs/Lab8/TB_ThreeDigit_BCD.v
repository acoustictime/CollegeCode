`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:08:12 03/12/2013
// Design Name:   ThreeDigit_BCD
// Module Name:   C:/Documents and Settings/user/Desktop/Lab8/TB_ThreeDigit_BCD.v
// Project Name:  Lab8
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ThreeDigit_BCD
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TB_ThreeDigit_BCD;

	// Inputs
	reg clk;
	reg reset;

	// Outputs
	wire [3:0] bit0;
	wire [3:0] bit1;
	wire [3:0] bit2;

	// Instantiate the Unit Under Test (UUT)
	ThreeDigit_BCD uut (
		.clk(clk), 
		.reset(reset), 
		.bit0(bit0), 
		.bit1(bit1), 
		.bit2(bit2)
	);

	initial begin clk = 0; forever #5 clk = ~clk; end

	initial begin
		// Initialize Inputs

		reset = 0;
		

	

	end
      
endmodule

