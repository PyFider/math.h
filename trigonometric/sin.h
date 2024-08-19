/* 
 *
 * WORKING WITH TAYLOR:
 * a(n+1) = a(n)*((-rad^2)/((2n+2)*(2n+3)))
 * 
*/

 /* MAX OPTIMIZATION WITH BINARY MOVING AND GOTO */
#define __sin_mult2(n) ((n << 1))
double mysin(double rad, int accuracy) {
    double an, res;
    int n;

    an = rad;
    res = 0.0f;
    n = 0;
    goto calc;

calc:
    if (n > accuracy)
        goto end_calculating;
    
    res += an;
    an *= ((-rad * rad) / ((__sin_mult2(n) + 2) * (__sin_mult2(n) + 3)));
    n++;

    goto calc;

end_calculating:
    return res;
}

/*
UNDERSANDABLE VERSION(LOWER IN 10 TIMES)
double mysin(double rad, int accuracy)
{
	double an, res;
	int n;

	for (n = 0, an = rad, res = 0.0f; n <= accuracy; n++) {
		res += an;
		an *= (-rad*rad)/(2*n+2)*(2*n+3)));
	}

	return res;
}
*/
