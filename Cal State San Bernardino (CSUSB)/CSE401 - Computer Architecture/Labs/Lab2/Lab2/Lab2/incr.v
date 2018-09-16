// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): 
//
// Lab #1: Instruction Fetch Stage

//                              -*- Mode: Verilog -*-
// Filename        : incr.v
// Description     : The incrementer module 
//                   of the IF stage of the pipeline
// Authors         : George M. Georgiou and Scott McWilliams
// Created On      : 2/06/2003
// Modified On     : 4/5/2011
// Modified By     : Jason Fredrick and David Sturgeon
// Comments        : CHANGE: The incrementer is by 1 instead of by 4.
//                   This way, memory is word addressable.  If we need
//                   to change it later we will do that. You may make
//                   this change as well.

module incrementer (
   input  wire [31:0] pcin,      // Input of incrementer
   output wire [31:0] pcout      // Output of incrementer
   );
   assign pcout = pcin + 1;  // Increment PC by 1, *See Comments above
endmodule // incrementer
