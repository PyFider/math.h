/*
 * WORKS WITH TAYLOR METHOD
 * a(n+1) = a(n)*(x/(n+1))
*/

#define exp_acc 100 /* FOR FUTURE: make acc argument */

double myexp(double x)
{
	double res, an;
	int i;

	i = 0, an = 1.0f, res = 0.0f;

calc_exp:
	res += an;
	an  *= x/(++i);
	if (i > exp_acc)
		return res;

	goto calc_exp;
}

/* UNDERSTANDABLE VERSION(LOWER)
double myexp(double x)
{
	double res, an;
	int i;

	for (i = 0, an = 1.0f, res = 0.0f; i < exp_acc; i++) {
		res += an;
		an  *= x/(i+1);
	}

	return res;
}
*/
