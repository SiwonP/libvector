#include "vector.h"

vector *zero(int size)
{
    vector *v = calloc(2, sizeof(int)+sizeof(double*));
    v->n = size;
    double *val = calloc(size, size*sizeof(double));
    v->values = val;

    return v;
}

//TODO: creation of a vector from an array of numbers

/**
 * @Brief Returnt the dimension (size) of v.
 */
int size(vector *v)
{
    return v->n;
}

/**
 * @brief Return the value of the i-th component
 * of v.
 */
double get(vector *v, int i)
{
    return v->values[i];
}

/**
 * @brief Change the value of the i-th component
 * of v.
 */
void set(vector *v, int i, double x)
{
    v->values[i] = x;
}

/**
 * @brief Sum of two vector of the same dimension,
 * the new vector is stored in u, while v remains unchanged.
 */
int vector_add(vector *u, vector *v)
{
  int res = 0;
  
  if(size(v) == size(u)) {
      for(int i = 0; i < size(u); i++) {
          double x = get(u,i);
          set(u,i, x+get(v,i));
      }
      res = 1;
  }
  return res;
}

/**
 * @brief Difference of the vectors of the same dimension,
 * the new vector if stored in u, while v remains unchanged.
 */
int vector_sub(vector *u, vector *v)
{
    int res = 0;

    if(size(u) == size(v)) {
        for (int i = 0; i < size(u); i++) {
            double x = get(u,i);
            set(u, i, x + get(v, i));
        }
        res = 1;
    } 

    return res;
}

/**
 * @brief Multiplication of vector such as the result is
 * a square matrix whose pointer in stored in m.
 */
int vector_mul(vector *u, vector *v, matrix *m)
{
    int res = 0;
    
    return res;
}

/**
 * @brief The scalar product is the one whose
 * norm is the euclidian norm. In other words,
 * it is the operation \f$u^T v \f$.
 */
double scalar(vector *u, vector *v)
{
    double res = 0;
    if (u->n == v->n) {
        for (int i = 0; i < u->n; i++) {
            res += u->values[i] * v->values[i];
        }
    } else {
        res = -1;
    }
    return res;
}

/**
 * @brief The euclidian norm is calculated with the
 * formula \f$\left(\displaystyle\sum_{k=0}^{n-1} v_k^2\right)^{\frac{1}{2}}\f$
 */
double norm(vector *v)
{
    double res = 0;

    //TODO: Add infinity norm, and declinaison of p norms
    res = sqrt(scalar(v, v));

    return res;
}

/**
 * @brief Free the allocated memory of the array of values and 
 * of the struct of the vector itself.
 */
void destroy(vector *v)
{
    free(v->values);
    free(v);
}
