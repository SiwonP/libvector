#include <math.h>
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

int add_vector(vector *v, vector *u)
{
  int res;
  
  if(size(v) == size(u)) {
      for(int i = 0; i < size(u); i++) {
          double x = get(v,i);
          set(v,i, x+get(u,i));
      }
      res = 1;
  } else {
      res = -1;
  }

  return res;
}

/*
 * @param: u and v, both vector pointers
 * @returns: a double formatted scalar products if the vectors have
 * the same size, -1 otherwise
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

double norm(vector *v)
{
    double res = 0;

    //TODO: Add infinity norm, and declinaison of p norms
    res = sqrt(scalar(v, v));

    return res;
}

/*
 * @param: a vector pointer v
 */
void destroy(vector *v)
{
    free(v->values);
    free(v);
}
