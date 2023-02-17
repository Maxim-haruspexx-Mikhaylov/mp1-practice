#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void alloc_matrix(TMatrix** matrix, int n)
{
    *matrix = (TMatrix*)malloc(sizeof(TMatrix) * 1);
    (*matrix)->n = n;
    (*matrix)->x = (double*)malloc(sizeof(double) * n * n);
}

void free_matrix(TMatrix** matrix)
{
    free((*matrix)->x);
    free(*matrix);
}

void fill_matrix(TMatrix* matrix)
{
    int i = 0;
    for (; i < (matrix->n * matrix->n); i++)
    {
        scanf("%lf", &(matrix->x[i]));
    }
}

void print_matrix(TMatrix* matrix)
{
    int i = 0;
    int num = matrix->n;
    for (; i < num * num; i++)
    {
        if (i >= num && i%num == 0) printf("\n");
        printf("%.2lf ", matrix->x[i]);
        
    }
    printf("\n");
}

TMatrix* add_matrix(TMatrix* matrix1, TMatrix* matrix2)
{
    TMatrix* res;
    int i = 0;
    alloc_matrix(&res, matrix1->n);
    for (; i < res->n * res->n; i++)
    {
        res->x[i] = matrix1->x[i] + matrix2->x[i];
    }
    return res;
}

TMatrix* add_scalar(TMatrix* matrix, double c)
{
    TMatrix* res;
    int i = 0;
    alloc_matrix(&res, matrix->n);
    for (; i < res->n * res->n; i++)
    {
        res->x[i] = matrix->x[i] + c;
    }
    return res;
}

TMatrix* mult_by_scalar(TMatrix* matrix, double c)
{
    TMatrix* res;
    int i = 0;
    alloc_matrix(&res, matrix->n);
    for (; i < res->n * res->n; i++)
    {
        res->x[i] = matrix->x[i] * c;
    }
    return res;
}

TMatrix* mult_by_matrix(TMatrix* matrix1, TMatrix* matrix2)
{
    TMatrix* res;
    int i = 0;
    int j = 0;
    int z = 0;
    alloc_matrix(&res, matrix1->n);
    int num = res->n;
    for (i = 0 ; i < num; i++) {
        for (j = 0; j < num; j++) {
            res->x[i * num + j] = 0;
            for (z = 0; z < num; z++) {
                res->x[i * num + j] += matrix1->x[i * num + z] * matrix2->x[j + num * z];
            }
        }
    }

    return res;
}