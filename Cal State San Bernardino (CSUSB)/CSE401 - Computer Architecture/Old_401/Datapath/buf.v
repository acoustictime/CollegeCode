`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:02:46 04/05/2012 
// Design Name: 
// Module Name:    buf 
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
module buf#(SIZE=32)
	(input [SIZE-1:0] in,
	 output reg [SIZE-1:0] out);

	always @ (in)
		#1 out<= in;
endmodule // buf
