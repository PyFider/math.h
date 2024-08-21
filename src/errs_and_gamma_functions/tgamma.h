/*
*/

#define __B2 		 0.5 /*  B2 = B2 / 2! */
#define __B4 		-0.03333333333333333 /*  B4 = B4 / 4!  */
#define __B6 		 0.002380952380952381 /*  B6 = B6 / 6! */
#define __B8 		-0.00003544793544793545 /*  B8 = B8 / 8! */
#define __B10 		 0.000000641025641025641 /*  B10 = B10 / 10! */
#define __B12 		-0.000000011666666666667 /*  B12 = B12 / 12! */
#define __B14 		 0.00000000024089641525641 /*  B14 = B14 / 14! */
#define __B16 		-0.00000000000569240569241 /*  B16 = B16 / 16! */
#define __B18 		 0.000000000000140540540541 /*  B18 = B18 / 18! */
#define __B20 		-0.00000000000000360655737705 /*  B20 = B20 / 20! */

#define __C0		 0.99999999999980993
#define __C1		 57.1562356658629235
#define __C2		-59.5979603554754912
#define __C3		 14.1360979747417471
#define __C4		-0.491913816097620199
#define __C5		 .339946499848118887e-4
#define __C6		 .465236289270485756e-4

#define __sqrt_2pi 	 2.506628274631

double mytgamma(double x)
{
    if (x <= 0) 
    	return nan;
	
    double res, sum;
    int k, i;

    sum += __C0/x;
    sum += __C1/(x+1);
    sum += __C2/(x+2);
    sum += __C3/(x+3);
    sum += __C4/(x+4);
    sum += __C5/(x+5);
    sum += __C6/(x+6);

    res = __sqrt_2pi + (x - 0.5)  *  mylog(x) - x + sum;

    res += __B2/mypow(x, 1);
    res += __B4/mypow(x, 3);
    res += __B6/mypow(x, 5);
    res += __B8/mypow(x, 7);
    res += __B10/mypow(x, 9);
    res += __B12/mypow(x, 11);
    res += __B14/mypow(x, 13);
    res += __B16/mypow(x, 15);
    res += __B18/mypow(x, 17);
    res += __B20/mypow(x, 19);
    
    return res;
}
