double mylog(double x) {
    if (x <= 0)
	return nan;

    double res, term, term_squared, numerator;
    int n;

    /* TAYLOR */
    res = 0.0f;
    term = (x-1)/(x+1);
    term_squared = term*term;
    numerator = term;
    n = 1;
    for (;;term = numerator / n, res += term, numerator *= term_squared, n += 2)
    	if (term < EPSILON && term > -EPSILON)
    		break;
	
    res *= 2;
    return res;
}
