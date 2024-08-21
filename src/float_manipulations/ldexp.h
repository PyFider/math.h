#define ___ld_exp_pos_pow2___(n, res) 						\
	int counter;								\
	for (res = 2, counter = n; counter != 1; counter--, res <<= 1)		\
		;								\


#define ___ld_exp_neg_pow2___(n, res) 						\
	int counter;								\
	for (res = 0.5f, counter = n; counter != -1; counter++, res/=2)		\
		;								\


double myldexp(double mant, int e) 
{
	if (e == 0)
		return mant;
		
	if (e > 0) {
       		int step2;
		___ld_exp_pos_pow2___(e, step2);
		return mant*step2;
	} else {
		double step2;
		___ld_exp_neg_pow2___(e, step2);
		return mant*step2;
	}
}
