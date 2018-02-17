#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

typedef struct vector vector;

struct vector
{
    int n;
    double *values;
};

vector *zero(int);

int size(vector*);

double get(vector*, int);

void set(vector*, int, double);

int add_vector(vector*, vector*);

double scalar(vector*, vector*);

double norm(vector*);

void destroy(vector*);

#endif
