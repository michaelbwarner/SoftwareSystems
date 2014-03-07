#include <stdio.h>
#include <stdlib.h>

#include "rand.c"

main (int argc, char *argv[])
{
	int i;
 	double x;
	float f;

	srandom (time (NULL));

	for (i=0;i<10; i++) {
		f = my_random_double();
		printf("%f\n", f);
	}

//  for (i=0; i<10000; i++) {
//    x = my_random_double();
//    printf ("%lf\n", x);
//  }
}
