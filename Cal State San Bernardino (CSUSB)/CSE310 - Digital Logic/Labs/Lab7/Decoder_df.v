`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:59:14 03/05/2013 
// Design Name: 
// Module Name:    Decoder_df 
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


module Decoder_df(
	output [3:0] d_out,
	input en,
	input [1:0] d_in
);

assign d_out[0] = !(!(d_out[0]) && !(d_out[1]) && !(en));
assign d_out[1] = !((d_out[0]) && !(d_out[1]) && !(en));
assign d_out[2] = !(!(d_out[0]) && (d_out[1]) && !(en));
assign d_out[3] = !((d_out[0]) && (d_out[1]) && !(en));

endmodule


