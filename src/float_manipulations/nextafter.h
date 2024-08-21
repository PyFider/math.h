/* thanks MUSL */

#define __force_eval(x)	{							\
	if 	(sizeof(x) == sizeof(float)) 	{volatile float 	y = x;}	\
	else if (sizeof(x) == sizeof(double))	{volatile double 	y = x;}	\
	else					{volatile long double 	y = x;}	\
}

#define __ulli unsigned long long int
double mynextafter(double x, double y)
{
	union {double f; __ulli i;} ux={x}, uy={y};
	__ulli ax, ay;

	if (ux.i == uy.i) return y;

	ax = ux.i & -1ULL>>1;
	ay = uy.i & -1ULL>>1;
	if 	(ax == ay && ay == 0)	 		return y;
	else if (ax == 0)				ux.i = (uy.i & 1ULL<<63) | 1;
	else if (ax > ay || ((ux.i ^ uy.i) & 1ULL<<63)) ux.i--;
	else						ux.i++;
	
	if ((ux.i >> 52 & 0x7ff) == 0x7ff) __force_eval(x+x);	 		/* raise overflow if ux.f is infinite and x is finite */
	if ((ux.i >> 52 & 0x7ff) == 0) 	   __force_eval(x*x + ux.f*ux.f); 	/* raise underflow if ux.f is subnormal or zero */
	
	return ux.f;
}
