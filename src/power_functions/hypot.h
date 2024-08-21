double myhypot(double a, double b) {
	if (a >= 0.0f && b >= 0.0f)
		return mysqrt(a*a + b*b);
	return -1.0f/0.0f;
}
