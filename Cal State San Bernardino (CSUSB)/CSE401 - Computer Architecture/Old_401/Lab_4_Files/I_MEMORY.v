`timescale 1ns / 1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #3: Instruction Execute Stage

//                              -*- Mode: Verilog -*-
// Filename        : I_MEMORY.v
// Description     : Top level module of the memory portion of the data-path. 

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 5/16/11
module I_MEMORY(	//And Gate Signals
						input wire m_ctl_out,
						input wire zero,
						output wire PCSrc,
						
						//mem_wb signals
						input wire [1:0] control_wb_in,
						//input wire [31:0] read_data_in,
						input wire [31:0]	ALU_result_in,
						input wire [4:0] write_reg_in,
					
						output wire [1:0] mem_control_wb,
						output wire [31:0] mem_read_data_out,
						//output wire [31:0] mem_ALU_result,
						output wire [4:0] mem_write_reg,
						output wire [31:0] mem_alu_result_out,  //Result of ALU straight throught he latch, heading to mux in lab 5. 
						
						//D_mem signals
						input wire [31:0] address,
						input wire [31:0] write_data,
						input wire MemWrite,
						input wire MemRead		
						
    );

	wire [31:0] read_data;

	and_gate and_gate1(	.m_ctl_out(m_ctl_out),
								.zero(zero),
								.PCSrc(PCSrc)
    );
	 
	 
	 
	 
	 mem_wb mem_wb1(	.control_wb_in(control_wb_in),
				.read_data_in(read_data),
				.ALU_result_in(ALU_result_in),
				.write_reg_in(write_reg_in),
					
				.mem_control_wb(mem_control_wb),
				.read_data(mem_read_data_out),
				.mem_ALU_result(mem_alu_result_out),  ///// previously: mem_control_wb),
				.mem_write_reg(mem_write_reg)
    );
	 
	 
	D_MEM D_MEM1(		.address(address),
					.write_data(write_data),
					.MemWrite(MemWrite),
					.MemRead(MemRead),
					.read_data(read_data)
    );



endmodule
