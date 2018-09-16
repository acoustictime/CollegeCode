`timescale 1ns / 1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #3: Instruction Execute Stage

//                              -*- Mode: Verilog -*-
// Filename        : ADDER.v
// Description     : Adds two 32 bit numbers.

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 5/3/11
module ADDER(	input wire [31:0] add_input_1,
					input wire [31:0] add_input_2,
					output reg [31:0] add_output
    );

	always @*
	begin
		add_output <= add_input_1 + add_input_2;
   end
endmodule
