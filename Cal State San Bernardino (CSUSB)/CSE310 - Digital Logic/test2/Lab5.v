`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:33:16 02/12/2013 
// Design Name: 
// Module Name:    Lab5 
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
module Lab5(

	input wire [7:0] sw,
	input wire btn,
	output wire [3:0] an,
	output wire z,
	output wire x
    );



	FourBitAddrSub fb(
	.a(sw[3:0]),
	.b(sw[7:4]),
	.c0(btn),
	.s(an[3:0]),
	.c4(x),
	.v(z)
	);
	
	


	
endmodule
