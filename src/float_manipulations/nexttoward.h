int __signbit(double x)
{
	union {
		double d;
		unsigned long long int i;
	} y = { x };
	return y.i>>63;
}

double mynexttoward(double x, long double y)
{
	union {double f; unsigned long long i;} ux = {x};

	if (x == 0)	(ux.i = (__signbit(y)) ? (1 | (1ULL<<63)):1);
	else if (x < y)	(__signbit(x)) ? ux.i--:ux.i++;
	else  		(__signbit(x)) ? ux.i++:ux.i--;

	if ((ux.i>>52 & 0x7ff) == 0x7ff)  __force_eval(x*x); 	          /* raise overflow if ux.f is infinite and x is finite */
	if ((ux.i>>52 & 0x7ff) == 0)      __force_eval(x*x + ux.f*ux.f);  /* raise underflow if ux.f is subnormal or zero */

	return ux.f;
}
