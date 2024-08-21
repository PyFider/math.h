#include <stdio.h>
#include <stdlib.h>
#include "src/math.h"

main(int argc, char **argv) 
{
	double num = atof(*++argv);
	printf("%f\n", myerfc(num, 100));
}
