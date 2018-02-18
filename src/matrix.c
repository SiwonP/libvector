#include "matrix.h"

matrix *zeros(int size_n, int size_m)
{
    double **v = calloc(size_n*size_m, size_n*size_m*sizeof(double));
    matrix *M = calloc(3, 2*sizeof(int) + size_n*size_m*sizeof(double));
    M->n = size_n;
    M->m = size_m;
    M->values = v;
    return M;
}
    
