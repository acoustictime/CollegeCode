`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #2: Instruction Decode Stage

//                              -*- Mode: Verilog -*-
// Filename        : ex_mem.v
// Description     : Latch between execute and memory stage 

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 5/10/11
//////////////////////////////////////////////////////////////////////////////////
module ex_mem(	input wire [1:0] ctwb_in,
					input wire [2:0] ctlm_in,
					input wire [31:0] adder_in,
					input wire zero_in,
					input wire [31:0] aluout_in,
					input wire [31:0] readdat_in,
					input wire [4:0] mux_in,
					
					output reg [1:0] ctwb_out,
					output reg [2:0] ctlm_out,
					output reg [31:0] adder_out,
					output reg zero_out,
					output reg [31:0] aluout_out,
					output reg [31:0] readdat_out,
					output reg [31:0] mux_out
    );


	initial begin
      ctwb_out <= 0;	
		ctlm_out <= 0;     		
		adder_out <= 0;	
		zero_out <= 0;
		aluout_out <= 0;			
		readdat_out <= 0;		
		mux_out <= 0;
   end
	
   always @* 
	begin
      #1 ctwb_out <= ctwb_in;	
			ctlm_out <= ctlm_in;     		
			adder_out <= adder_in;	
			zero_out <= zero_in;
			aluout_out <= aluout_in;			
			readdat_out <= readdat_in;		
			mux_out <= mux_in;
	end

endmodule
