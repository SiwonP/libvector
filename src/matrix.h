#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct Matrix Matrix;

struct Matrix
{
    int n;
    int m;
    double **values;

};

Matrix *zeros(int, int);

#endif
