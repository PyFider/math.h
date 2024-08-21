#define myctg(num, accuracy) __start_cal_c__ctg___((num), (accuracy))
#define __start_cal_c__ctg___(num, accuracy) (mycos(num, accuracy)/mysin(num, accuracy))
