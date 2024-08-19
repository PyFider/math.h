#define myrint(num) ((num >= 0.0f) ? __myrint_get_res(num, 1.0f):__myrint_get_res(num, -1.0f))
#define __myrint_get_res(num, sign) (sign*num - (float)((int)(num*sign)) > 0.5) ? sign*(float)((int)(num*sign)+1):sign*(float)((int)(num*sign))

/*
In function form logic of macro
float rint(float num) {
	if (num >= 0.0f) {
		if (num - (float)((int)num) > 0.5)
	       		return (float)((int)num+1);
		else
			return (float)((int)num);
	} else {
		num *= -1;
		if (num - (float)((int)num) > 0.5)
	       		return (float)((int)num+1)*(-1);
		else
			return (float)((int)num)*(-1);
	}
}
*/
