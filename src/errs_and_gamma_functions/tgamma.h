/*
 * WORKS WITH PUGH'S METHOD( no negative nums, sorry user )
*/

#include <math.h>
#define G 	    7
#define __sqrt_2pi_ 2.506628274631
#define __lanc_le_n 9

double mytgamma(double z, int accuracy) {
	if (z < 0)
		return nan;

	static const double lanczos_coefs[__lanc_le_n] = {
    		 0.99999999999980993,
    		 676.5203681218851,
    		-1259.1392167224028,
    		 771.32342877765313,
    		-176.61502916214059,
    		 12.507343278686905,
    		-0.13857109526572012,
    		 9.9843695780195716e-6,
    		 1.5056327351493116e-7
	};

	if (z-- >= 0.5) {
            double x, t;
	    int i;
            for (i = 1, x = lanczos_coefs[0]; i < __lanc_le_n; i++)
               x += lanczos_coefs[i] / (z + i);

            t = z + G + 0.5;
            return __sqrt_2pi_ * mypow(t, z + 0.5) * myexp(-t) * x;
    	}
	return PI / (mysin(PI * z, accuracy) * mytgamma(1.0 - z, accuracy));
}
