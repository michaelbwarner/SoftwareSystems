/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

void plocal() {
	int locali = 1;
	printf("address of locali is %p\n", &locali);
	int local2;
	printf("address of local2 is %p\n", &local2);
	int *ptr = malloc(sizeof(int));
	int *ptr2 = malloc(sizeof(int));
	printf("address of malloc ptr is %p\n", ptr);
	printf("address of malloc ptr2 is %p\n", ptr2);

}

int main ()
{
	int local = 5;
	void *p = malloc(128);

	printf ("Address of main is %p\n", main);
	printf ("Address of global is %p\n", &global);
	printf ("Address of local is %p\n", &local);
	printf ("Address of p is %p\n", p);
	plocal();
    
	return 0;
}
