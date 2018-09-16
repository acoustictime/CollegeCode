`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:23:23 03/05/2013
// Design Name:   Nibble_Reg
// Module Name:   C:/Documents and Settings/user/Desktop/Lab7/TB_Nibble.v
// Project Name:  Lab7
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Nibble_Reg
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TB_Nibble;

	// Inputs
	reg [3:0] data_in;
	reg load;
	reg out_en;

	// Outputs
	wire [3:0] data_out;

	// Instantiate the Unit Under Test (UUT)
	Nibble_Reg uut (
		.data_in(data_in), 
		.load(load), 
		.out_en(out_en), 
		.data_out(data_out)
	);

	initial begin
		// Initialize Inputs
		data_in = 0;
		load = 0;
		out_en = 0;

		// Wait 100 ns for global reset to finish
		#20;
        
		// Add stimulus here
		
		data_in = 4'b1010;
		load = 1;
		out_en = 0;
		
		#20;
        
		// Add stimulus here
		
		data_in = 4'b1111;
		load = 0;
		out_en = 0;
		
		#20;
        
		// Add stimulus here
		
		load = 1;
		out_en = 0;

	end
      
endmodule

