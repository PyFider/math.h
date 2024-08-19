#define mytg(num, accuracy) __start_cal_c__tg___((num), (accuracy))
#define __start_cal_c__tg___(num, accuracy) (mysin(num, accuracy)/mycos(num, accuracy))
