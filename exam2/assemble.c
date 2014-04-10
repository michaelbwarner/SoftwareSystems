#include <stdio.h>
#include <stdint.h>

uint16_t assemble(uint8_t most, uint8_t least) {

	uint16_t result = (uint16_t) most;
	result = result << 8;
	result = result | (uint16_t) least;
	return result;
}

int main(int argc, char *argv[]) {

	printf("%i\n", assemble(1,2));	
	return 0;
}
