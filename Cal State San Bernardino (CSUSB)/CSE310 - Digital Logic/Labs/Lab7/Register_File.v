`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:02:14 03/05/2013 
// Design Name: 
// Module Name:    Register_File 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////

module Register_File(
	input [3:0] data_in,
	input [1:0] read_add,write_add,
	input read_en,write_en,
	output [3:0] data_out
);

wire [3:0] read_sel, write_sel;
//wire [3:0] write_sel2;

// decoders

Decoder_df Dec_Read(.en(read_en), .d_in(read_add), .d_out(read_sel));
Decoder_df Dec_Write(.en(write_en), .d_in(write_add), .d_out(write_sel));

// Registers

Nibble_Reg Reg_0(.data_out(data_out),.data_in(data_in),.load(write_sel[0]),.out_en(read_sel[0]));
Nibble_Reg Reg_1(.data_out(data_out),.data_in(data_in),.load(write_sel[1]),.out_en(read_sel[1]));
Nibble_Reg Reg_2(.data_out(data_out),.data_in(data_in),.load(write_sel[2]),.out_en(read_sel[2]));
Nibble_Reg Reg_3(.data_out(data_out),.data_in(data_in),.load(write_sel[3]),.out_en(read_sel[3]));

endmodule
