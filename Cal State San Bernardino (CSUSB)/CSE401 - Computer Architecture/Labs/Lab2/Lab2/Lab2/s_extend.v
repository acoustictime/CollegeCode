`timescale 1ns / 1ps

/*  s_extend.v  */

module s_extend(
    input	wire	[15:0] nextend,
    output	reg	[31:0] extend
    );

	always@ * 
	  begin
		// Replicate signed bit 16 times then cancatinate
		
		extend = {{16{nextend[15]}},nextend};
		
		end

endmodule
