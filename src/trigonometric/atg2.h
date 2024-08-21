/* thanks MUSL */

#define __asuint64(f) ((union{double _f; unsigned long long _i;}){f})._i
#define __EXTRACT_WORDS(hi,lo,d) {			  \
  		unsigned long __u = __asuint64(d);        \
  		(hi) = __u >> 32;                         \
  		(lo) = (unsigned long)__u;                \
}

#define __PI_LO 1.2246467991473531772E-16
double myatg2(double y, double x, int accuracy)
{
	double z;
	unsigned long m,lx,ly,ix,iy;

	__EXTRACT_WORDS(ix, lx, x);
	__EXTRACT_WORDS(iy, ly, y);
	if ((ix-0x3ff00000 | lx) == 0)  /* x = 1.0 */
		return myatg(y, accuracy);
	m = ((iy>>31)&1) | ((ix>>30)&2);  /* 2*sign(x)+sign(y) */
	ix = ix & 0x7fffffff;
	iy = iy & 0x7fffffff;

	/* when y = 0 */
	if ((iy|ly) == 0) {
		switch(m) {
			case 0: 
			case 1: return y;   /* atan(+-0,+anything)=+-0 */
			case 2: return  PI; /* atan(+0,-anything) = pi */
			case 3: return -PI; /* atan(-0,-anything) =-pi */
		}
	}
	/* when x = 0 */
	if ((ix|lx) == 0)
		return m&1 ? -PI/2 : PI/2;
	/* when x is INF */
	if (ix == 0x7ff00000) {
		if (iy == 0x7ff00000) {
			switch(m) {
				case 0: return  PI/4;   /* atan(+INF,+INF) */
				case 1: return -PI/4;   /* atan(-INF,+INF) */
				case 2: return  3*PI/4; /* atan(+INF,-INF) */
				case 3: return -3*PI/4; /* atan(-INF,-INF) */
			}
		} else {
			switch(m) {
				case 0: return  0.0; /* atan(+...,+INF) */
				case 1: return -0.0; /* atan(-...,+INF) */
				case 2: return  PI;  /* atan(+...,-INF) */
				case 3: return -PI;  /* atan(-...,-INF) */
			}
		}
	}
	/* |y/x| > 0x1p64 */
	if (ix+(64<<20) < iy || iy == 0x7ff00000)
		return ((m&1) ? -PI/2 : PI/2);

	/* z = atan(|y/x|) without spurious underflow */
	z = ((m&2) && iy+(64<<20) < ix) ? 0:myatg(myfabs(y/x), accuracy); /* |y/x| < 0x1p-64, x<0 */
	switch (m) {
		case 0:  return z;                /* atan(+,+) */
		case 1:  return -z;            	  /* atan(-,+) */
		case 2:  return PI - (z-__PI_LO); /* atan(+,-) */
		default: return (z-__PI_LO) - PI; /* case 3: atan(-,-) */
	}
}
