int myisfinite(double num) {
	if (num != nan && num != inf)
		return 1;
	return 0;
}
