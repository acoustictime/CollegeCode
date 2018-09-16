`timescale 1ns/1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #2: Instruction Decode Stage

//                              -*- Mode: Verilog -*-
// Filename        : id_ex.v
// Description     : Buffer to syncronize the timing between stages of the pipeline. 

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 4/25/11
//////////////////////////////////////////////////////////////////////////////////
module id_ex(	input wire [1:0] WB_in,     	
					input wire [2:0] M_in,     		
					input wire [4:0] EX_in,  			// Control outputs.
					input wire [31:0] A,
					input wire [31:0] B,					// Reg outputs
					input wire [31:0] Extended,		// s_extend outputs
					input wire [20:16] IF_ID_instrHigher,
					input wire [15:11] IF_ID_instrLower,
					input wire [31:0] IF_ID_npc,		// i_fetch output
					output reg [1:0] WB_out,     		
					output reg [2:0] M_out,     		
					output reg [4:0] EX_out, 			// Control bits out
					output reg [31:0] A_out,
					output reg [31:0] B_out,					
					output reg [31:0] Extended_out,		
					output reg [20:16] IF_ID_instrHigher_out,
					output reg [15:11] IF_ID_instrLower_out,
					output reg [31:0] IF_ID_npc_out	
    );

	   initial begin
      WB_out <= 0;	
		M_out <= 0;     		
		EX_out <= 0;	
		A_out <= 0;
		B_out <= 0;			
		Extended_out <= 0;		
		IF_ID_instrHigher_out <= 0;
		IF_ID_instrLower_out <= 0;
		IF_ID_npc_out <= 0;
   end
   always @* begin
      #1 WB_out <= WB_in;	
			M_out <= M_in;     		
			EX_out <= EX_in;	
			A_out <= A;
			B_out <= B;			
			Extended_out <= Extended;		
			IF_ID_instrHigher_out <= IF_ID_instrHigher;
			IF_ID_instrLower_out <= IF_ID_instrLower;
			IF_ID_npc_out <= IF_ID_npc;
		end

endmodule
