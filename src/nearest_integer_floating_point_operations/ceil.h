#define myceil(num) ((num >= 0.0f) ? (float)((int)num+1):(float)((int)num))

/*
In function form logic of my macro
float ceil(float num) {
	if (num >= 0.0f)
		return (float)((int)num+1);
	else
		return (float)((int)num);
}
*/
