`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:		CSUSB, CSE 310
// Engineer:	Dr. Haiyan Qiao, Sean A. Finucane
// 
// Create Date:		11:07:57 11/17/2012 
// Design Name: 		32-Bit Jump Counter Driven Frequency Divider	
// Module Name:		JumpDivider32 
// Project Name:
// Target Devices:
// Tool versions:		Xilinx ISE Design Suite (13.2)
// Description:		Uses an internal 32-Bit resolution jump counter,
//							which increments by a given amount (i.e., the 
//							JUMP value). The output frequency is the input
//							frequency divided by a set amount.
//
// Dependencies:		None.
//
// Revision:
// Revision 0.01 - File Created
// Revision 1.00 - First Release
// Additional Comments:	The JUMP value is typically calculated as follows: 
//								JUMP = ( Hz_Out / MHz_in ) * ( 2^32 / 1e6 )
//
//////////////////////////////////////////////////////////////////////////////////
module JumpDivider32
	#(	parameter JUMP=86 )	// 86 := ( 1 Hz / 50 MHz ) * ( 2^32 / 1e6 )
	(
    input wire clk,
    output wire tick
    );
			
	reg [32:0] count;

	always@( posedge(clk) )
		count <= count[31:0] + JUMP;

	assign tick = count[32];

endmodule
