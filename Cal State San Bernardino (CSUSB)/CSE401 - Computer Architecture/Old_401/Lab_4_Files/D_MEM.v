`timescale 1ns / 1ps
// Class: CSCI 401 Computer Architecture
// Term: SPR11
// Name(s): Chris Glaubig, Ahmed Khayyat
//
// Lab #3: Instruction Execute Stage

//                              -*- Mode: Verilog -*-
// Filename        : D_MEM.v
// Description     : 

// Authors         : Chris Glaubig, Ahmed Khayyat
// Created On      : 5/3/11
module D_MEM(	input wire [31:0] address,
					input wire [31:0] write_data,
					input wire MemWrite,
					input wire MemRead,
					output reg [31:0] read_data
    );
	
	// Register Declarations
   reg [31:0] MEM[0:255];  // 128 words of 32-bit memory
	wire MemReadTest = 1;

	integer i;
	
	initial
	begin
		//$readmemb("data.txt",MEM);
		//for (i=0; i<6; i=i+1)
			//$display(MEM[1]);	
		MEM[0] = 'b0000_0000_0000_0000_0000_0000_0000_0000;		//Data 0
		MEM[1] = 'b0000_0000_0000_0000_0000_0000_0000_0001;		//Data 1
		MEM[2] = 'b0000_0000_0000_0000_0000_0000_0000_0010;		//Data 2
		MEM[3] = 'b0000_0000_0000_0000_0000_0000_0000_0011;		//Data 3
		MEM[4] = 'b0000_0000_0000_0000_0000_0000_0000_0100;		//Data 4
		MEM[5] = 'b0000_0000_0000_0000_0000_0000_0000_0101;		//Data 5	
	/*
	//	A<=0;
		//B<=0;
		for(i=0; i <= 255; i = i+1)
			MEM[i] <= 0;
	*/
	end

	always@* 
	begin
		//if(MemRead==1)
		if(MemRead==1)
		begin 
			read_data <= MEM[address];
		end
		else
		begin
			read_data <= 0;
		end
		
		if(MemWrite==1)
		begin
			#0.5 MEM[address] = write_data;
		end
	end



endmodule
