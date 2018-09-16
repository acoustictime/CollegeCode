`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:26:56 04/05/2012 
// Design Name: 
// Module Name:    pc 
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
module pc(output reg [31:0] PC_out,
			 input [31:0] PC_in);
			 
	//reg [31:0] PC_out;
	initial
	  begin
			PC_out<=0;
	  end

	always @(PC_in)begin
		#1 
		PC_out <= PC_in;
	end
endmodule
