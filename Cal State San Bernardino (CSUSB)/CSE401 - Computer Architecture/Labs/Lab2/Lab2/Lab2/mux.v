// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): 
//
// Lab #1: Instruction Fetch Stage

//                              -*- Mode: Verilog -*-
// Filename        : mux.v
// Description     : The multiplexer module 
//                   of the IF stage of the pipeline
// Authors         : George M. Georgiou and Scott McWilliams
// Created On      : 2/06/2003
// Modified On     : 4/5/2011
// Modified By     : Jason Fredrick and David Sturgeon

module mux (
   output wire [31:0] y,     // Output of Multiplexer
   input wire  [31:0] a,     // Input 1 of Multiplexer
                      b,     // Input 0 of Multiplexer
   input wire  sel           // Select Input
   );
   
   assign	y = sel ? a : b;
endmodule // mux
