/* 
 *
 * WORKING WITH TAYLOR:
 * a(n+1) = (a(n)*(-x*x*(2*n+1)))/(2*n+3)
 * 
*/

/*  MAX OPTIMIZATION WITH BINARY MOVING AND GOTO */
#define __atg_numerator_(x, n) (-x*x*((n << 1)+1))
#define __atg_denominator_(n) ((n << 1)+3)
double myatg(double x, int accuracy) {
    double an, res;
    int n;

    an = x;
    res = 0.0f;
    n = 0;
    goto calc;

calc:
    if (n > accuracy)
        goto end_calculating;
    
    res += an;
    an *= __atg_numerator_(x, n)/__atg_denominator_(n);
    n++;

    goto calc;

end_calculating:
    return res;
}

/*
UNDERSANDABLE VERSION(LOWER IN 10 TIMES)
double myatg(double x, int accuracy)
{
	double an, res;
	int n;

	for (n = 0, an = x, res = 0.0f; n <= accuracy; n++) {
		res += an;
		an *= (-x*x*(2*n+1))/(2*n+3);
	}

	return res;
}
*/
