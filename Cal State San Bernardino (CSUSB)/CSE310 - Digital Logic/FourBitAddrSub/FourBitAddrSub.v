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

module FourBitAddrSub(
    input wire [3:0] a,
    input wire [3:0] b,
    input wire c0,
    output wire [3:0] s,
    output wire c4,
    output wire v
    );	 

	 // signal interconnects:

	wire c1, c2, c3, x1, x2, x3, x4;
	
	// internal module declarations (sub-modules):

	xor x5(x1,c0,b[0]);

	full_adder fa_0( .x(a[0]), .y(x1), .z(c0), .S(s[0]), .C(c1) );	// FIRST Full-ADDER

	xor x6(x2,c0,b[1]);

	full_adder fa_1( .x(a[1]), .y(x2), .z(c1), .S(s[1]), .C(c2) );	// Second Full-ADDER

	xor x7(x3,c0,b[2]);

	full_adder fa_2( .x(a[2]), .y(x3), .z(c2), .S(s[2]), .C(c3) );	// Third Full-ADDER

	xor x8(x4,c0,b[3]);

	full_adder fa_3( .x(a[3]), .y(x4), .z(c3), .S(s[3]), .C(c4) );	// Fourth Full-ADDER
	
	xor x9(v,c4,c3);


endmodule
