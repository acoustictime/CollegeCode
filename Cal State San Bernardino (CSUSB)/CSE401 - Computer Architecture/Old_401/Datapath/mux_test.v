`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:08:41 04/05/2012
// Design Name:   mux
// Module Name:   C:/Users/003834323/Desktop/CSE401/Datapath/mux_test.v
// Project Name:  Datapath
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mux
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module mux_test;
	reg [31:0] a, b;
	reg sel;

	wire [31:0] out;
	// wire [31:0] pc_adder;
	initial
		begin
			a <= 32'h0000ffff;
			b <= 32'hffff0000;
			c <= 0;
			#10
			c <= 1;
			#10
			c <= 0;
			#10 $finish;
		end


	mux mux_unit(.in0(a), .in1(b), .sel(sel), .out(out));
	// incr adder(.in(pc_adder), .out(a));
	// pc pc_unit(.in(out), .out(pc_adder));

endmodule // mux_test

