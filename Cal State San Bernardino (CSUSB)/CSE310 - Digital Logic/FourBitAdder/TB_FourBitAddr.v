`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: James Small, Zachary Fuller
//
// Create Date:   12:59:50 01/22/2013
// Design Name:   FourBitAddr
// Module Name:   C:/Documents and Settings/user/Desktop/FourBitAdder/TB_FourBitAddr.v
// Project Name:  FourBitAdder
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: FourBitAddr
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TB_FourBitAddr;

	// Inputs
	reg [3:0] a;
	reg [3:0] b;
	reg c0;

	// Outputs
	wire [3:0] s;
	wire c4;

	// Instantiate the Unit Under Test (UUT)
	FourBitAddr uut (
		.a(a), 
		.b(b), 
		.c0(c0), 
		.s(s), 
		.c4(c4)
	);

	initial begin
		// 0000 + 0000
		a = 0;
		b = 0;
		c0 = 0;

		#100;
		
		// 0011 + 0101
		a = 4'b0011;
		b = 4'b0101;
	   c0= 0;
		
		#100;
		
		// 1111 + 0001
		a = 4'b1111;
		b = 4'b0001;
	   c0= 0;
		
		#100;
		
		// 4 + 7
		a = 4;
		b = 7;
		c0 = 0;
		
		#100;
		
		// 0011 + 0101
		a[0] = 1;
		a[1] = 1;
		a[2] = 0;
		a[3] = 0;
		
		b[0] = 1;
		b[1] = 0;
		b[2] = 1;
		b[3] = 0;
		
		c0 = 0;
		
		#100;

	end
      
endmodule

