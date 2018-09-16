////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2011 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: O.61xd
//  \   \         Application: netgen
//  /   /         Filename: FPGA_hex_sseg_synthesis.v
// /___/   /\     Timestamp: Tue Feb 19 12:30:17 2013
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim FPGA_hex_sseg.ngc FPGA_hex_sseg_synthesis.v 
// Device	: xc3s200-4-ft256
// Input file	: FPGA_hex_sseg.ngc
// Output file	: C:\Documents and Settings\user\Desktop\test2\netgen\synthesis\FPGA_hex_sseg_synthesis.v
// # of Modules	: 1
// Design Name	: FPGA_hex_sseg
// Xilinx        : C:\Xilinx\13.2\ISE_DS\ISE\
//             
// Purpose:    
//     This verilog netlist is a verification model and uses simulation 
//     primitives which may not represent the true implementation of the 
//     device, however the netlist is functionally correct and should not 
//     be modified. This file cannot be synthesized and should only be used 
//     with supported simulation tools.
//             
// Reference:  
//     Command Line Tools User Guide, Chapter 23 and Synthesis and Simulation Design Guide, Chapter 6
//             
////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns/1 ps

module FPGA_hex_sseg (
  c4, clk, an, hexOut, sseg, temp, led, btn, sw
);
  output c4;
  input clk;
  output [3 : 0] an;
  output [3 : 0] hexOut;
  output [7 : 0] sseg;
  output [3 : 0] temp;
  output [0 : 0] led;
  input [1 : 1] btn;
  input [7 : 0] sw;
  wire N0;
  wire N1;
  wire N36;
  wire N38;
  wire N40;
  wire N42;
  wire N44;
  wire N46;
  wire N48;
  wire N50;
  wire N51;
  wire an_0_OBUF_33;
  wire an_1_OBUF_34;
  wire an_2_OBUF_35;
  wire an_3_OBUF_36;
  wire btn_1_IBUF_38;
  wire c4_OBUF_40;
  wire clk_BUFGP_42;
  wire \disp_unit/Mcount_q_reg_cy<10>_rt_45 ;
  wire \disp_unit/Mcount_q_reg_cy<11>_rt_47 ;
  wire \disp_unit/Mcount_q_reg_cy<12>_rt_49 ;
  wire \disp_unit/Mcount_q_reg_cy<13>_rt_51 ;
  wire \disp_unit/Mcount_q_reg_cy<14>_rt_53 ;
  wire \disp_unit/Mcount_q_reg_cy<15>_rt_55 ;
  wire \disp_unit/Mcount_q_reg_cy<16>_rt_57 ;
  wire \disp_unit/Mcount_q_reg_cy<1>_rt_59 ;
  wire \disp_unit/Mcount_q_reg_cy<2>_rt_61 ;
  wire \disp_unit/Mcount_q_reg_cy<3>_rt_63 ;
  wire \disp_unit/Mcount_q_reg_cy<4>_rt_65 ;
  wire \disp_unit/Mcount_q_reg_cy<5>_rt_67 ;
  wire \disp_unit/Mcount_q_reg_cy<6>_rt_69 ;
  wire \disp_unit/Mcount_q_reg_cy<7>_rt_71 ;
  wire \disp_unit/Mcount_q_reg_cy<8>_rt_73 ;
  wire \disp_unit/Mcount_q_reg_cy<9>_rt_75 ;
  wire \disp_unit/Mcount_q_reg_xor<17>_rt_77 ;
  wire \f0/c2 ;
  wire \f0/c3 ;
  wire \f0/fa_1/ha_1/Mxor_S_Result1 ;
  wire \f0/fa_1/ha_1/Mxor_S_Result11 ;
  wire led_0_OBUF_101;
  wire sseg_0_OBUF_110;
  wire sseg_1_OBUF_111;
  wire sseg_2_OBUF_112;
  wire sseg_3_OBUF_113;
  wire sseg_4_OBUF_114;
  wire sseg_5_OBUF_115;
  wire sseg_6_OBUF_116;
  wire sw_0_IBUF_125;
  wire sw_1_IBUF_126;
  wire sw_2_IBUF_127;
  wire sw_3_IBUF_128;
  wire sw_4_IBUF_129;
  wire sw_5_IBUF_130;
  wire sw_6_IBUF_131;
  wire sw_7_IBUF_132;
  wire temp_0_OBUF_137;
  wire temp_1_OBUF_138;
  wire temp_2_OBUF_139;
  wire temp_3_OBUF_140;
  wire [17 : 0] Result;
  wire [16 : 0] \disp_unit/Mcount_q_reg_cy ;
  wire [0 : 0] \disp_unit/Mcount_q_reg_lut ;
  wire [17 : 0] \disp_unit/q_reg ;
  GND   XST_GND (
    .G(N0)
  );
  VCC   XST_VCC (
    .P(N1)
  );
  FD   \disp_unit/q_reg_0  (
    .C(clk_BUFGP_42),
    .D(Result[0]),
    .Q(\disp_unit/q_reg [0])
  );
  FD   \disp_unit/q_reg_1  (
    .C(clk_BUFGP_42),
    .D(Result[1]),
    .Q(\disp_unit/q_reg [1])
  );
  FD   \disp_unit/q_reg_2  (
    .C(clk_BUFGP_42),
    .D(Result[2]),
    .Q(\disp_unit/q_reg [2])
  );
  FD   \disp_unit/q_reg_3  (
    .C(clk_BUFGP_42),
    .D(Result[3]),
    .Q(\disp_unit/q_reg [3])
  );
  FD   \disp_unit/q_reg_4  (
    .C(clk_BUFGP_42),
    .D(Result[4]),
    .Q(\disp_unit/q_reg [4])
  );
  FD   \disp_unit/q_reg_5  (
    .C(clk_BUFGP_42),
    .D(Result[5]),
    .Q(\disp_unit/q_reg [5])
  );
  FD   \disp_unit/q_reg_6  (
    .C(clk_BUFGP_42),
    .D(Result[6]),
    .Q(\disp_unit/q_reg [6])
  );
  FD   \disp_unit/q_reg_7  (
    .C(clk_BUFGP_42),
    .D(Result[7]),
    .Q(\disp_unit/q_reg [7])
  );
  FD   \disp_unit/q_reg_8  (
    .C(clk_BUFGP_42),
    .D(Result[8]),
    .Q(\disp_unit/q_reg [8])
  );
  FD   \disp_unit/q_reg_9  (
    .C(clk_BUFGP_42),
    .D(Result[9]),
    .Q(\disp_unit/q_reg [9])
  );
  FD   \disp_unit/q_reg_10  (
    .C(clk_BUFGP_42),
    .D(Result[10]),
    .Q(\disp_unit/q_reg [10])
  );
  FD   \disp_unit/q_reg_11  (
    .C(clk_BUFGP_42),
    .D(Result[11]),
    .Q(\disp_unit/q_reg [11])
  );
  FD   \disp_unit/q_reg_12  (
    .C(clk_BUFGP_42),
    .D(Result[12]),
    .Q(\disp_unit/q_reg [12])
  );
  FD   \disp_unit/q_reg_13  (
    .C(clk_BUFGP_42),
    .D(Result[13]),
    .Q(\disp_unit/q_reg [13])
  );
  FD   \disp_unit/q_reg_14  (
    .C(clk_BUFGP_42),
    .D(Result[14]),
    .Q(\disp_unit/q_reg [14])
  );
  FD   \disp_unit/q_reg_15  (
    .C(clk_BUFGP_42),
    .D(Result[15]),
    .Q(\disp_unit/q_reg [15])
  );
  FD   \disp_unit/q_reg_16  (
    .C(clk_BUFGP_42),
    .D(Result[16]),
    .Q(\disp_unit/q_reg [16])
  );
  FD   \disp_unit/q_reg_17  (
    .C(clk_BUFGP_42),
    .D(Result[17]),
    .Q(\disp_unit/q_reg [17])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<0>  (
    .CI(N0),
    .DI(N1),
    .S(\disp_unit/Mcount_q_reg_lut [0]),
    .O(\disp_unit/Mcount_q_reg_cy [0])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<0>  (
    .CI(N0),
    .LI(\disp_unit/Mcount_q_reg_lut [0]),
    .O(Result[0])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<1>  (
    .CI(\disp_unit/Mcount_q_reg_cy [0]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<1>_rt_59 ),
    .O(\disp_unit/Mcount_q_reg_cy [1])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<1>  (
    .CI(\disp_unit/Mcount_q_reg_cy [0]),
    .LI(\disp_unit/Mcount_q_reg_cy<1>_rt_59 ),
    .O(Result[1])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<2>  (
    .CI(\disp_unit/Mcount_q_reg_cy [1]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<2>_rt_61 ),
    .O(\disp_unit/Mcount_q_reg_cy [2])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<2>  (
    .CI(\disp_unit/Mcount_q_reg_cy [1]),
    .LI(\disp_unit/Mcount_q_reg_cy<2>_rt_61 ),
    .O(Result[2])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<3>  (
    .CI(\disp_unit/Mcount_q_reg_cy [2]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<3>_rt_63 ),
    .O(\disp_unit/Mcount_q_reg_cy [3])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<3>  (
    .CI(\disp_unit/Mcount_q_reg_cy [2]),
    .LI(\disp_unit/Mcount_q_reg_cy<3>_rt_63 ),
    .O(Result[3])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<4>  (
    .CI(\disp_unit/Mcount_q_reg_cy [3]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<4>_rt_65 ),
    .O(\disp_unit/Mcount_q_reg_cy [4])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<4>  (
    .CI(\disp_unit/Mcount_q_reg_cy [3]),
    .LI(\disp_unit/Mcount_q_reg_cy<4>_rt_65 ),
    .O(Result[4])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<5>  (
    .CI(\disp_unit/Mcount_q_reg_cy [4]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<5>_rt_67 ),
    .O(\disp_unit/Mcount_q_reg_cy [5])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<5>  (
    .CI(\disp_unit/Mcount_q_reg_cy [4]),
    .LI(\disp_unit/Mcount_q_reg_cy<5>_rt_67 ),
    .O(Result[5])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<6>  (
    .CI(\disp_unit/Mcount_q_reg_cy [5]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<6>_rt_69 ),
    .O(\disp_unit/Mcount_q_reg_cy [6])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<6>  (
    .CI(\disp_unit/Mcount_q_reg_cy [5]),
    .LI(\disp_unit/Mcount_q_reg_cy<6>_rt_69 ),
    .O(Result[6])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<7>  (
    .CI(\disp_unit/Mcount_q_reg_cy [6]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<7>_rt_71 ),
    .O(\disp_unit/Mcount_q_reg_cy [7])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<7>  (
    .CI(\disp_unit/Mcount_q_reg_cy [6]),
    .LI(\disp_unit/Mcount_q_reg_cy<7>_rt_71 ),
    .O(Result[7])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<8>  (
    .CI(\disp_unit/Mcount_q_reg_cy [7]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<8>_rt_73 ),
    .O(\disp_unit/Mcount_q_reg_cy [8])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<8>  (
    .CI(\disp_unit/Mcount_q_reg_cy [7]),
    .LI(\disp_unit/Mcount_q_reg_cy<8>_rt_73 ),
    .O(Result[8])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<9>  (
    .CI(\disp_unit/Mcount_q_reg_cy [8]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<9>_rt_75 ),
    .O(\disp_unit/Mcount_q_reg_cy [9])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<9>  (
    .CI(\disp_unit/Mcount_q_reg_cy [8]),
    .LI(\disp_unit/Mcount_q_reg_cy<9>_rt_75 ),
    .O(Result[9])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<10>  (
    .CI(\disp_unit/Mcount_q_reg_cy [9]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<10>_rt_45 ),
    .O(\disp_unit/Mcount_q_reg_cy [10])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<10>  (
    .CI(\disp_unit/Mcount_q_reg_cy [9]),
    .LI(\disp_unit/Mcount_q_reg_cy<10>_rt_45 ),
    .O(Result[10])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<11>  (
    .CI(\disp_unit/Mcount_q_reg_cy [10]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<11>_rt_47 ),
    .O(\disp_unit/Mcount_q_reg_cy [11])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<11>  (
    .CI(\disp_unit/Mcount_q_reg_cy [10]),
    .LI(\disp_unit/Mcount_q_reg_cy<11>_rt_47 ),
    .O(Result[11])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<12>  (
    .CI(\disp_unit/Mcount_q_reg_cy [11]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<12>_rt_49 ),
    .O(\disp_unit/Mcount_q_reg_cy [12])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<12>  (
    .CI(\disp_unit/Mcount_q_reg_cy [11]),
    .LI(\disp_unit/Mcount_q_reg_cy<12>_rt_49 ),
    .O(Result[12])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<13>  (
    .CI(\disp_unit/Mcount_q_reg_cy [12]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<13>_rt_51 ),
    .O(\disp_unit/Mcount_q_reg_cy [13])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<13>  (
    .CI(\disp_unit/Mcount_q_reg_cy [12]),
    .LI(\disp_unit/Mcount_q_reg_cy<13>_rt_51 ),
    .O(Result[13])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<14>  (
    .CI(\disp_unit/Mcount_q_reg_cy [13]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<14>_rt_53 ),
    .O(\disp_unit/Mcount_q_reg_cy [14])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<14>  (
    .CI(\disp_unit/Mcount_q_reg_cy [13]),
    .LI(\disp_unit/Mcount_q_reg_cy<14>_rt_53 ),
    .O(Result[14])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<15>  (
    .CI(\disp_unit/Mcount_q_reg_cy [14]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<15>_rt_55 ),
    .O(\disp_unit/Mcount_q_reg_cy [15])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<15>  (
    .CI(\disp_unit/Mcount_q_reg_cy [14]),
    .LI(\disp_unit/Mcount_q_reg_cy<15>_rt_55 ),
    .O(Result[15])
  );
  MUXCY   \disp_unit/Mcount_q_reg_cy<16>  (
    .CI(\disp_unit/Mcount_q_reg_cy [15]),
    .DI(N0),
    .S(\disp_unit/Mcount_q_reg_cy<16>_rt_57 ),
    .O(\disp_unit/Mcount_q_reg_cy [16])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<16>  (
    .CI(\disp_unit/Mcount_q_reg_cy [15]),
    .LI(\disp_unit/Mcount_q_reg_cy<16>_rt_57 ),
    .O(Result[16])
  );
  XORCY   \disp_unit/Mcount_q_reg_xor<17>  (
    .CI(\disp_unit/Mcount_q_reg_cy [16]),
    .LI(\disp_unit/Mcount_q_reg_xor<17>_rt_77 ),
    .O(Result[17])
  );
  LUT2 #(
    .INIT ( 4'h7 ))
  \disp_unit/Mdecod_an31  (
    .I0(\disp_unit/q_reg [16]),
    .I1(\disp_unit/q_reg [17]),
    .O(an_3_OBUF_36)
  );
  LUT2 #(
    .INIT ( 4'hD ))
  \disp_unit/Mdecod_an21  (
    .I0(\disp_unit/q_reg [17]),
    .I1(\disp_unit/q_reg [16]),
    .O(an_2_OBUF_35)
  );
  LUT2 #(
    .INIT ( 4'hD ))
  \disp_unit/Mdecod_an11  (
    .I0(\disp_unit/q_reg [16]),
    .I1(\disp_unit/q_reg [17]),
    .O(an_1_OBUF_34)
  );
  LUT2 #(
    .INIT ( 4'hE ))
  \disp_unit/Mdecod_an01  (
    .I0(\disp_unit/q_reg [16]),
    .I1(\disp_unit/q_reg [17]),
    .O(an_0_OBUF_33)
  );
  LUT2 #(
    .INIT ( 4'h6 ))
  \f0/fa_0/ha_1/Mxor_S_Result1  (
    .I0(sw_4_IBUF_129),
    .I1(sw_0_IBUF_125),
    .O(temp_0_OBUF_137)
  );
  LUT4 #(
    .INIT ( 16'hBE28 ))
  \f0/fa_3/C1  (
    .I0(sw_3_IBUF_128),
    .I1(sw_7_IBUF_132),
    .I2(btn_1_IBUF_38),
    .I3(\f0/c3 ),
    .O(c4_OBUF_40)
  );
  LUT4 #(
    .INIT ( 16'h4224 ))
  \f0/Mxor_v_Result1  (
    .I0(sw_3_IBUF_128),
    .I1(\f0/c3 ),
    .I2(btn_1_IBUF_38),
    .I3(sw_7_IBUF_132),
    .O(led_0_OBUF_101)
  );
  LUT4 #(
    .INIT ( 16'h6996 ))
  \f0/fa_2/ha_1/Mxor_S_Result1  (
    .I0(sw_2_IBUF_127),
    .I1(sw_6_IBUF_131),
    .I2(btn_1_IBUF_38),
    .I3(\f0/c2 ),
    .O(temp_2_OBUF_139)
  );
  LUT4 #(
    .INIT ( 16'hBE28 ))
  \f0/fa_2/C1  (
    .I0(sw_2_IBUF_127),
    .I1(sw_6_IBUF_131),
    .I2(btn_1_IBUF_38),
    .I3(\f0/c2 ),
    .O(\f0/c3 )
  );
  LUT4 #(
    .INIT ( 16'h6996 ))
  \f0/fa_3/ha_1/Mxor_S_Result1  (
    .I0(sw_3_IBUF_128),
    .I1(sw_7_IBUF_132),
    .I2(btn_1_IBUF_38),
    .I3(\f0/c3 ),
    .O(temp_3_OBUF_140)
  );
  IBUF   btn_1_IBUF (
    .I(btn[1]),
    .O(btn_1_IBUF_38)
  );
  IBUF   sw_7_IBUF (
    .I(sw[7]),
    .O(sw_7_IBUF_132)
  );
  IBUF   sw_6_IBUF (
    .I(sw[6]),
    .O(sw_6_IBUF_131)
  );
  IBUF   sw_5_IBUF (
    .I(sw[5]),
    .O(sw_5_IBUF_130)
  );
  IBUF   sw_4_IBUF (
    .I(sw[4]),
    .O(sw_4_IBUF_129)
  );
  IBUF   sw_3_IBUF (
    .I(sw[3]),
    .O(sw_3_IBUF_128)
  );
  IBUF   sw_2_IBUF (
    .I(sw[2]),
    .O(sw_2_IBUF_127)
  );
  IBUF   sw_1_IBUF (
    .I(sw[1]),
    .O(sw_1_IBUF_126)
  );
  IBUF   sw_0_IBUF (
    .I(sw[0]),
    .O(sw_0_IBUF_125)
  );
  OBUF   c4_OBUF (
    .I(c4_OBUF_40),
    .O(c4)
  );
  OBUF   an_3_OBUF (
    .I(an_3_OBUF_36),
    .O(an[3])
  );
  OBUF   an_2_OBUF (
    .I(an_2_OBUF_35),
    .O(an[2])
  );
  OBUF   an_1_OBUF (
    .I(an_1_OBUF_34),
    .O(an[1])
  );
  OBUF   an_0_OBUF (
    .I(an_0_OBUF_33),
    .O(an[0])
  );
  OBUF   sseg_7_OBUF (
    .I(N1),
    .O(sseg[7])
  );
  OBUF   sseg_6_OBUF (
    .I(sseg_6_OBUF_116),
    .O(sseg[6])
  );
  OBUF   sseg_5_OBUF (
    .I(sseg_5_OBUF_115),
    .O(sseg[5])
  );
  OBUF   sseg_4_OBUF (
    .I(sseg_4_OBUF_114),
    .O(sseg[4])
  );
  OBUF   sseg_3_OBUF (
    .I(sseg_3_OBUF_113),
    .O(sseg[3])
  );
  OBUF   sseg_2_OBUF (
    .I(sseg_2_OBUF_112),
    .O(sseg[2])
  );
  OBUF   sseg_1_OBUF (
    .I(sseg_1_OBUF_111),
    .O(sseg[1])
  );
  OBUF   sseg_0_OBUF (
    .I(sseg_0_OBUF_110),
    .O(sseg[0])
  );
  OBUF   temp_3_OBUF (
    .I(temp_3_OBUF_140),
    .O(temp[3])
  );
  OBUF   temp_2_OBUF (
    .I(temp_2_OBUF_139),
    .O(temp[2])
  );
  OBUF   temp_1_OBUF (
    .I(temp_1_OBUF_138),
    .O(temp[1])
  );
  OBUF   temp_0_OBUF (
    .I(temp_0_OBUF_137),
    .O(temp[0])
  );
  OBUF   led_0_OBUF (
    .I(led_0_OBUF_101),
    .O(led[0])
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<1>_rt  (
    .I0(\disp_unit/q_reg [1]),
    .O(\disp_unit/Mcount_q_reg_cy<1>_rt_59 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<2>_rt  (
    .I0(\disp_unit/q_reg [2]),
    .O(\disp_unit/Mcount_q_reg_cy<2>_rt_61 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<3>_rt  (
    .I0(\disp_unit/q_reg [3]),
    .O(\disp_unit/Mcount_q_reg_cy<3>_rt_63 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<4>_rt  (
    .I0(\disp_unit/q_reg [4]),
    .O(\disp_unit/Mcount_q_reg_cy<4>_rt_65 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<5>_rt  (
    .I0(\disp_unit/q_reg [5]),
    .O(\disp_unit/Mcount_q_reg_cy<5>_rt_67 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<6>_rt  (
    .I0(\disp_unit/q_reg [6]),
    .O(\disp_unit/Mcount_q_reg_cy<6>_rt_69 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<7>_rt  (
    .I0(\disp_unit/q_reg [7]),
    .O(\disp_unit/Mcount_q_reg_cy<7>_rt_71 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<8>_rt  (
    .I0(\disp_unit/q_reg [8]),
    .O(\disp_unit/Mcount_q_reg_cy<8>_rt_73 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<9>_rt  (
    .I0(\disp_unit/q_reg [9]),
    .O(\disp_unit/Mcount_q_reg_cy<9>_rt_75 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<10>_rt  (
    .I0(\disp_unit/q_reg [10]),
    .O(\disp_unit/Mcount_q_reg_cy<10>_rt_45 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<11>_rt  (
    .I0(\disp_unit/q_reg [11]),
    .O(\disp_unit/Mcount_q_reg_cy<11>_rt_47 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<12>_rt  (
    .I0(\disp_unit/q_reg [12]),
    .O(\disp_unit/Mcount_q_reg_cy<12>_rt_49 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<13>_rt  (
    .I0(\disp_unit/q_reg [13]),
    .O(\disp_unit/Mcount_q_reg_cy<13>_rt_51 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<14>_rt  (
    .I0(\disp_unit/q_reg [14]),
    .O(\disp_unit/Mcount_q_reg_cy<14>_rt_53 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<15>_rt  (
    .I0(\disp_unit/q_reg [15]),
    .O(\disp_unit/Mcount_q_reg_cy<15>_rt_55 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_cy<16>_rt  (
    .I0(\disp_unit/q_reg [16]),
    .O(\disp_unit/Mcount_q_reg_cy<16>_rt_57 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \disp_unit/Mcount_q_reg_xor<17>_rt  (
    .I0(\disp_unit/q_reg [17]),
    .O(\disp_unit/Mcount_q_reg_xor<17>_rt_77 )
  );
  LUT4 #(
    .INIT ( 16'h10F2 ))
  \disp_unit/Mmux_sseg3_SW2  (
    .I0(temp_2_OBUF_139),
    .I1(temp_1_OBUF_138),
    .I2(temp_0_OBUF_137),
    .I3(temp_3_OBUF_140),
    .O(N36)
  );
  LUT3 #(
    .INIT ( 8'hFE ))
  \disp_unit/Mmux_sseg3  (
    .I0(\disp_unit/q_reg [16]),
    .I1(\disp_unit/q_reg [17]),
    .I2(N36),
    .O(sseg_2_OBUF_112)
  );
  LUT4 #(
    .INIT ( 16'h8908 ))
  \disp_unit/Mmux_sseg5_SW2  (
    .I0(temp_2_OBUF_139),
    .I1(temp_3_OBUF_140),
    .I2(temp_0_OBUF_137),
    .I3(temp_1_OBUF_138),
    .O(N38)
  );
  LUT3 #(
    .INIT ( 8'hFE ))
  \disp_unit/Mmux_sseg5  (
    .I0(\disp_unit/q_reg [16]),
    .I1(\disp_unit/q_reg [17]),
    .I2(N38),
    .O(sseg_4_OBUF_114)
  );
  LUT4 #(
    .INIT ( 16'hD680 ))
  \disp_unit/Mmux_sseg6_SW2  (
    .I0(temp_0_OBUF_137),
    .I1(temp_1_OBUF_138),
    .I2(temp_3_OBUF_140),
    .I3(temp_2_OBUF_139),
    .O(N40)
  );
  LUT3 #(
    .INIT ( 8'hFE ))
  \disp_unit/Mmux_sseg6  (
    .I0(\disp_unit/q_reg [16]),
    .I1(\disp_unit/q_reg [17]),
    .I2(N40),
    .O(sseg_5_OBUF_115)
  );
  LUT4 #(
    .INIT ( 16'h6302 ))
  \disp_unit/Mmux_sseg2_SW2  (
    .I0(temp_1_OBUF_138),
    .I1(temp_3_OBUF_140),
    .I2(temp_2_OBUF_139),
    .I3(temp_0_OBUF_137),
    .O(N42)
  );
  LUT3 #(
    .INIT ( 8'hFE ))
  \disp_unit/Mmux_sseg2  (
    .I0(\disp_unit/q_reg [16]),
    .I1(\disp_unit/q_reg [17]),
    .I2(N42),
    .O(sseg_1_OBUF_111)
  );
  LUT4 #(
    .INIT ( 16'h0491 ))
  \disp_unit/Mmux_sseg1_SW2  (
    .I0(temp_1_OBUF_138),
    .I1(temp_2_OBUF_139),
    .I2(temp_0_OBUF_137),
    .I3(temp_3_OBUF_140),
    .O(N44)
  );
  LUT3 #(
    .INIT ( 8'hFE ))
  \disp_unit/Mmux_sseg1  (
    .I0(\disp_unit/q_reg [16]),
    .I1(\disp_unit/q_reg [17]),
    .I2(N44),
    .O(sseg_0_OBUF_110)
  );
  LUT4 #(
    .INIT ( 16'h8492 ))
  \disp_unit/Mmux_sseg4_SW2  (
    .I0(temp_0_OBUF_137),
    .I1(temp_1_OBUF_138),
    .I2(temp_2_OBUF_139),
    .I3(temp_3_OBUF_140),
    .O(N46)
  );
  LUT3 #(
    .INIT ( 8'hFE ))
  \disp_unit/Mmux_sseg4  (
    .I0(\disp_unit/q_reg [16]),
    .I1(\disp_unit/q_reg [17]),
    .I2(N46),
    .O(sseg_3_OBUF_113)
  );
  LUT4 #(
    .INIT ( 16'h4184 ))
  \disp_unit/Mmux_sseg7_SW1  (
    .I0(temp_1_OBUF_138),
    .I1(temp_0_OBUF_137),
    .I2(temp_3_OBUF_140),
    .I3(temp_2_OBUF_139),
    .O(N48)
  );
  LUT3 #(
    .INIT ( 8'hFE ))
  \disp_unit/Mmux_sseg7  (
    .I0(\disp_unit/q_reg [16]),
    .I1(\disp_unit/q_reg [17]),
    .I2(N48),
    .O(sseg_6_OBUF_116)
  );
  MUXF5   \f0/fa_1/C  (
    .I0(N50),
    .I1(N51),
    .S(sw_1_IBUF_126),
    .O(\f0/c2 )
  );
  LUT4 #(
    .INIT ( 16'h4A02 ))
  \f0/fa_1/C_F  (
    .I0(btn_1_IBUF_38),
    .I1(sw_4_IBUF_129),
    .I2(sw_5_IBUF_130),
    .I3(sw_0_IBUF_125),
    .O(N50)
  );
  LUT4 #(
    .INIT ( 16'hBFF8 ))
  \f0/fa_1/C_G  (
    .I0(sw_0_IBUF_125),
    .I1(sw_4_IBUF_129),
    .I2(sw_5_IBUF_130),
    .I3(btn_1_IBUF_38),
    .O(N51)
  );
  BUFGP   clk_BUFGP (
    .I(clk),
    .O(clk_BUFGP_42)
  );
  INV   \disp_unit/Mcount_q_reg_lut<0>_INV_0  (
    .I(\disp_unit/q_reg [0]),
    .O(\disp_unit/Mcount_q_reg_lut [0])
  );
  LUT4 #(
    .INIT ( 16'h690F ))
  \f0/fa_1/ha_1/Mxor_S_Result12  (
    .I0(sw_0_IBUF_125),
    .I1(btn_1_IBUF_38),
    .I2(sw_1_IBUF_126),
    .I3(sw_4_IBUF_129),
    .O(\f0/fa_1/ha_1/Mxor_S_Result1 )
  );
  LUT4 #(
    .INIT ( 16'hB748 ))
  \f0/fa_1/ha_1/Mxor_S_Result13  (
    .I0(btn_1_IBUF_38),
    .I1(sw_4_IBUF_129),
    .I2(sw_0_IBUF_125),
    .I3(sw_1_IBUF_126),
    .O(\f0/fa_1/ha_1/Mxor_S_Result11 )
  );
  MUXF5   \f0/fa_1/ha_1/Mxor_S_Result1_f5  (
    .I0(\f0/fa_1/ha_1/Mxor_S_Result11 ),
    .I1(\f0/fa_1/ha_1/Mxor_S_Result1 ),
    .S(sw_5_IBUF_130),
    .O(temp_1_OBUF_138)
  );
endmodule


`ifndef GLBL
`define GLBL

`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;

    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule

`endif

