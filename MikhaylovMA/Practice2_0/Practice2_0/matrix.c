#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void alloc_matrix(TMatrix** matrix, int n)
{
    *matrix = (TMatrix*)malloc(sizeof(TMatrix) * 1);
    (*matrix)->n = n;
    (*matrix)->x = (double**)malloc(sizeof(double*) * n);
    for (int i = 0; i < n; i++) {
          *((*matrix)->x[i]) = (double*)malloc(n * sizeof(double));
        }
}

void free_matrix(TMatrix** matrix)
{

}
