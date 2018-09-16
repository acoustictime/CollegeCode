`timescale 1ns / 1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #3: Instruction Execute Stage

//                              -*- Mode: Verilog -*-
// Filename        : ALU.v
// Description     : Adds, subtracts, or's, and's or checks if a < b

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 5/3/11
// Some code used was written by Jason Fredrick
module ALU(	input wire [31:0] A,
				input wire [31:0] B,
				input wire [2:0] control,
				output wire	zero,
				output reg [31:0] result
    );

wire sign_mismatch;
assign sign_mismatch = A[31] ^ B[31];

initial result <=0;
assign zero = ~|result; //Unary nor result to check for zero
		
always @*
begin
		case (control)
				3'b010: //add
				begin
					result = A + B;
				end
				
				3'b110: //subtract
				begin
					result = A - B;
				end
				
				3'b000: //and			
				begin
					result = A & B;
				end
				
				3'b001: //or			
				begin
					result = A | B;
				end
				
				3'b111: result <= A < B ? 1-sign_mismatch:
										0+sign_mismatch;
				default:
				begin
					result = 32'bx;
				end
      endcase
end

endmodule
