`timescale 1ns / 1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #3: Instruction Execute Stage

//                              -*- Mode: Verilog -*-
// Filename        : ALU_CONTROL.v
// Description     : 

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 5/3/11
module ALU_CONTROL(	input wire [5:0] funct,
							input wire [1:0] alu_op,
							output reg [2:0] select
    );


always @*
begin
		case (alu_op)
				3'b00:
				begin
					select = 3'b010;
				end
				
				3'b01:
				begin
					select = 3'b110;
				end
				3'b10:				

				begin
					//NESTED CASE BEGIN
					case (funct)
					6'b100000:
					begin
						select = 3'b010;
					end
				
					6'b100010:
					begin
						select = 3'b110;
					end
				
					6'b100100:
					begin
						select = 3'b000;
					end
					
					6'b100101:
					begin
						select = 3'b001;
					end
					
					6'b101010:
					begin
						select = 3'b111;
					end
					endcase
					//NESTED CASE END
					
				end
      endcase
end

endmodule