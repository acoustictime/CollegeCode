`timescale 1ns/1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #2: Instruction Decode Stage

//                              -*- Mode: Verilog -*-
// Filename        : s_extend.v
// Description     : Extends the 16 bits into 32 bit. 

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 4/22/11
//////////////////////////////////////////////////////////////////////////////////
module s_extend(	input wire [15:0] IF_ID_instr,     	// opcode input
						output reg [31:0] Extended 			
    );


	assign sign_bit = IF_ID_instr[15];


	always @*
		begin
			case (sign_bit)
				0:
				begin
					Extended = {16'b0, IF_ID_instr[15:0]};
				end
				1:
				begin
					Extended = {16'b1, IF_ID_instr[15:0]};
				end
      endcase
   end
	
endmodule
