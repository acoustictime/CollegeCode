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
    work_m_00000000002403219321_1323274903_init();
    work_m_00000000000172990357_2078204288_init();
    work_m_00000000003333555705_3383896982_init();
    work_m_00000000000186167125_1774216237_init();
    work_m_00000000002635909810_3674278440_init();
    work_m_00000000001251437580_1654266308_init();
    work_m_00000000003019421634_3409648901_init();
    work_m_00000000004093713498_2073120511_init();


    xsi_register_tops("work_m_00000000003019421634_3409648901");
    xsi_register_tops("work_m_00000000004093713498_2073120511");


    return xsi_run_simulation(argc, argv);

}
