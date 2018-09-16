/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000002062102019_4122600708_init();
    work_m_00000000000628438056_3190593924_init();
    work_m_00000000000415197304_1086460743_init();
    work_m_00000000002564699464_2250382437_init();
    work_m_00000000001510851567_0855183448_init();
    work_m_00000000003459955776_0638330825_init();
    work_m_00000000004093713498_2073120511_init();


    xsi_register_tops("work_m_00000000003459955776_0638330825");
    xsi_register_tops("work_m_00000000004093713498_2073120511");


    return xsi_run_simulation(argc, argv);

}
