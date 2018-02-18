/**
 * @author Simon Petit
 *
 * @file vector.h
 * Implementation of a vector struct and functions associated to it.
 * This implementation is related to the math definition of the vector
 * and of the following functions.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include "matrix.h"

typedef struct vector vector;

/**
 * @struct vector
 */
struct vector
{
    int n;
    double *values;
};

/**
 * @param[in] size The dimension of the vector.
 * @return vector pointer of length size.
 */
vector *zero(int size);

/**
 * @param[in] v A vector pointer.
 * @return size of v.
 */
int size(vector *v);

/**
 * @param[in] v A vector pointer.
 * @param[in] i The index of the component to retrieve.
 * @return i-th component.
 */
double get(vector *v, int i);

/**
 * @param[in] v A vector pointer.
 * @param[in] i The index of the component to replace.
 * @param[in] x The new value.
 */
void set(vector *v, int i, double x);

/**
 * @param[in] u A vector pointer.
 * @param[in] v A vector pointer.
 * @return 1 if both vectors have the same dimension,
 * 0 otherwise (the operation is not defined).
 */
int vector_add(vector *u, vector *v);

/**
 * @param[in] u A vector pointer.
 * @param[in] v A vector pointer.
 * @return 1 if both vectors have the same dimension,
 * 0 otherwise (the operation is not defined).
 */
int vector_sub(vector *u, vector *v);

/**
 * @param[in] u A vector pointer.
 * @param[in] v A vector pointer.
 * @param[out] m A matrix pointer to store the result of the product.
 * @return 1 if both vectors have the same dimension,
 * 0 otherwise (the operation is not defined).
 */
int vector_mul(vector *u, vector *v, matrix *m);

/**
 * @param[in] u A vector pointer.
 * @param[in] v A vector pointer.
 * @return the scalar product of them (double format) or -1 if
 * they are not of the same length.
 */
double scalar(vector *u, vector *v);

/**
 * @param[in] v A vector pointer.
 * @return the euclidian norm
 */
double norm(vector *v);

/**
 * @param[in] v A vector pointer.
 */
void destroy(vector *v);

#endif
