// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): 
//
// Lab #1: Instruction Fetch Stage

//                              -*- Mode: Verilog -*-
// Filename        : if_id.v
// Description     : The if_id module 
//                   of the IF stage of the pipeline.
// Authors         : George M. Georgiou and Scott McWilliams
// Created On      : 2/06/2003
// Modified On     : 4/5/2011
// Modified By     : Jason Fredrick and David Sturgeon

module if_id (
   output reg [31:0] instrout,       // Output of IF/ID Instruction Register
                       npcout,       // Output of IF/ID NPC Register
   input wire [31:0]    instr,       // Input of IF/ID Instruction Register
                          npc        // Input of IF/ID NPC Register
   );
   initial begin
      instrout <= 0;
      npcout   <= 0;
   end
   always @* begin
      #1 instrout <= instr;
           npcout <= npc;
   end
endmodule // if_id
