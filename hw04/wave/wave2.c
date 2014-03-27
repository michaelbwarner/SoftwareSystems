#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char * int2bin(int i) {
	size_t bits = sizeof(int) * CHAR_BIT;
	
	char * str = malloc(bits +1);
	if(!str) return NULL;
	str[bits] = 0;

	unsigned u = *(unsigned *)&i;
	for(; bits--; u>>=1) 
		str[bits] = u & 1 ? '1' : '0';
	
	return str;
}

void writeByte(int x) {
	int pin;
 	for (pin=13; pin>=6; pin--) {
		printf("%s\n", int2bin(x));
		x >>= 1;
 	}

}

int main() {
	int c = 24;
	//writeByte(c);
 	//printf("%s\n", int2bin(c));
	writeByte(c);
	return 0;
}
