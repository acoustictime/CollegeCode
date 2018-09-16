// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): 
//
// Lab #1: Instruction Fetch Stage

//                              -*- Mode: Verilog -*-
// Filename        : ifetch.v
// Description     : The ifetch module 
//                   of the IF stage of the pipeline.
// Authors         : George M. Georgiou and Scott McWilliams
// Created On      : 2/06/2003
// Modified On     : 4/5/2011
// Modified By     : Jason Fredrick and David Sturgeon

/*
`include "mux.v"
`include "mem.v"
`include "incr.v"
`include "if_id.v"
`include "pc_mod.v"
*/

module I_FETCH (
   output wire  [31:0] IF_ID_instr,
   output wire  [31:0] IF_ID_npc,
   input  wire         EX_MEM_PCSrc,
   input  wire  [31:0] EX_MEM_NPC
   );
   
//signals
   wire [31:0] PC;
   wire [31:0] dataout;
   wire [31:0] npc,npc_mux;

   //instantiations
   mux mux1 (.y(npc_mux), 
             .a(EX_MEM_NPC), 
             .b(npc), 
             .sel(EX_MEM_PCSrc));
                
   pc_mod pc_mod1 (.PC(PC), 
                   .npc(npc_mux));
                   
   memory memory1 (.data(dataout),
                   .addr(PC));
                   
   if_id  if_id1  (.instrout(IF_ID_instr),
                   .npcout(IF_ID_npc),
                   .instr(dataout), 
                   .npc(npc));
                   
   incrementer incrementer1 (.pcout(npc), 
                             .pcin(PC));
   initial begin
      $display("Time\t PC\t npc\t dataout of MEM\t IF_ID_instr\t IF_ID_npc");
      $monitor("%0d\t %0d\t %0d\t %h\t %h\t %0d", $time, PC, npc, dataout,IF_ID_instr,IF_ID_npc);
      #20 $finish;
   end                          

endmodule // I_FETCH
