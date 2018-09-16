`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:58:02 03/05/2013 
// Design Name: 
// Module Name:    Nibble_Reg 
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


module Nibble_Reg(
	input [3:0] data_in,
	input load, out_en,
	output [3:0] data_out
);

// wires between flip flops

wire [3:0] dff_out;

// tri state gates

bufif0 t0(data_out[0], dff_out[0], out_en);
bufif0 t1(data_out[1], dff_out[1], out_en);
bufif0 t2(data_out[2], dff_out[2], out_en);
bufif0 t3(data_out[3], dff_out[3], out_en);

// d flip flops

D_FF Reg_Bit_0(.Q(dff_out[0]),.D(data_in[0]),.clk(load));
D_FF Reg_Bit_1(.Q(dff_out[1]),.D(data_in[1]),.clk(load));
D_FF Reg_Bit_2(.Q(dff_out[2]),.D(data_in[2]),.clk(load));
D_FF Reg_Bit_3(.Q(dff_out[3]),.D(data_in[3]),.clk(load));

endmodule
