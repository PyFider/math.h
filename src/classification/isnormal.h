int myisnormal(double x) {
	x = ((x >= 0.0f) ? x:-x);
	return (x != 0.0f && x != nan && x != inf && x >= 1e-308) ? 1:0;
}						/* ESCAPED SUBNRML */
