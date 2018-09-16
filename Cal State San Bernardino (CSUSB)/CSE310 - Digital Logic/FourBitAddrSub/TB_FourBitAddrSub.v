`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:05:44 02/07/2013
// Design Name:   FourBitAddrSub
// Module Name:   C:/Documents and Settings/user/Desktop/FourBitAddrSub/TB_FourBitAddrSub.v
// Project Name:  FPGA_Lab
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: FourBitAddrSub
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TB_FourBitAddrSub;

	// Inputs
	reg [3:0] a;
	reg [3:0] b;
	reg c0;

	// Outputs
	wire [3:0] s;
	wire c4;
	wire v;

	// Instantiate the Unit Under Test (UUT)
	FourBitAddrSub uut (
		.a(a), 
		.b(b), 
		.c0(c0), 
		.s(s), 
		.c4(c4), 
		.v(v)
	);

	initial begin
		
		// 1110 - 0101
		a = 4'b1110;
		b = 4'b0101;
	   c0= 1;
	
		#100;
		
		
	end
      
endmodule

