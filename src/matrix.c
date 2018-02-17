#include "matrix.h"

Matrix *zeros(int size_n, int size_m)
{
    double **v = calloc(size_n*size_m, size_n*size_m*sizeof(double));
    Matrix *M = calloc(3, 2*sizeof(int) + size_n*size_m*sizeof(double));
    M->n = size_n;
    M->m = size_m;
    M->values = v;
    printf("%lf\n", v[0][0]);
    return M;
}
    
