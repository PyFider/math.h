#define myfloor(num) ((num >= 0.0f) ? (float)((int)num):(float)((int)num-1))

/*
In function form logic of my macro
float floor(float num) {
	if (num >= 0.0f)
		return (float)((int)num);
	else
		return (float)((int)num-1);
}
*/
