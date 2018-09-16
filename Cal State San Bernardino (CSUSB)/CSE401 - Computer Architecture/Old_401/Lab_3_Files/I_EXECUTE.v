`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #2: Instruction Decode Stage

//                              -*- Mode: Verilog -*-
// Filename        : I_EXECUTE.v
// Description     : Inputs 5 bits 

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 5/10/11
//////////////////////////////////////////////////////////////////////////////////
module I_EXECUTE(		//Adder
							input wire [31:0] adder_1,
							input wire [31:0] adder_2,
							
							//ALU
							input wire [31:0] ALU_A,
							//input wire [2:0] ALU_control,
							
							//ALU Control
							input wire [5:0] ALU_control_funct,
							input wire [1:0] ALU_control_alu_op,
							
							//Bottom Mux
							input wire [4:0] bottom_mux_a,
							input wire [4:0] bottom_mux_b,
							input wire bottom_mux_regDst,
							
							//Straight to the latch
							input wire [31:0] readData2, //From the ID_ex
							input wire [1:0] ctwb_in,
							input wire [2:0] ctlm_in,
							
							//Mux2
							input wire [31:0] mux2_a,
							input wire [31:0] mux2_b,
							input wire mux2_sel,
							
							output wire [1:0] ex_mem_ctwb_out,
							output wire [2:0] ex_mem_ctlm_out,
							output wire [31:0] ex_mem_adder_out,
							output wire ex_mem_zero_out,
							output wire [31:0] ex_mem_aluout_out,
							output wire [31:0] ex_mem_readdat_out,
							output wire [31:0] ex_mem_mux_out					
    );

	wire [31:0] adder_out;
	wire [31:0] ALU_result;
	wire ALU_zero;
	wire [4:0] bottom_mux_y;
	wire [31:0] mux2_y;   
	wire [2:0] alu_out_select;



	ADDER ADDER1(	.add_input_1(adder_1),
						.add_input_2(adder_2),
						.add_output(adder_out)
    );
	
	ALU ALU1(	.A(ALU_A),
					.B(mux2_y),
					.control(alu_out_select),//////////////////
					.zero(ALU_zero),
					.result(ALU_result)
    );
   
	ALU_CONTROL ALU_CONTROL1(	.funct(ALU_control_funct),
										.alu_op(ALU_control_alu_op),/////////////////////
										.select(alu_out_select)
    );

	bottom_mux bottom_mux1(
									.y(bottom_mux_y),     
									.a(bottom_mux_a),     
									.b(bottom_mux_b),     
									.regDst(bottom_mux_regDst) 
   );
	
	mux mux2(	.y(mux2_y),     
					.a(mux2_a),    
               .b(mux2_b),     
					.sel(mux2_sel)          
   );
	
	ex_mem ex_mem1(	.ctwb_in(ctwb_in),
							.ctlm_in(ctlm_in),
							.adder_in(adder_out),
							.zero_in(ALU_zero),
							.aluout_in(ALU_result),
							.readdat_in(readData2),
							.mux_in(bottom_mux_y),
					
							.ctwb_out(ex_mem_ctwb_out),
							.ctlm_out(ex_mem_ctlm_out),
							.adder_out(ex_mem_adder_out),
							.zero_out(ex_mem_zero_out),
							.aluout_out(ex_mem_aluout_out),
							.readdat_out(ex_mem_readdat_out),
							.mux_out(ex_mem_mux_out)
    );
	
endmodule
