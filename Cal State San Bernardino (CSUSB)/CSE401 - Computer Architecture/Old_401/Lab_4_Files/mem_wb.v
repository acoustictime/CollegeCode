`timescale 1ns / 1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #3: Instruction Execute Stage

//                              -*- Mode: Verilog -*-
// Filename        : mem_wb.v
// Description     : latch betweent he memory and the writeback portions of the data-path.

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 5/18/11
module mem_wb(	input wire [1:0] control_wb_in,
					input wire [31:0] read_data_in,
					input wire [31:0]	ALU_result_in,
					input wire [4:0] write_reg_in,
					
					output reg [1:0] mem_control_wb,
					output reg [31:0] read_data,
					output reg [31:0]	mem_ALU_result,
					output reg [4:0] mem_write_reg
					
    );

   initial begin
      mem_control_wb <= 0;
		read_data <= 0;
		mem_ALU_result <= 0;
		mem_write_reg <= 0;
   end
   always @* begin
      #1 mem_control_wb <= control_wb_in;
			read_data <= read_data_in;
			mem_ALU_result <= ALU_result_in;
			mem_write_reg <= write_reg_in;
   end
endmodule
