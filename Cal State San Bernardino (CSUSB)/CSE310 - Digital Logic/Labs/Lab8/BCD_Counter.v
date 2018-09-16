`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:00:13 03/12/2013 
// Design Name: 
// Module Name:    BCD_Counter 
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


module BCD_Counter(
	input wire clk,
	input wire reset,
	output reg [3:0] Q
);

// state register

reg [3:0] state = 9, next_state = 0;

always @ (negedge clk, posedge reset)
begin
	if (reset == 1)
		state <= 0;
	else
		state <= next_state;
	 
end

always @ *
	 Q = state;

always @ (posedge clk)
begin
	if (state == 9)
		next_state = 0;
	else
		next_state = state + 1;
end

endmodule