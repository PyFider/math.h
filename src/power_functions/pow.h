double mypow(double num1, double num2) {
	if (num2 == (int)num2) {
		double res;
		int i;
		if (num2 == 0.0f) {
			return 1;
		} else if (num2 < 0.0f) {
			res = 1.0f / num1;
			for (i = 0; i < num2-1; res /= num1, i++);
			return res;
		} else {
			res = num1;
			for (i = 0; i < num2-1; res *= num1, i++);
			return res;
		}
	}

	return (num1 < 0) ? 0:myexp(num2 * mylog(num1));
}
