#include <stdio.h>
#include <stdlib.h>
#include "src/math.h"

main(int argc, char **argv) 
{
	printf("%f\n", mytgamma(atof(*++argv)));
}

