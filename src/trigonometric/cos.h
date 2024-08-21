/*
 * 
 *  WORKING WITH TAYLOR:
 *  a(n+1) = a(n)*((-rad^2)/(2*n*(2*n-1)))
 *
*/

 /* MAX OPTIMIZATION WITH BINARY MOVING AND GOTO */
#define __cos_mult2(n) ((n << 1))

double mycos(double rad, int accuracy) {
    double an, res;
    int n;

    an = 1;
    res = 0.0f;
    n = 1;
    goto calc;

calc:
    if (n > accuracy)
        goto end_calculating;
    
    res += an;
    an *= ((-rad * rad) / ((__cos_mult2(n)) * (__cos_mult2(n) - 1)));
    n++;

    goto calc;

end_calculating:
    return res;
}


/*
UNDERSANDABLE VERSION(LOWER IN 10 TIMES)
double mycos(double rad, int accuracy)
{
	double an, res;
	int n;

	for (n = 1, an = 1, res = 0.0f; n <= accuracy; n++) {
		res += an;
		an *= (-rad*rad)/((2*n)*(2*n-1));
	}

	return res;
}
*/
