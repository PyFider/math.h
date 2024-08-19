#include <stdio.h>
#include <stdlib.h>
#include "mymath.h"

int main(int argc, char **argv) {
	double mant = atof(*++argv);
	int exp = atoi(*++argv);

	printf("%f\n", myldexp(mant, exp));
	return 0;
}
