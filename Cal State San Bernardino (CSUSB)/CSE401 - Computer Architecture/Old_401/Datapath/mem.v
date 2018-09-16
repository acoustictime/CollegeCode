`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:38:05 04/05/2012 
// Design Name: 
// Module Name:    mem 
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
module mem(output [31:0] mem_data,
			  input  [31:0] mem_addr);
			  
	reg [31:0] mem[0:9];
	assign mem_data=mem[mem_addr];
	
	initial
	begin
	mem[0] <= 32'hA00000AA;
	mem[1] <= 32'h10000011;
	mem[2] <= 32'h20000022;
	mem[3] <= 32'h30000033;
	mem[4] <= 32'h40000044;
	mem[5] <= 32'h50000055;
	mem[6] <= 32'h60000066;
	mem[7] <= 32'h70000077;
	mem[8] <= 32'h80000088;
	mem[9] <= 32'h90000099;
	end


endmodule
