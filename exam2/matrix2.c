/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    double **data;
    int rows, cols;
} Matrix;


// Makes a new matrix and sets all elements to zero.
Matrix *make_matrix(int rows, int cols) {
    int i;
    Matrix *matrix = malloc(sizeof(Matrix));

    matrix->data = malloc(rows * sizeof(double *));
    matrix->rows = rows;
    matrix->cols = cols;

    for (i=0; i<rows; i++) {
	// use calloc to initialize to 0
	matrix->data[i] = calloc(cols, sizeof(double));
    }
    return matrix;
}

// Prints the elements of a matrix.
void print_matrix(Matrix *matrix) {
    int i, j;

    for (i=0; i<matrix->rows; i++) {
	for (j=0; j<matrix->cols; j++) {
	    printf("%lf ", matrix->data[i][j]);
	}
	printf("\n");
    }
}

// Adds a scalar to all elements of a matrix.
void increment_matrix(Matrix *matrix, int incr) {
    int i, j;

    for (i=0; i<matrix->rows; i++) {
	for (j=0; j<matrix->cols; j++) {
	    matrix->data[i][j] += incr;
	}
    }
}

// Sets the elements of a matrix to consecutive numbers.
void consecutive_matrix(Matrix *matrix) {
    int i, j;

    for (i=0; i<matrix->rows; i++) {
	for (j=0; j<matrix->cols; j++) {
	    matrix->data[i][j] = i * matrix->cols + j;
	}
    }
}

// Adds two matrices elementwise and stores the result in the given
// destination matrix (C).
void add_matrix(Matrix *A, Matrix *B, Matrix *C) {
    int i, j;

    assert(A->rows == B->rows && B->rows == C->rows);
    assert(A->cols == B->cols && B->cols == C->cols);

    for (i=0; i<A->rows; i++) {
	for (j=0; j<A->cols; j++) {
	    C->data[i][j] =  A->data[i][j] + B->data[i][j];
	}
    }
}

// Adds two matrices elementwise and returns a new matrix.
Matrix *add_matrix_func(Matrix *A, Matrix *B) {
    Matrix *C = make_matrix(A->rows, A->cols);
    add_matrix(A, B, C);
    return C;
}

// Performs matrix multiplication and stores the result in the given
// destination matrix (C).
void mult_matrix(Matrix *A, Matrix *B, Matrix *C) {
    int i, j, k;

    assert(A->rows == B->cols);
    assert(A->rows == C->rows);
    assert(B->cols == C->cols);

    for (i=0; i<C->rows; i++) {
	for (j=0; j<C->cols; j++) {
	    for (k=0; k<A->cols; k++) {
		C->data[i][j] += A->data[i][k] * B->data[k][j];
	    }
	}
    }
}

// Performs matrix multiplication and returns a new matrix.
Matrix *mult_matrix_func(Matrix *A, Matrix *B) {
    Matrix *C = make_matrix(A->rows, B->cols);
    mult_matrix(A, B, C);
    return C;
}

double matrix_sum1(Matrix *A) {
    double total = 0.0;
    int i, j;

    for (i=0; i<A->rows; i++) {
	for (j=0; j<A->cols; j++) {
	    total += A->data[i][j];
	}
    }
    return total;
}
    
double matrix_sum2(Matrix *A) {
    double total = 0.0;
    int i, j;

    for (j=0; j<A->cols; j++) {
	for (i=0; i<A->rows; i++) {
	    total += A->data[i][j];
	}
    }
    return total;
}
    

// Adds up the rows of A and returns a heap-allocated array of doubles.
double *row_sum(Matrix *A) {
    double total;
    int i, j;

    double *res = malloc(A->rows * sizeof(double));

    for (i=0; i<A->rows; i++) {
	total = 0.0;
	for (j=0; j<A->cols; j++) {
	    total += A->data[i][j];
	}
	res[i] = total;
    }
    return res;
}
// adds up all the cols of A and return a heap-allocated array of doubles
double *col_sum(Matrix *A) {

	double total;
	int i, j;
	
	double *res = malloc(A->cols * sizeof(double));
	
	for (i=0; i<A->cols; i++) {
		total = 0.0;
		for (j = 0; j < A->rows; j++) {
			total += A->data[j][i];
		}
		res[i] = total;
	}
	return res;	
}
//adds up the diagonal across the matrix starting at the upper-left-hand corner going across
//returns double total if valid square matrix, -1.0 otherwise
double diagonal_TL(Matrix *A) {
	
	if (A->rows != A->cols) return -1.0;

	double total = 0.0;
	int i;	

	for (i=0; i<A->rows; i++) {
		total += A->data[i][i];
	}
	return total;
}
//adds up the diagonal across the matrix starting at the upper-right-hand corner going back across
//returns double total if valid square matrix, -1.0 otherwise
double diagonal_TR(Matrix *A) {
	
	if (A->rows != A->cols) return -1.0;

	double total = 0.0;
	int i;
		
	for (i=A->rows-1;i >= 0; i--) {
		total += A->data[i][i];
	}
	return total;
}


/*checks whether square array is magic or not. return 0 if not, 1 if true
*/
int is_magic_square(Matrix *A) {

	if (A->rows != A->cols) return 0;
	int i;
	double *rows, *cols; 
	rows = row_sum(A);
	cols = col_sum(A);

	double val = rows[0];

	for (i=0; i < A->rows; i++) {
		if (rows[i] != val) return 0;
	}

	for (i=0; i < A->cols; i++) {
		if (cols[i] != val) return 0;
	}

	if ((diagonal_TL(A) != val) || (diagonal_TL(A) != val)) return 0;

	return 1;

}


int main() {
    int i;
/*
    Matrix *A = make_matrix(3, 4);
    consecutive_matrix(A);
    printf("A\n");
    print_matrix(A);

    Matrix *C = add_matrix_func(A, A);
    printf("A + A\n");
    print_matrix(C);

    Matrix *B = make_matrix(4, 3);
    increment_matrix(B, 1);
    printf("B\n");
    print_matrix(B);

    Matrix *D = mult_matrix_func(A, B);
    printf("D\n");
    print_matrix(D);

    double sum = matrix_sum1(A);
    printf("sum = %lf\n", sum);

    sum = matrix_sum2(A);
    printf("sum = %lf\n", sum);

    double *sums = row_sum(A);
    for (i=0; i<A->rows; i++) {
	printf("row %d\t%lf\n", i, sums[i]);
    }
    // should print 6, 22, 38

	Matrix *S = make_matrix(4,4);
	increment_matrix(S, 1);
	printf("S\n");
	print_matrix(S);

	double diag = diagonal_TL(S);

	printf("%lf\n", diag);

	double diag2 = diagonal_TR(S);
	printf("%lf\n", diag2);
*/
	Matrix *M = make_matrix(3,3);
	
	M->data[0][0] = 2;
	M->data[0][1] = 7;
	M->data[0][2] = 6;

	M->data[1][0] = 9;
	M->data[1][1] = 5;
	M->data[1][2] = 1;

	M->data[2][0] = 4;
	M->data[2][1] = 3;
	M->data[2][2] = 8;

	printf("magic? %i\n", is_magic_square(M));

    return 0;
}
