`timescale 1ns/1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #1 & 2: Instruction Fetch Stage + Decode Stage

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
	//wire [31:0] NOT_CURRENTLY_USED = 'bz;
	wire [1:0] WB_out;     		
	wire [2:0] M_out;    		
	wire [4:0] EX_out; 			
	wire [31:0] A_out;
	wire [31:0] B_out;					
	wire [31:0] Extended_out;		
	wire [20:16] IF_ID_instrHigher_out;
	wire [15:11] IF_ID_instrLower_out;
	wire [31:0] IF_ID_npc_out;	
	wire [4:0] ex_mem_mux_out;
	wire [1:0] ex_mem_ctwb_out; 
	wire [2:0] ex_mem_ctlm_out;
	wire [31:0] ex_mem_adder_out;
	wire ex_mem_zero_out;
	wire [31:0] ex_mem_aluout_out;
	wire [31:0] ex_mem_readdat_out;
	wire PCSrc;
	wire [1:0] mem_control_wb;
	wire [31:0] mem_read_data_out;
	wire [31:0] mem_ALU_result;
	wire [4:0] mem_write_reg;
	wire [31:0] wb_mux_out;
	wire [31:0] mem_read_data;


	

	I_decode I_decode1(	.IR(IF_ID_instr),
								.regwrite_in(mem_control_wb[1]), 	///
								.write_reg_in(mem_write_reg), 			///
								.write_data_in(wb_mux_out),	///
								.npc(IF_ID_npc), 
									//Begin Outputs
								.WB_out(WB_out),     		
								.M_out(M_out),     		
								.EX_out(EX_out), 			
								.A_out(A_out),
								.B_out(B_out),					
								.Extended_out(Extended_out),		
								.IF_ID_instrHigher_out(IF_ID_instrHigher_out),
								.IF_ID_instrLower_out(IF_ID_instrLower_out), //Higher
								.IF_ID_npc_out(IF_ID_npc_out)	
								);

   I_FETCH I_FETCH1(.IF_ID_instr(IF_ID_instr),
                    .IF_ID_npc(IF_ID_npc),
                    .EX_MEM_PCSrc(PCSrc),
                    .EX_MEM_NPC(ex_mem_adder_out) );
						  
						  
	I_EXECUTE I_EXECUTE1(	//adder module
									.adder_1(IF_ID_npc_out),
									.adder_2(Extended_out),
								
									//ALU module
									.ALU_A(A_out),
									
									//ALU control
									.ALU_control_funct(Extended_out[5:0]),
									.ALU_control_alu_op(EX_out[2:1]),//////////////
									
									//Bottom_mux 
									.bottom_mux_a(IF_ID_instrLower_out),
									.bottom_mux_b(IF_ID_instrHigher_out),
									.bottom_mux_regDst(EX_out[3]),
							
									//mux2
									.mux2_a(Extended_out),
									.mux2_b(B_out),
									.mux2_sel(EX_out[0]),///////
							
									//Inputs latch
									.readData2(B_out),
									.ctwb_in(WB_out),
									.ctlm_in(M_out),
							
									//Outputs: Latch
									.ex_mem_ctwb_out(ex_mem_ctwb_out),
									.ex_mem_ctlm_out(ex_mem_ctlm_out),
									.ex_mem_adder_out(ex_mem_adder_out),
									.ex_mem_zero_out(ex_mem_zero_out),
									.ex_mem_aluout_out(ex_mem_aluout_out),
									.ex_mem_readdat_out(ex_mem_readdat_out),
									.ex_mem_mux_out(ex_mem_mux_out)	
							);
							
							
							
	I_MEMORY I_memory1(	//And Gate Signals
								.m_ctl_out(ex_mem_ctlm_out[0]),	///////////////////
								.zero(ex_mem_zero_out),
								.PCSrc(PCSrc),
						
								//mem_wb signals
								.control_wb_in(ex_mem_ctwb_out),
								.ALU_result_in(ex_mem_aluout_out),
								.write_reg_in(ex_mem_mux_out),
					
								.mem_control_wb(mem_control_wb),
								.mem_read_data_out(mem_read_data),
								.mem_alu_result_out(mem_ALU_result),
								.mem_write_reg(mem_write_reg),
						
								//D_mem signals
								.address(ex_mem_aluout_out),
								.write_data(ex_mem_readdat_out),
								.MemWrite(ex_mem_ctlm_out[1]),   	////////////////////
								.MemRead(ex_mem_ctlm_out[2])		////////////////////
							);
	
	
	mux mux_lab_5	( 	.y(wb_mux_out),     // Output of Multiplexer
							.a(mem_read_data),				      //ex_mem_mux_out),     // Input 1 of Multiplexer
							.b(mem_ALU_result),     // Input 0 of Multiplexer
							.sel(mem_control_wb[0])
						);
						
						
		
							
			
   initial begin
   EX_MEM_PCSrc <= 0;
   EX_MEM_NPC <= 0;
   end
   
// Here you will add I_DECODE.  You will have to declare wires to make 
// the connections between the I_FETCH and I_DECODE modules

endmodule // pipeline