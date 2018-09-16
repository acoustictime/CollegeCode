`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:00:39 03/12/2013 
// Design Name: 
// Module Name:    ThreeDigit_BCD 
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

module ThreeDigit_BCD (
	input wire clk,
	input wire reset,
	output wire [3:0] bit0, 
	output wire [3:0] bit1, 
	output wire [3:0] bit2
);

// 3 instances of BCD_Counter

BCD_Counter c1(.clk(clk),.reset(reset),.Q(bit0));
BCD_Counter c2(.clk(bit0[3]),.reset(reset),.Q(bit1));
BCD_Counter c3(.clk(bit1[3]),.reset(reset),.Q(bit2));

endmodule