#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct {
	int numer;
	int denom;
} Rational;

Rational *make_rational(int numer, int denom) {
	Rational *rat = malloc(sizeof(Rational));
	if (rat == NULL) {printf("malloc error"); exit(1); }
	rat->numer = numer;
	rat->denom = denom;
	return rat;
}

double rational_to_double(Rational *rational) {
	float f = (float)rational->numer / (float)rational->denom;
	return f;
}
Rational *mult_rational(Rational *r1, Rational *r2) {
	Rational temp = malloc(sizeof(Rational));
	temp->numer = r1->numer * r2->numer;
	temp->denom = r1->denom * r2->denom;
	return temp;
}

