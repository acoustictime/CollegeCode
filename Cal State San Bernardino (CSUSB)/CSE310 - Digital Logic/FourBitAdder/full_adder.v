`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSUSB
// Engineer: Haiyan Qiao, Sean A. Finucane
// 
// Create Date:	08:29:08 09/29/2012 
// Design Name:	Full-Adder using Half-Adders, Gate-Level (200X)
// Module Name:	full_adder 
// Project Name:	CSE 310 LAB
// Target Devices: NONE
// Tool versions: XILINX ISE (13.4)
// Description: 
//
// Dependencies: half_adder
//
// Revision: 1.0 - First Functional Release
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module full_adder(
    input wire x,
    input wire y,
    input wire z,
    output wire S,
    output wire C
    );

	// signal interconnects:
	wire S0, C0, C1;

	// internal module declarations (sub-modules):
	half_adder ha_0( .x(x), .y(y), .S(S0), .C(C0) );	// FIRST HALF-ADDER
	half_adder ha_1( .x(S0), .y(z), .S(S), .C(C1) );	// SECOND HALF_ADDER
	
	// output assignments (where still needed):
	assign C = C0 | C1;

endmodule
