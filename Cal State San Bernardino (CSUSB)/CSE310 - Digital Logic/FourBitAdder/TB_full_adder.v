`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   08:40:35 09/29/2012
// Design Name:   full_adder
// Module Name:   C:/Users/sfinucane/Desktop/CSE 310 LAB Mats/XILINX/LAB 2/CSE_310_FULL_ADDER/TB_full_adder.v
// Project Name:  CSE_310_FULL_ADDER
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: full_adder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TB_full_adder;

	// Inputs
	reg x;
	reg y;
	reg z;

	// Outputs
	wire S;
	wire C;

	// Instantiate the Unit Under Test (UUT)
	full_adder uut (
		.x(x), 
		.y(y), 
		.z(z), 
		.S(S), 
		.C(C)
	);

	initial begin
	
		// Initialize Inputs
		x = 0;
		y = 0;
		z = 0;
		
		#5;	// wait five cycles
        
		// TEST 1 + 0, Carry 0 == 1, Carry 0:
		x = 1;
		y = 0;
		z = 0;
		
		#5;	// wait five cycles
		
		// TEST 1 + 1, Carry 0 == 0, Carry 1:
		x = 1;
		y = 1;
		z = 0;
		
		#5;	// wait five cycles
		
		// TEST 1 + 1, Carry 1 == 1, Carry 1:
		x = 1;
		y = 1;
		z = 1;
		
		#5;	// wait five cycles
		
		// SPECIAL TEST:
		x = 0;
		y = 1;
		z = 1;

	end
      
endmodule

