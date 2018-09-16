`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:00:58 03/12/2013 
// Design Name: 
// Module Name:    Lab8 
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


module Lab8(
	input wire clk,
	input wire [0:0] btn,  
	output wire [3:0] an,
	output wire [7:0] sseg
);


wire [3:0] hexDigit0;
wire [3:0] hexDigit1;
wire [3:0] hexDigit2;

wire [7:0] seg0;
wire [7:0] seg1;
wire [7:0] seg2;

wire newClk;

localparam [7:0] DISABLED_DISPLAY = 8'b11111111;

JumpDivider32 jump(.clk(clk),.tick(newClk));


ThreeDigit_BCD tdb(.clk(newClk),.reset(btn),.bit0(hexDigit0),.bit1(hexDigit1),.bit2(hexDigit2));

hex_to_sseg sseg_unit_0
      ( .hex( hexDigit0 ), .dp( 1'b1 ), .sseg( seg0 ) );	
		
hex_to_sseg sseg_unit_1
      ( .hex( hexDigit1 ), .dp( 1'b1 ), .sseg( seg1 ) );

hex_to_sseg sseg_unit_2
      ( .hex( hexDigit2 ), .dp( 1'b1 ), .sseg( seg2 ) );

   disp_mux disp_unit
      ( .clk( clk ), .reset( 1'b0 ), .in0( seg0 ), .in1( seg1 ),
        .in2( seg2 ), .in3( DISABLED_DISPLAY ), .an( an ), .sseg( sseg ) );	


endmodule
