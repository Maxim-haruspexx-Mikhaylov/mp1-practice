#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int main() {
	int n = 2;
	double con1 = 4.6;
	int con2 = 2;
	TMatrix* matrix1, * matrix2, * res;

	alloc_matrix(&matrix1, n);
	alloc_matrix(&matrix2, n);

	fill_matrix(matrix1);
	fill_matrix(matrix2);
	printf("\n");

	print_matrix(matrix1);
	printf("\n");
	print_matrix(matrix2);
	printf("\n");

	res = add_matrix(matrix1, matrix2);
	print_matrix(res);
	printf("\n");
	free_matrix(&res);

	res = mult_by_matrix(matrix1, matrix2);
	print_matrix(res);
	printf("\n");
	free_matrix(&res);

	res = add_scalar(matrix1, con1);
	print_matrix(res);
	printf("\n");
	free_matrix(&res);

	res = mult_by_scalar(matrix1, con2);
	print_matrix(res);
	printf("\n");
	free_matrix(&res);

	return 0;
}