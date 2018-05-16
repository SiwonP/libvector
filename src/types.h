/**
 * @author Simon Petit
 *
 * @file types.h
 */

#ifndef TYPES_H
#define TYPES_H

/**
 * @typedef matrix
 * @brief vector structure.
 */
typedef struct matrix matrix;

/**
 * @struct matrix
 *
 * @brief Real-valued Matrix math object.
 */
struct matrix
{
    /** Number of rows.*/
    int n;
    /** Number of columns.*/
    int m; 
    /** Elements of the matrix.*/
    struct vector **values; 

};

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

/**
 * @typedef complex_num
 *
 * @brief complex number structure.
 */
typedef struct complex_num complex_num;

/**
 * @struct complex_num
 *
 * @brief Representation of complex numbers.
 */
struct complex_num
{
    /** Real part.*/
    double x;
    /** Imaginary part.*/
    double y;
};

/**
 * @typedef quaternion
 *
 * @brief quaternion structure.
 */
typedef struct quaternion quaternion;

/**
 * @struct quaternion
 *
 * @brief Representation of quaternion numbers.
 */
struct quaternion
{
    /** Real part. */
    double a;

    /** First imaginary part. */
    double b;
    /** Second imaginary part. */
    double c;
    /** Third imaginary part. */
    double d;

};

#endif
