/**
 * @author Simon Petit
 *
 * @file complex.h
 * Implementation of complex numbers.
 * This will follow the classic mathematical definition of complex numbers
 * as well as the classi functions involving complex numbers.
 *
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "vector.h"

/**
 * @typedef complex_num
 * @brief complex number structure.
 */
typedef struct complex_num complex_num;

/**
 * @struct complex_num
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
 * @brief Creates and returns the cartesiand form of a complex number
 * from a couple of real numbers.
 *
 * @param[in] a Real part.
 * @param[in] b Imaginary part.
 * @return A complex_num pointer.
 *
 * @relates complex_num
 */
complex_num *cartesian(double a, double b);

/**
 * @brief Creates and returns the cartesian form of
 * a complex number from its modulus and its argument.
 *
 * @param[in] r Modulus of the complex.
 * @param[in] theta Argument of the complex.
 * @return A complex_num pointer.
 *
 * @relates complex_num
 */
complex_num *polar(double r, double theta);

/**
 * @brief Creates and returns the cartesian form of
 * a complex number from a two elements long array.
 *
 * @param[in] a Array of length 2 as [real part, imaginary part]
 * @return A complex_num pointer.
 *
 * @relates complex_num
 */
complex_num *cartesian_from_array(double a[2]);

/**
 * @brief Creates and returns the cartesian form of
 * a complex number from a two elements long array
 * containing its modulus and its argument.
 *
 * @param[in] r Array of length 2 as [modulus, argument].
 * @return A complex_num pointer.
 *
 * @relates complex_num
 */
complex_num *polar_from_array(double r[2]);

/**
 * @brief Creates and returns a complex number
 * from a two dimension vector.
 *
 * @param[in] v A vector of dimension 2 whose first component is the real part
 * and the second the imaginary part.
 * @return A complex_num pointer.
 *
 * @relates complex_num
 */
complex_num *cartesian_from_vector(vector *v);

/**
 * @brief Returns the real part of the complex.
 *
 * @param[in] z A complex_num pointer.
 * @return Its real part
 *
 * @relates complex_num
 */ 
double real_part(complex_num *z);

/**
 * @brief Returns the imaginary part of the complex.
 *
 * @param[in] z A complex_num pointer.
 * @return Its imaginary part
 *
 * @relates complex_num
 */ 
double im_part(complex_num *z);

/**
 * @brief Displays the cartesian form of the complex number.
 *
 * @param[in] z A complex_num pointer.
 *
 * @relates complex_num
 */
void print_complex(complex_num *z);

/**
 * @brief Sum of two complex numbers.
 *
 * @param[in] u A complex_num pointer.
 * @param[in] v A complex_num pointer.
 * @return The sum of them.
 *
 * @relates complex_num
 */
complex_num *complex_add(complex_num *u, complex_num *v);

/**
 * @brief Difference of two complex numbers.
 *
 * @param[in] u A complex_num pointer.
 * @param[in] v A complex_num pointer.
 * @return The difference between the first and the second.
 *
 * @relates complex_num
 */
complex_num *complex_sub(complex_num *u, complex_num *v);

/**
 * @brief Product of two complex numbers.
 *
 * @param[in] u A complex_num pointer.
 * @param[in] v A complex_num pointer.
 *
 * @return The product of them.
 *
 * @relates complex_num
 */
complex_num *complex_mul(complex_num *u, complex_num *v);

/**
 * @brief Sum of a complex number and a real
 * 
 * @param[in] u A complex_num pointer.
 * @param[in] x A real.
 * 
 * @return The sum of them.
 *
 * @relates complex_num
 */
complex_num *complex_add_real(complex_num *u, double x);

/**
 * @brief Difference between a complex number and a real
 *
 * @param[in] u A complex_num pointer.
 * @param[in] x A real.
 *
 * @return The difference.
 *
 * @relates complex_num
 */
complex_num *complex_sub_real(complex_num *u, double x);

/**
 * @brief Product of a complex and a real.
 *
 * @param[in] u A complex_num pointer.
 * @param[in] x A real.
 *
 * @return The product.
 *
 * @relates complex_num
 */
complex_num *complex_mul_real(complex_num *u, double x);

/**
 * @brief Division of a complex and a real.
 *
 * @param[in] u A complex_num pointer.
 * @param[in] x A real.
 *
 * @return The quotient.
 *
 * @relates complex_num
 */
complex_num *complex_div_real(complex_num *u, double x);

/**
 * @brief Computes and returns the conjugate.
 *
 * @param[in] z A complex_num pointer.
 * @return Its conjugate.
 *
 * @relates complex_num
 */
complex_num *conjugate(complex_num *z);

/**
 * @brief Compute the negative complex.
 *
 * @param[in] z A complex_num pointer.
 * 
 * @returns The negative complex.
 *
 * @relates complex_num
 */
complex_num *complex_neg(complex_num *z);

/**
 * @brief Compute the modulus of the complex
 * as \f$\sqrt(x^2 + y^2)\f$.
 *
 * @param[in] z A complex_num pointer.
 * @return Its modulus.
 *
 * @relates complex_num
 */
double modulus(complex_num *z);

/**
 * @brief Frees the memory.
 *
 * @param[in] z A complex_num pointer.
 *
 * @relates complex_num
 */
void complex_free(complex_num *z);

#endif
