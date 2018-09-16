`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:42:14 04/19/2011 
// Design Name: 
// Module Name:    REG 
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
module REG(
    input [4:0] rs,
    input [4:0] rt,
    input [4:0] rd,
    input [31:0] writedata,
    input regwrite,
    output reg [31:0] A,
    output reg [31:0] B
    );

	reg [31:0] register [31:0];
	
	integer i;
	
initial
begin
 A<=0;
 B<=0;
 for(i=0; i <= 31; i = i+1)
	register[i] <= i;
end

//read out values A and B;
always@* 
begin
	A = register[rs];
	B = register[rt];
end

//Write data in and modify at a given input address
always@*
begin
	if(regwrite)
	begin
		#0.5 register[rd] <= writedata; //Waits .5ns so that the module can read before writing.
	end
		
end



endmodule
