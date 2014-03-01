#include <stdio.h>
#include <stdlib.h>

char * interleave(char[] one, char[] two) {
	int countOne = 0;
	int countTwo = 0;

	while (one[countOne] != '\0') {countOne++;}
	while (two[countTwo] != '\0') {countTwo++;}

	char * final = malloc(countOne + countTwo - 1);
	int i = 0;
	int n = 0;

	while (one[i] != '\0' && two[i] != '\0') {
		final[n] = one[i];
		n++;
		final[n] = two[i];
		n++;
		i++;
	}
	if (one[i] == '\0') {
		for (int b = i; b < countTwo; b++;) {
			  final[b] = two[b];
		 }
	}
	else {
		for (int b = i; b < countOne; b++;) { 
			 final[b] = one[b];
		 }
	}
	return * final;

}

int main() {

	char *s = interleave("clips","aloe");
	printf("%s/n", s);
	return 0;
}
