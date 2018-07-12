#ifndef STATISTICS_H
#define STATISTICS_H

#include "vector.h"

/**
 * @brief Compute the mean estimator of a vector.
 *
 * @param[in] v A vector pointer.
 *
 * @returns The mean estimator.
 */
double v_mean(vector *v);

/**
 * @brief Compute the unbiaised variance estimator.
 *
 * @param[in] v a Vector pointer.
 *
 * @return The variance.
 */
double v_variance(vector *v);

/**
 * @brief Compute the covariance of two vectors.
 *
 * @param[in] u A vector pointer.
 * @param[in] v A vector pointer.
 *
 * @return The covariance.
 */
double v_covariance(vector *u, vector *v);

/**
 * @brief Compute the auto-correlation of a vector.
 *
 * @param[in] u A vector pointer.
 * @param[in] k The shift index.
 *
 * @return The auto-correlation.
 */
double v_auto_correlation(vector *u, int k);

/**
 * @brief Compute the correlation between two vectors.
 *
 * @param[in] u A vector pointer.
 * @param[in] v A vector pointer.
 *
 * @return The correlation.
 */
double v_correlation(vector *u, vector *v);

#endif
