`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:	CSUSB, CSE 310 LAB
// Engineer:	Dr. Haiyan Qiao, and Sean A. Finucane
// 
// Create Date:    07:33:52 10/16/2012 
// Design Name:	FPGA Implementation of hex switch input to simple sseg output.
// Module Name:	FPGA_hex_sseg 
// Project Name:	CSE 310 LAB 4 FPGA DEMO
// Target Devices:	Spartan 3, and Spartan 3E (Basys 2)
// Tool versions:	Xilinx ISE 13.4
// Description:
//
// Dependencies: hex_to_sseg.v (Pong Chu, chapter 3), disp_mux.v (Pong Chu, chapter 3 + 4)
//
// Revision: 
// Revision 0.01 - File Created
//	Revision 1.00 - First Release
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module FPGA_hex_sseg
   (
     input wire clk,
     input wire [7:0] sw,
     output wire [3:0] an,
     output wire [7:0] sseg
   );
	
	// note the use of local parameters (module constants):
	localparam [7:0] DISABLED_DISPLAY = 8'b11111111;

   // internal signal declarations:
   wire [7:0] seg0, seg1;

   // sub-module insantiations:
	
	/*	NOTE:
	 *
	 *	(1) All of the output signals to the sseg display are ACTIVE LOW.
	 *	(2) The sseg display units on the FPGA board must be TIME-DIVISION MULTIPLEXED (TDM).
	 *	    Becuase ALL of the sseg displays show the same value at any one time,
	 *	    the individual sseg diaplays must be switched on ONE AT A TIME, very quickly,
	 *		 while the appropriate symbol is configured. This switching occurs faster than
	 *		 human vision can perceive, and therefore creates the illusion of separate sseg
	 *		 display units, each one independent of the other.
	 */
	
   hex_to_sseg sseg_unit_0
      ( .hex( sw[3:0] ), .dp( 1'b1 ), .sseg( seg0 ) );	// decoder for 4 LSBs of switches
		
   hex_to_sseg sseg_unit_1
      ( .hex( sw[7:4] ), .dp( 1'b1 ), .sseg( seg1 ) );	// decoder for 4 MSBs of switches

   disp_mux disp_unit
      ( .clk( clk ), .reset( 1'b0 ), .in0( seg0 ), .in1( seg1 ),
        .in2( DISABLED_DISPLAY ), .in3( DISABLED_DISPLAY ), .an( an ), .sseg( sseg ) );		// 7-seg LED display time-multiplexing module
		 
endmodule
