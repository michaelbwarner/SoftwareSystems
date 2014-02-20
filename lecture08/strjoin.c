/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *tracks[] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};

/* Returns a heap-allocated string that contains the strings 
   from the given array, joined up with no spaces between.
*/
char *strjoin(char *array[], int n)
{
	int totalLen = 0;
	int b;
	for(b = 0; b < n; b++) {
		totalLen += strlen(array[b]);
	}
	printf("total num of characters in strings: %i\n", totalLen);
	char *final = malloc(totalLen * sizeof(char));
	
	int i; int lastPos = 0;
	for(b = 0; b < n; b++) {
		for (i = 0; i < strlen(array[b]); i++) {
			if (array[b][i] != ' ') {
				//printf("%c\n", array[b][i]);
				final[lastPos] = array[b][i];
				lastPos++; 
			}
		}
	}
	final[lastPos] = '\0';

    return final;
}


int main (int argc, char *argv[])
{
    char *s = strjoin(tracks, 5);
    printf("%s\n", s);
    return 0;
}
