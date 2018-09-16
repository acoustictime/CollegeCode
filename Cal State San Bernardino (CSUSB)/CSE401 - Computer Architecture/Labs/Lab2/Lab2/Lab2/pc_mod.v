// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): 
//
// Lab #1: Instruction Fetch Stage

//                              -*- Mode: Verilog -*-
// Filename        : pc_mod.v
// Description     : The program counter module 
//                   of the IF stage of the pipeline.
// Authors         : George M. Georgiou and Scott McWilliams
// Created On      : 2/06/2003
// Modified On     : 4/5/2011
// Modified By     : Jason Fredrick and David Sturgeon

module pc_mod (
   output reg [31:0] PC,             // Output of pc_mod
   input wire [31:0] npc             // Input of pc_mod
   );

   initial begin
      PC <= 0;
   end
   always @ ( npc) begin
      #1 PC <= npc;
   end

endmodule // pc_mod
