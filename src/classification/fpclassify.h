#define FP_INFINITE 	1
#define FP_NAN	    	0
#define FP_NORMAL   	4
#define FP_SUBNORMAL	3
#define FP_ZERO		2

int myfpclassify(double x)
{
	double xabs;

	xabs = ((x >= 0.0f) ? x:-x);
	if (myisinf(x)) 				return FP_INFINITE;
	if (myisnan(x)) 				return FP_NAN;
	if (xabs<1e-308 && xabs!=+0.0f && xabs!=0.0f)	return FP_SUBNORMAL;
	if (myisnormal(x))				return FP_NORMAL;	
	if (x == +0.0f || x == -0.0f || x == 0.0f)	return FP_ZERO;

	return 0;
}
