/*
WORKING WITH BINARY SEARCHING
*/

double mysqrt(double num) {
	#define __sqrt_low_  	calc_opts[0]
	#define __sqrt_high_ 	calc_opts[1]
	#define __sqrt_res_  	calc_opts[2]

	if (num < 0.0f) 
		return -nan;

	double calc_opts[3];
	for (__sqrt_low_ = 0.0f, __sqrt_high_ = num, __sqrt_res_ = 0.0f; __sqrt_high_ - __sqrt_low_ >= 1e-9; __sqrt_res_ = (__sqrt_low_ + __sqrt_high_)/2) {
		if (num < __sqrt_res_ * __sqrt_res_) {
			__sqrt_high_ = __sqrt_res_;
			continue;
		}
			__sqrt_low_  = __sqrt_res_;
	}

	return __sqrt_res_;
}
