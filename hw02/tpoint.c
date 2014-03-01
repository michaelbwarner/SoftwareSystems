#include <stdio.h>

void test(int *var) {
	*var = 6;
}

void testchar(char *pattern) {

	pattern[0] = 'y';
}

int main() {

	int number = 4;
	int *num = &number;
	printf("%p\n", &num);
	printf("%i\n", *num);
	//test(&number);
	test(num);
	printf("%i\n", *num);

	char pattern[] = "not changed";
	testchar(pattern);
	printf("%s\n", pattern);
}
