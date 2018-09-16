`timescale 1ns / 1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #3: Instruction Execute Stage

//                              -*- Mode: Verilog -*-
// Filename        : and_gate.v
// Description     : Typical And gate

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 5/17/11
module and_gate(	input wire m_ctl_out,
						input wire zero,
						output reg PCSrc
    );
initial begin
	PCSrc = 0;
end
	
always@*
begin
	PCSrc <= m_ctl_out && zero;
end

endmodule
