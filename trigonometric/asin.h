/* 
 *
 * WORKING WITH TAYLOR:
 * a(n+1) = a(n)*(((2*n+1)*(2*n+1)*x*x)/(2*(n+1)*(2*n+3))) 
 * 
*/

/*  MAX OPTIMIZATION WITH BINARY MOVING AND GOTO */
#define __asin_mult2(n) ((n << 1))
#define __asin_denominator_(n) (__asin_mult2((n+1)*((n << 1)+3)))
#define __asin_numerator_(x, n) (((n << 1)+1)*((n << 1)+1)*x*x)
double myasin(double x, int accuracy) {
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
    an *= __asin_numerator_(x, n)/__asin_denominator_(n);
    n++;

    goto calc;

end_calculating:
    return res;
}


/*
UNDERSANDABLE VERSION(LOWER IN 10 TIMES)
double myasin(double x, int accuracy)
{
	double an, res;
	int n;

	for (n = 0, an = x, res = 0.0f; n <= accuracy; n++) {
		res += an;
		an *= (((2*n+1)*(2*n+1)*x*x)/(2*(n+1)*(2*n+3)));
	}

	return res;
}
*/
