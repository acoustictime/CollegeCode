`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSUSB
// Engineer: Haiyan Qiao, Sean A. Finucane
// 
// Create Date:	08:19:36 09/29/2012 
// Design Name:	Gate-Level Half-Adder (200X)
// Module Name:	half_adder
// Project Name:	CSE 310 LAB
// Target Devices: NONE
// Tool versions: XILINX ISE (13.4)
// Description:
//
// Dependencies:
//
// Revision: 1.0 - First Functional Release
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module half_adder(
    input wire x,
    input wire y,
    output wire S,
    output wire C
    );

	assign S = x ^ y;	// XOR Gate
	assign C = x & y;	// AND Gate

endmodule
