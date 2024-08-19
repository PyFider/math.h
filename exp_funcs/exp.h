double myexp(double step) {
	double res, term;
	int n;

	const double epsilon = 1e-10;
	for(res = 1.0f, term = 1.0f, n = 1; term > epsilon; term *= step / n, res += term, n++);

	return res;
}
