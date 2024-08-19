/*
WORKING WITH POW FUNC 1/3
*/

#define mycbrt(num) __mycbrt_start_((num))
#define __mycbrt_start_(num) ((num < 0.0f) ? (-1.0f)*mypow(-num, 1.0f/3.0f):mypow(num, 1.0f/3.0f))

