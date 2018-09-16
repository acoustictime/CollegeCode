// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): 
//
// Lab #1: Instruction Fetch Stage

//                              -*- Mode: Verilog -*-
// Filename        : pipeline.v
// Description     : The pipeline module which simulates the
//                   function of the IF stage of the pipeline
// Authors         : George M. Georgiou and Scott McWilliams
// Created On      : 2/06/2003
// Modified On     : 4/5/2011
// Modified By     : Jason Fredrick and David Sturgeon

//`include "ifetch.v"

module pipeline ();

  wire [31:0] IF_ID_instr, IF_ID_npc;
  reg EX_MEM_PCSrc;
  reg [31:0] EX_MEM_NPC;

   I_FETCH I_FETCH1(.IF_ID_instr(IF_ID_instr),
                    .IF_ID_npc(IF_ID_npc),
                    .EX_MEM_PCSrc(EX_MEM_PCSrc),
                    .EX_MEM_NPC(EX_MEM_NPC) );
   initial begin
   EX_MEM_PCSrc <= 0;
   EX_MEM_NPC <= 0;
   end
   
// Here you will add I_DECODE.  You will have to declare wires to make 
// the connections between the I_FETCH and I_DECODE modules

// declare REG for 3 input wires from last stage, and also 11 wires for output


	IDECODE IDECODE1(.IF_ID_instrout(IF_ID_instr), 
						  .IF_ID_npcout(IF_ID_npc),
						  .MEM_WB_rd(),
						  .MEM_WB_regwrite(),
						  .WB_mux5_writedata(),
						  .wb_ctlout(),
						  .m_ctlout(),
						  .regdst(),
						  .alusrc(),
						  .aluop(),
						  .npcout(),
						  .rdata1out(),
						  .rdata2out(),
						  .s_extendout(),
						  .instrout_2016(),
						  .instrout_1511());
	initial begin
   //setup three inputs coming from last stage, most likely 0's
   end	

	
						  
// Inputs to IDECODE						
/*IF_ID_instrout,
IF_ID_npcout,
MEM_WB_rd, // comes from last stage
MEM_WB_regwrite,// comes from last stage
WB_mux5_writedata*/// comes from last stage
	



endmodule // pipeline





