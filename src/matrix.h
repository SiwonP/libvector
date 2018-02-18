#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

typedef struct matrix matrix;

struct matrix
{
    int n;
    int m;
    double **values;

};

matrix *zeros(int, int);

#endif
