#include <stdio.h>

void test(int *var) {
	*var = 6;
}

int main() {

	int number = 4;
	int *num = &number;
	printf("%p\n", &num);
	printf("%i\n", *num);
	test(&number);
	printf("%i\n", *num);
}
