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
#include <stdarg.h>
#include <string.h>

#define vector_norm(...) var_vector_norm((vector_norm_args){__VA_ARGS__})

/**
 * @typedef vector
 *
 * @brief vector structure.
 */
typedef struct vector vector;

/**
 * @struct vector
 *
 * @brief Real-valued Vector math object.
 */
struct vector
{
    /** Length of the vector.*/
    int n;
    /** Element of the vector.*/
    double *values;
};

typedef struct vector_norm_args vector_norm_args;

struct vector_norm_args
{
    vector *x;
    char *name;
};


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
int vector_size(vector *v);

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
double vector_get(vector *v, int i);

/**
 * @brief Change the value of the i-th component of v.
 *
 * @param[in] v A vector pointer.
 * @param[in] i The index of the component to replace.
 * @param[in] x The new value.
 *
 * @relates vector
 */
void vector_set(vector *v, int i, double x);

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
 * @brief 
 *
 * @param[in] v A vector pointer.
 * @param[in] name The name of the norm, "1", "2" ... "p", "euclidian" or
 * "infinity". 
 *
 * @return The named norm.
 *
 * @relates vector
 */
double vector_norm_base(vector *v, char *name);

/**
 * @brief Computer the norm from the structure given.
 *
 * @param[in] in A vector_norm_args object
 *
 * @return The norm in.name of in.x. If n.name not specified, the euclidian norm
 * is chosen by default.
 */
double var_vector_norm(vector_norm_args in);

/**
 * @brief Free the allocated memory of the array of values and 
 * of the struct of the vector itself.
 *
 * @param[in] v A vector pointer.
 *
 * @relates vector
 */
void vector_free(vector *v);

#endif
