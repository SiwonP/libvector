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

int size(vector *v)
{
    return v->n;
}

double get(vector *v, int i)
{
    return v->values[i];
}

void set(vector *v, int i, double x)
{
    v->values[i] = x;
}

int vector_add(vector *u, vector *v)
{
  int res = 0;
  int i;
  
  if(size(v) == size(u)) {
      for(i = 0; i < size(u); i++) {
          double x = get(u,i);
          set(u,i, x+get(v,i));
      }
      res = 1;
  }
  return res;
}

int vector_sub(vector *u, vector *v)
{
    int res = 0;
    int i;

    if(size(u) == size(v)) {
        for (i = 0; i < size(u); i++) {
            double x = get(u,i);
            set(u, i, x + get(v, i));
        }
        res = 1;
    } 

    return res;
}

//TODO
int vector_mul(vector *u, vector *v, matrix *m)
{
    int res = 0;
    
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

double norm(vector *v)
{
    double res = 0;

    //TODO: Add infinity norm, and declinaison of p norms
    res = sqrt(scalar(v, v));

    return res;
}

void vector_free(vector *v)
{
    free(v->values);
    free(v);
}
