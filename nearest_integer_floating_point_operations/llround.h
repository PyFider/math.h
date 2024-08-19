#define myllround(num) ((num >= 0.0f) ? __myllround_get_res(num, 1):__myllround_get_res(num, -1))
#define __myllround_get_res(num, sign) (sign*num - (int)(sign*num) >= 0.5) ? sign*(long long int)((int)(num*sign) + 1):sign*(long long int)((int)(sign*num))

/*
In function form logic of my macro
long long int llround(float num) {
	if (num >= 0.0f) {
		if (num - (int)num >= 0.5)
			return (long long int)((int)num+1);
		else
			return (long long int)((int)num);
	} else {
		num *= -1.0f;
		if (num - (int)num >= 0.5)
			return (-1)*(long long int)((int)num+1);
		else
			return (-1)*(long long int)((int)num);

	}
}
*/
