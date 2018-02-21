/**
 * @author Simon Petit
 *
 * @file complex.h
 * Implementation of complex numbers.
 * This will follow the classic mathematical definition of complex numbers
 * as well as the classi functions involving complex numbers.
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "vector.h"

typedef struct complex_num complex_num;

/**
 * @struct complex_num
 */
struct complex_num {
    /** Real part.*/
    double x;
    /** Imaginary part.*/
    double y;
};

/**
 * @param[in] a Real part.
 * @param[in] b Imaginary part.
 * @return A complex_num pointer.
 *
 * @relates complex_num
 */
complex_num *cartesian(double a, double b);

/**
 * @param[in] r Modulus of the complex.
 * @param[in] theta Argument of the complex.
 * @return A complex_num pointer.
 *
 * @relates complex_num
 */
complex_num *polar(double r, double theta);

/**
 * @param[in] a Array of length 2 as [real part, imaginary part]
 * @return A complex_num pointer.
 *
 * @relates complex_num
 */
complex_num *cartesian_from_array(double a[2]);

/**
 * @param[in r Array of length 2 as [modulus, argument].
 * @return A complex_num pointer.
 *
 * @relates complex_num
 */
complex_num *polar_from_array(double r[2]);

/**
 * @param[in] v A vector of dimension 2 whose first component is the real part
 * and the second the imaginary part.
 * @return A complex_num pointer.
 *
 * @relates complex_num
 */
complex_num *cartesian_from_vector(vector *v);

/**
 * @param[in] z A complex_num pointer.
 * @return Its real part
 *
 * @relates complex_num
 */ 
double real_part(complex_num *z);

/**
 * @param[in] z A complex_num pointer.
 * @return Its imaginary part
 *
 * @relates complex_num
 */ 
double im_part(complex_num *z);

/**
 * @param[in] z A complex_num pointer.
 *
 * @relates complex_num
 */
void print_complex(complex_num *z);

/**
 * @param[in] u A complex_num pointer.
 * @param[in] v A complex_num pointer.
 * @return The sum of them.
 *
 * @relates complex_num
 */
complex_num *complex_add(complex_num *u, complex_num *v);

/**
 * @param[in] u A complex_num pointer.
 * @param[in] v A complex_num pointer.
 * @return The difference between the first and the second.
 *
 * @relates complex_num
 */
complex_num *complex_sub(complex_num *u, complex_num *v);

/**
 * @param[in] z A complex_num pointer.
 * @return Its conjugate.
 *
 * @relates complex_num
 */
complex_num *conjugate(complex_num *z);

/**
 * @param[in] z A complex_num pointer.
 * @return Its modulus.
 *
 * @relates complex_num
 */
double modulus(complex_num *z);

/**
 * @param[in] z A complex_num pointer.
 *
 * @relates complex_num
 */
void complex_destroy(complex_num *z);

#endif
