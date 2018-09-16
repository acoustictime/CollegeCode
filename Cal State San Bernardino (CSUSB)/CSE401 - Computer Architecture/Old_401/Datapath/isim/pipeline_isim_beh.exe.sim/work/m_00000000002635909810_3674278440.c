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

/* This file is designed for use with ISim build 0x1cce1bb2 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Owner/Desktop/Datapath/buff.v";
static int ng1[] = {0, 0};



static void Initial_24_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(25, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1584);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 32, 0LL);

LAB1:    return;
}

static void Always_27_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;

LAB0:    t1 = (t0 + 2752U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(27, ng0);
    t2 = (t0 + 3072);
    *((int *)t2) = 1;
    t3 = (t0 + 2784);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(28, ng0);
    t4 = (t0 + 2560);
    xsi_process_wait(t4, 1000LL);
    *((char **)t1) = &&LAB5;
    goto LAB1;

LAB5:    xsi_set_current_line(28, ng0);
    t5 = (t0 + 1184U);
    t6 = *((char **)t5);
    t5 = (t0 + 1584);
    xsi_vlogvar_wait_assign_value(t5, t6, 0, 0, 32, 0LL);
    goto LAB2;

}


extern void work_m_00000000002635909810_3674278440_init()
{
	static char *pe[] = {(void *)Initial_24_0,(void *)Always_27_1};
	xsi_register_didat("work_m_00000000002635909810_3674278440", "isim/pipeline_isim_beh.exe.sim/work/m_00000000002635909810_3674278440.didat");
	xsi_register_executes(pe);
}
