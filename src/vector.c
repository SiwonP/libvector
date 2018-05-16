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
    int i, p = atoi(name);
    char inf[] = "infinity", euc[] = "euclidian";

    if (strcmp(inf, name) == 0) {
        double max = v->values[0];
        for (i = 0; i < v->n; i++) { 
            if (v->values[i] > max) {
                max = v->values[i];
            }
        }
        res = max;
    } else if(strcmp(euc, name) == 0 || p == 2) {
        res = sqrt(scalar(v, v));
    } else if (p > 0) {
        for (i = 0; i < v->n; i++) {
            res += pow(fabs(v->values[i]),p);
        }
        res = pow(res, 1/p);
    }
    return res;
}

double var_vector_norm(vector_norm_args in)
{
    char *n_out = in.name ? in.name : "euclidian";
    return vector_norm_base(in.x, n_out);
}

void vector_free(vector *v)
{
    free(v->values);
    free(v);
}
