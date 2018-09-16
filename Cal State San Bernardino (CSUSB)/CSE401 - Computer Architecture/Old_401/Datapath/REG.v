`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Engineer:       
// Create Date:    12:26:26 04/10/2012 
// Module Name:    REG
// Project Name: 	 Lab2
// Description: 	 
//////////////////////////////////////////////////////////////////////////////////

module REG(input wire [4:0] rs, rt, rd,
			  input [31:0] writedata,
			  input regwrite,
			  output reg [31:0] A, B);

	reg [31:0] register[0:31];
	integer i;

	initial begin
		for (i = 0; i < 32; i = i + 1) 
			register[i] <= i;
		A <= 0;
		B <= 0;
	end

	//read rs and rt and index the register file to return outputs A and B
	always @* begin
		A <= register[rs];
		B <= register[rt];
	end

	//if regwrite and rd is true, write data using index destination
	always @* begin
		if(regwrite && rd != 0)
			register[rd] <= writedata;
	end

endmodule
	