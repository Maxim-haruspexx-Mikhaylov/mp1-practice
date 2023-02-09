#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct {
	int n;
	double* x;
} TMatrix;

void alloc_matrix(TMatrix** matrix, int n);
void free_matrix(TMatrix** matrix);



#endif !_MATRIX_H
