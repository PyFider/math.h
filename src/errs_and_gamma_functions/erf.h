/*
 * WORK WITH TAYLOR
 * a(n+1) = a(n)*((-1)*x^2*(2*n+1)/((2*n+3)*(n+1)))
*/

#define __2del_sqrtPI	1.128379167095513
double myerf(double x, int accuracy) 
{
	double res, an;
	int i;
	i = 0, an = x, res = 0.0f;
       		
calc_erf:
	res += an;
	an *= (-x*x)*((i << 1)+1)/(((i << 1)+3)*(i+1));

	if (i++ > accuracy)
		return res*__2del_sqrtPI;

	goto calc_erf;
}

/* UNDERSTANDABLE VERSION(LOWER)
double myerf(double x, int accuracy) 
{
	double res, an;
	int i;
	for (i = 0, an = x, res = 0.0f; i < accuracy; i++) {
		res += an;
		an *= (-x*x)*(2*i+1)/((2*i+3)*(i+1));
	}

	return res*__2del_sqrtPI;
}
*/
