`timescale 1ns/1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #2: Instruction Decode Stage

//                              -*- Mode: Verilog -*-
// Filename        : BOTTOM_MUX.v
// Description     : Inputs 5 bits 

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 4/22/11

module bottom_mux (
   output wire [4:0] y,     // Output of Multiplexer
   input wire  [4:0] a,     // Input 1 of Multiplexer
                     b,     // Input 0 of Multiplexer
   input wire  regDst       // Select Input
   );
   
   assign	y = regDst ? a : b;
endmodule // mux
