/**
 * @author Simon Petit
 *
 * @file 
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



#endif
