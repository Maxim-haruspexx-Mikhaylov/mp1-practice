#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct {
	int n;
	double* x;
} TMatrix;

void alloc_matrix(TMatrix** matrix, int n);
void free_matrix(TMatrix** matrix);
void fill_matrix(TMatrix* matrix);
void print_matrix(TMatrix* matrix);
TMatrix* add_matrix(TMatrix* matrix1, TMatrix* matrix2);
TMatrix* add_scalar(TMatrix* matrix, double c);
TMatrix* mult_by_matrix(TMatrix* matrix1, TMatrix* matrix2);
TMatrix* mult_by_scalar(TMatrix* matrix, double c);


#endif !_MATRIX_H
