`timescale 1ns/1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #2: Instruction Decode Stage

//                              -*- Mode: Verilog -*-
// Filename        : i_decode.v
// Description     : Top module for the decoding stage of the pipeline. 

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 4/25/11
//////////////////////////////////////////////////////////////////////////////////
module I_decode(	input wire [31:0] IR,
						input wire regwrite_in, 	//Not currently used
						input wire [4:0] write_reg_in, 	//Not currently used
						input wire [31:0] write_data_in,	//Not currently used
						input wire [31:0] npc, 
						
						output wire [1:0] WB_out,     		
						output wire [2:0] M_out,     		
						output wire [4:0] EX_out, 			
						output wire [31:0] A_out,
						output wire [31:0] B_out,					
						output wire [31:0] Extended_out,		
						output wire [20:16] IF_ID_instrHigher_out,
						output wire [15:11] IF_ID_instrLower_out,
						output wire [31:0] IF_ID_npc_out	
    );

	// Module connecting wires
	wire [31:0] a_between;
	wire [31:0] b_between;
	wire [1:0] WB;    		
	wire [2:0] M;  		
	wire [4:0] EX;
	wire [31:0] extended_between;
	wire [1:0] wb_between;    	
	wire [2:0] m_between;  		
	wire [4:0] ex_between;
	


	REG REG1 (	.rs(IR[25:21]),
					.rt(IR[20:16]),
					.rd(write_reg_in),
					.writedata(write_data_in),
					.regwrite(regwrite_in),
					.A(a_between),
					.B(b_between)
					);
   


	control  control1(
					.WB(wb_between),     		
					.M(m_between),     		
					.EX(ex_between),  			
					.opcode(IR[31:26])
					);    	
   


	s_extend s_extend1(	
					.IF_ID_instr(IR[15:0]),
					.Extended(extended_between) 
					);




	id_ex id_ex1(.WB_in(wb_between),     	
					.M_in(m_between),     		
					.EX_in(ex_between),  			
					.A(a_between),
					.B(b_between),				
					.Extended(extended_between),		
					.IF_ID_instrHigher(IR[20:16]),
					.IF_ID_instrLower(IR[15:11]),
					.IF_ID_npc(npc),
					.WB_out(WB_out),     		
					.M_out(M_out),     		
					.EX_out(EX_out),
					.A_out(A_out),
					.B_out(B_out),					
					.Extended_out(Extended_out),		
					.IF_ID_instrHigher_out(IF_ID_instrHigher_out),
					.IF_ID_instrLower_out(IF_ID_instrLower_out),
					.IF_ID_npc_out(IF_ID_npc_out) 
					);
   

endmodule
