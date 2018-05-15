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
#include "types.h"

/**
 * @brief Create a null vector.
 *
 * @param[in] size The dimension of the vector.
 *
 * @return Vector pointer of length size.
 *
 * @relates vector
 */
vector *vector_zeros(int size);

/**
 * @brief Return the dimension (size) of v.
 *
 * @param[in] v A vector pointer.
 * @return size of v.
 *
 * @related vector
 */
int size(vector *v);

/**
 * @brief Return the value of the i-th component of v.
 *
 * @param[in] v A vector pointer.
 * @param[in] i The index of the component to retrieve.
 *
 * @return i-th component.
 *
 * @relates vector
 */
double get(vector *v, int i);

/**
 * @brief Change the value of the i-th component of v.
 *
 * @param[in] v A vector pointer.
 * @param[in] i The index of the component to replace.
 * @param[in] x The new value.
 *
 * @relates vector
 */
void set(vector *v, int i, double x);

/**
 * @brief Sum of two vector of the same dimension,
 * the new vector is stored in u, while v remains unchanged.
 *
 * @param[in] u A vector pointer.
 * @param[in] v A vector pointer.
 *
 * @return 0 if the addition can't be made because of dimension
 * incompatibility, 1 otherwise.
 *
 * @relates vector
 */
int vector_add(vector *u, vector *v);

/**
 * @brief Difference of the vectors of the same dimension,
 * the new vector if stored in u, while v remains unchanged.
 *
 * @param[in] u A vector pointer.
 * @param[in] v A vector pointer.
 *
 * @return 1 if both vectors have the same dimension,
 * 0 otherwise (the operation is not defined).
 *
 * @related vector
 */
int vector_sub(vector *u, vector *v);

/**
 * @brief Multiplication of vector such as the result is
 * a square matrix whose pointer in stored in m.
 *
 * @param[in] u A vector pointer.
 * @param[in] v A vector pointer.
 * @param[out] m A matrix pointer to store the result of the product.
 *
 * @return 1 if both vectors have the same dimension,
 * 0 otherwise (the operation is not defined).
 *
 * @relates vector
 * @related matrix
 */
int vector_mul(vector *u, vector *v, matrix *m);

/**
 * @brief The scalar product is the one whose
 * norm is the euclidian norm. In other words,
 * it is the operation \f$u^T v \f$.
 *
 * @param[in] u A vector pointer.
 * @param[in] v A vector pointer.
 *
 * @return The scalar product of them or -1 if
 * they are not of the same length.
 *
 * @relates vector
 */
double scalar(vector *u, vector *v);

/**
 * @brief The euclidian norm is calculated with the
 * formula \f$\left(\displaystyle\sum_{k=0}^{n-1} v_k^2\right)^{\frac{1}{2}}\f$
 *
 * @param[in] v A vector pointer.
 *
 * @return the euclidian norm
 *
 * @relates vector
 */
double norm(vector *v);

/**
 * @brief Free the allocated memory of the array of values and 
 * of the struct of the vector itself.
 *
 * @param[in] v A vector pointer.
 *
 * @relates vector
 */
void destroy(vector *v);

#endif
