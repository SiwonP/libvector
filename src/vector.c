/**
 * @author Simon Petit
 *
 * @file 
 * Implementation of functions related to the vector structure.
 */
#include "vector.h"


vector *vector_zeros(int size)
{
    vector *v = calloc(2, sizeof(int)+sizeof(double*));
    v->n = size;
    double *val = calloc(size, size*sizeof(double));
    v->values = val;

    return v;
}

//TODO: creation of a vector from an array of numbers

int vector_size(vector *v)
{
    return v->n;
}

double vector_get(vector *v, int i)
{
    return v->values[i];
}

void vector_set(vector *v, int i, double x)
{
    v->values[i] = x;
}

int vector_add(vector *u, vector *v)
{
  int res = 0;
  int i;
  
  if(vector_size(v) == vector_size(u)) {
      for(i = 0; i < vector_size(u); i++) {
          double x = vector_get(u,i);
          vector_set(u,i, x+vector_get(v,i));
      }
      res = 1;
  }
  return res;
}

int vector_sub(vector *u, vector *v)
{
    int res = 0;
    int i;

    if(vector_size(u) == vector_size(v)) {
        for (i = 0; i < vector_size(u); i++) {
            double x = vector_get(u,i);
            vector_set(u, i, x + vector_get(v, i));
        }
        res = 1;
    } 

    return res;
}

double scalar(vector *u, vector *v)
{
    double res = 0;
    int i;

    if (u->n == v->n) {
        for (i = 0; i < u->n; i++) {
            res += u->values[i] * v->values[i];
        }
    } else {
        res = -1;
    }
    return res;
}

double vector_norm_base(vector *v, char *name)
{
    double res = 0;

    //TODO: Add infinity norm, and declinaison of p norms
    res = sqrt(scalar(v, v));

    return res;
}

double var_vector_norm(vector_norm_args in)
{
    char *n_out = in.name ? in.name : "2";
    return vector_norm_base(in.x, in.name);
}

void vector_free(vector *v)
{
    free(v->values);
    free(v);
}
