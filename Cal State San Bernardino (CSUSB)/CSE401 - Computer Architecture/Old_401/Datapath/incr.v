`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:20:16 04/05/2012 
// Design Name: 
// Module Name:    incr 
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
module incr(output [31:0] pcout,
			   input  [31:0] pcin);
				
			assign pcout = pcin+1;

endmodule
