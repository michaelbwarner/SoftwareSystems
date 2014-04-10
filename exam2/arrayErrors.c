#include <stdio.h>

int main(int argc, char *argv[]) {

	static int test1[2] = {1, 2};
	test1[4] = 4;
	printf("%i\n", test1[4]);
	
	return 0;
}
