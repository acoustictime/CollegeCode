`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:25:08 03/05/2013
// Design Name:   D_FF
// Module Name:   C:/Documents and Settings/user/Desktop/Lab7/TB_FF.v
// Project Name:  Lab7
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: D_FF
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TB_FF;

	// Inputs
	reg D;
	reg clk;

	// Outputs
	wire Q;

	// Instantiate the Unit Under Test (UUT)
	D_FF uut (
		.Q(Q), 
		.D(D), 
		.clk(clk)
	);

	initial begin
		// Initialize Inputs
		D = 0;
		clk = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		
		D = 1;
		clk = 1;
		
		# 100
		
		D = 0;
		clk = 0;
		
		# 100
		
		D = 0;
		clk = 1;
		
		
	end
      
endmodule

