float myfmod(float num1, float num2) {
	int i;
	num2 = myfabs(num2);
	if (num1 >= 0.0f) {
		for (i = 1; num1-num2*i > 0; i++);
		return num1-num2*(i-1);
	} else {
		for (i = 1; -num1-num2*i > 0; i++);
		return (-num1-num2*(i-1))*(-1);
	}
}

