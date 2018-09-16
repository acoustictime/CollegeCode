`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:04:15 04/19/2011
// Design Name:   REG
// Module Name:   F:/CSE-401/Labs/Lab_1/tb_REG.v
// Project Name:  Lab_1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: REG
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module tb_REG;

	// Inputs
	reg [4:0] rs;
	reg [4:0] rt;
	reg [4:0] rd;
	reg [31:0] writedata;
	reg regwrite;

	// Outputs
	wire [31:0] A;
	wire [31:0] B;

	// Instantiate the Unit Under Test (UUT)
	REG uut (
		.rs(rs), 
		.rt(rt), 
		.rd(rd), 
		.writedata(writedata), 
		.regwrite(regwrite), 
		.A(A), 
		.B(B)
	);

	initial begin
		// Initialize Inputs
		rs = 0;
		rt = 0;
		rd = 0;
		writedata = 0;
		regwrite = 0;

		// Wait 100 ns for global reset to finish
		#1;
        
		// Add stimulus here

		rs = 0;
		rt = 1;
		rd = 2;
		writedata = 0;
		regwrite = 0;
		#1

		rs = 0;
		rt = 0;
		rd = 0;
		writedata = 27;
		regwrite = 1;
		#1
	end
      
endmodule

