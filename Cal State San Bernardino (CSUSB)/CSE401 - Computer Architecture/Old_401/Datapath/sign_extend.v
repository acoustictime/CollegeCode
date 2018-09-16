`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Engineer:      
// Create Date:    12:26:26 04/10/2012 
// Module Name:    sign_extend
// Project Name: 	 Lab2
// Description: 	 Simple mux that uses select input to determine output
//////////////////////////////////////////////////////////////////////////////////
module sign_extend(input wire [15:0] ir_15_0,
						 output reg [31:0] sign_extended_ir_15_0);
						 
	always @(ir_15_0) begin
		sign_extended_ir_15_0[31:0] <= {{16{ir_15_0[15]}}, ir_15_0[15:0]};
	end
endmodule
