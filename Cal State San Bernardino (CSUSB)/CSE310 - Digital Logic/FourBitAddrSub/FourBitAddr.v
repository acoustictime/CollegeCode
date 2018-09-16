`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: James Small, Zachary Fuller
// 
// Create Date:    12:29:45 01/22/2013 
// Design Name: 
// Module Name:    FourBitAddr 
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

module FourBitAddr(
	 input wire [3:0] a,
    input wire [3:0] b,
	 input wire c0,
    output wire [3:0] s,
    output wire c4
    );	 

	 // signal interconnects:
	wire c1, c2, c3;
	
	// internal module declarations (sub-modules):
	full_adder fa_0( .x(a[0]), .y(b[0]), .z(c0), .S(s[0]), .C(c1) );	// FIRST Full-ADDER
	full_adder fa_1( .x(a[1]), .y(b[1]), .z(c1), .S(s[1]), .C(c2) );	// Second Full-ADDER
	full_adder fa_2( .x(a[2]), .y(b[2]), .z(c2), .S(s[2]), .C(c3) );	// Third Full-ADDER
	full_adder fa_3( .x(a[3]), .y(b[3]), .z(c3), .S(s[3]), .C(c4) );	// Fourth Full-ADDER
	


endmodule
