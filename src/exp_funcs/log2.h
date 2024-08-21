double mylog2(double num) {
	if (num <= 0.0f) return -1.0f/0.0f;
	return (mylog(num) / mylog(2.0f));
}
