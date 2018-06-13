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
#include <complex.h>
#include <string.h>

/**
 * @struct vector
 *
 * @typedef vector
 *
 * @brief Real-valued Vector math object.
 */
typedef struct vector
{
    int n; /**< Number of rows of the vector. */
    double *values; /**< Values of the vector. */

} vector;

/**
 * @struct matrix
 *
 * @typedef matrix
 *
 * @brief Real-valued Matrix math object.
 */
typedef struct matrix
{
    int n; /**< Number of rows of the matrix. */
    int m; /**< Number of columns of the matrix. */
    vector *values; /**< Values of the matrix. */
} matrix;
        

/**
 * @brief Create a null vector.
 *
 * @param[in] size The dimension of the vector.
 *
 * @return Vector pointer of length size.
 *
 * @relates vector
 */
vector *v_zeros(int size);

/**
 * @brief Return the dimension (size) of v.
 *
 * @param[in] v A vector pointer.
 * @return size of v.
 *
 * @related vector
 */
int v_size(vector *v);

/**
 * @brief Return the dimensions of the matrix.
 *
 * @param[in] m A matrix pointer.
 *
 * @return Dimension of the matrix as a int array.
 */
int *m_size(matrix *m);

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
double v_get(vector *v, int i);

/**
 * @brief Return the value of the i-th row and the j-th column of the matrix.
 *
 * @param[in] m A matrix pointer.
 * @param[in] i The row index.
 * @param[in] j The column index.
 *
 * @return Component i,j.
 *
 * @relates matrix
 */
double m_get(matrix *m, int i, int j);

/**
 * @brief Change the value of the i-th component of v.
 *
 * @param[in] v A vector pointer.
 * @param[in] i The index of the component to replace.
 * @param[in] x The new value.
 *
 * @relates vector
 */
void v_set(vector *v, int i, double x);

/**
 * @brief Change the value of the (i,j)-th component of m.
 *
 * @param[in] m A matrix pointer.
 * @param[in] i The row index.
 * @param[in] j The column index.
 * @param[in] x The new value.
 *
 * @relates matrix
 */
void m_set(matrix *m, int i, int j, double x);

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
int v_add(vector *u, vector *v);

/**
 * @brief Sum of two matrices.
 *
 * @param[in,out] m A matrix pointer. The result will be stored in this arg.
 * @param[in] n A matrix pointer.
 *
 * @return 1 if all went well, 0 either.
 *
 * @relates matrix
 */
int m_add(matrix *m, matrix *n);

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
 * @relates vector
 */
int v_sub(vector *u, vector *v);

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
double v_scalar(vector *u, vector *v);

/**
 * @brief The multiplication of two vector such that the result is a matrix.
 *
 * @param[in] u A vector pointer.
 * @param[in] v A vector pointer.
 * @param[out] m A matrix pointer : \f$M = uv^T\f$
 *
 * @return 1 if the product is done, 0 if not (vectors not of the same size).
 *
 * @relates vector
 */
int v_mul(vector *u, vector *v, matrix *m);

/**
 * @brief The multiplication of two matrices with appropriate dimensions.
 *
 * @para[in,out] m A matrix pointer. The result of the product will be stored
 * here.
 * @param[in] n A matrix pointer.
 *
 * @returns 1 if the product succeded, 0 otherwise.
 *
 * @relates matrix
 */
int m_mul(matrix *m, matrix *n);

/**
 * @brief Compute the euclidian norm of the vector.
 *
 * @param[in] v A vector pointer.
 *
 * @return The euclian norm computed based on the v_scalar function.
 *
 * @relates vector
 */
double v_euclidian_norm(vector *v);

/**
 * @brief Free the allocated memory of the array of values and 
 * of the struct of the vector itself.
 *
 * @param[in] v A vector pointer.
 *
 * @relates vector
 */
void v_free(vector *v);

/**
 * @brief Free the allocated memories of the matrix
 *
 * @param[in] m A matrix pointer
 *
 * @relates matrix
 */
void m_free(matrix *m);

#endif
