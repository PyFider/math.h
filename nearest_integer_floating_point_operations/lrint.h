#define mylrint(num) ((num >= 0.0f) ? __mylrint_get_res(num, 1):__mylrint_get_res(num, -1))
#define __mylrint_get_res(num, sign) (sign*num - (float)((int)(num*sign)) > 0.5) ? sign*(long int)((int)(num*sign)+1):sign*(long int)((int)(num*sign))

/*
In function form logic of macro
long int lrint(float num) {
	if (num >= 0.0f) {
		if (num - (float)((int)num) > 0.5)
	       		return (long int)((int)num+1);
		else
			return (long int)((int)num);
	} else {
		num *= -1.0f;
		if (num - (float)((int)num) > 0.5)
	       		return (long int)((int)num+1)*(-1);
		else
			return (long int)((int)num)*(-1);
	}
}
*/
