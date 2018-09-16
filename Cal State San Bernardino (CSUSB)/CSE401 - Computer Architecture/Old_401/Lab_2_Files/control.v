`timescale 1ns/1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #2: Instruction Decode Stage

//                              -*- Mode: Verilog -*-
// Filename        : control.v
// Description     : Decodes the opcode

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 4/22/11

module control (
	output reg [1:0] WB,     		// Write back stage control lines
	output reg [2:0] M,     		// Memory access stage control lines
	output reg [4:0] EX,  			// Execution/ Addrees calculation stage control lines
	input wire [5:0] opcode     	// opcode input
   );
 
   parameter R_FORMAT = 6'b0;
	parameter lw = 'b100011;
	parameter sw = 'b101011; 
	parameter beq = 'b000100; 
 
	always @*
    begin
      case (opcode)
         R_FORMAT:
			begin
				EX <= 'b1100;
            M <= 'b000;
				WB <= 'b10;
			end
         lw:
			begin
				EX <= 'b0001;
            M <= 'b010;
				WB <= 'b11;
			end
			sw:
			begin
				EX <= 'bx001;
            M <= 'b001;
				WB <= 'b0x;
			end
         beq:
			begin
            EX <= 'bx010;
            M <= 'b100;
				WB <= 'b0x;
			end
      endcase
   end
   
endmodule 
