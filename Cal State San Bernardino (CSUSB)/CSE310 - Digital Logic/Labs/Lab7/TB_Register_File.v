`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:10:10 03/05/2013
// Design Name:   Register_File
// Module Name:   C:/Documents and Settings/user/Desktop/Lab7/TB_Register_File.v
// Project Name:  Lab7
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Register_File
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TB_Register_File;

	// Inputs
	reg [3:0] data_in;
	reg [1:0] read_add;
	reg [1:0] write_add;
	reg read_en;
	reg write_en;

	// Outputs
	wire [3:0] data_out;

	// Instantiate the Unit Under Test (UUT)
	Register_File uut (
		.data_in(data_in), 
		.read_add(read_add), 
		.write_add(write_add), 
		.read_en(read_en), 
		.write_en(write_en), 
		.data_out(data_out)
	);

	initial begin
		// Initialize Inputs
		read_en = 0;
		write_en = 0;
		data_in = 4'b0000;
		read_add = 2'b00;
		write_add = 2'b00;

		#20;
		
		read_en = 1;
		write_en = 0;
		write_add = 2'b11;
		data_in = 4'b0001;
		
		#20;
      
		read_en = 0;
		write_en = 1;
		read_add = 2'b11;
		
		#20;
		
		read_en = 1;
		write_en = 0;
		write_add = 2'b10;
		data_in = 4'b1111;
		
		#20;
      
		read_en = 0;
		write_en = 1;
		read_add = 2'b10;
		
		#20;
		
		read_en = 1;
		write_en = 0;
		write_add = 2'b00;
		data_in = 4'b1010;
		
		#20;
      
		read_en = 0;
		write_en = 1;
		read_add = 2'b00;
		
		#20;



		
	end
      
endmodule

