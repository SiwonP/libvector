/**
 * @author Simon Petit
 *
 * @file vector.c
 * Implementation of functions related to vector and matrix.
 */
#include "vector.h"

vector *v_zeros(int size)
{
    vector *v;
    double *val;
    v = calloc(1, sizeof(vector));
    val = calloc(size, sizeof(double));
    v->n = size;
    v->values = val;
    return v;
}

vector *v_ones(int size)
{
    vector *v;
    int i;
    double *val;
    v = calloc(1, sizeof(vector));
    val = calloc(size, sizeof(double));
    v->n = size;
    for (i = 0; i < size; ++i) {
        val[i] = 1;
    }
    v->values = val;
    return v;
}

void v_print(vector *v)
{
    int i;
    printf("[ ");
    for (i = 0; i < v_size(v); i++) {
        printf("%lf ", v->values[i]);
    }
    printf("]\n");
}

matrix *m_zeros(int size1, int size2)
{
    int i;
    matrix *m;
    vector **val;
    m = calloc(1, sizeof(matrix));
    m->n = size1;
    m->m = size2;
    val = calloc(size1*size2, sizeof(vector*));
    for (i = 0; i < size1; i++) {
        val[i] = v_zeros(size2);
    }
    m->values = val;
    return m;
}

matrix *m_ones(int size1, int size2)
{
    int i;
    matrix *m;
    vector **val;
    m = calloc(1, sizeof(matrix));
    m->n = size1;
    m->m = size2;
    val = calloc(size1*size2, sizeof(vector*));
    for (i = 0; i < size1; i++) {
        val[i] = v_ones(size2);
    }
    m->values = val;
    return m;
}

matrix *m_identity(int size)
{
    matrix *m;
    int i;
    m = calloc(1, sizeof(matrix));
    m->n = size;
    m->m = size;
    for (i = 0; i < size; i++) {
        m_set(m, i, i, 1);
    }
    return m;
}

void m_print(matrix *m)
{
    int i, j, *size;
    for (i = 0; i < size[0]; i++) {
        for (j = 0 ; j < size[1]; j++) {
            printf("%lf\t", m_get(m, i, j));
        }
        printf("\n");
    }
}

int v_size(vector *v)
{
    return v->n;
}

int *m_size(matrix *m)
{
    static int size[2];
    size[0] = m->n;
    size[1] = m->m;
    return size;
}

double v_get(vector *v, int i)
{
    return v->values[i];
}

double m_get(matrix *m, int i, int j)
{
    return v_get(m->values[i], j);
}

void v_set(vector *v, int i, double x)
{
    v->values[i] = x;
}

void m_set(matrix *m, int i, int j, double x)
{
    v_set(m->values[i], j, x);
}

int v_add(vector *u, vector *v)
{
  int i, res = 0;
  if(v_size(v) == v_size(u)) {
      for(i = 0; i < v_size(u); i++) {
          double x = v_get(u,i);
          v_set(u,i, x+v_get(v,i));
      }
      res = 1;
  }
  return res;
}

int m_add(matrix *m, matrix *n)
{
    int i, j, res = 1, *s_m, *s_n;
    s_m = m_size(m);
    s_n = m_size(n);
    if (s_m[0] == s_n[0] && s_m[1] == s_n[1]) {
       for (i = 0; i < s_m[0]; i++) {
          for (j = 0; j < s_m[1]; j++) {
             m_set(m, i, j, m_get(m, i, j) + m_get(n, i, j));
          }
       } 
    } else {
        res = 0;
    }
    return res;
}

int v_sub(vector *u, vector *v)
{
    int i, res = 0;
    if(v_size(u) == v_size(v)) {
        for (i = 0; i < v_size(u); i++) {
            double x = v_get(u,i);
            v_set(u, i, x + v_get(v, i));
        }
        res = 1;
    } 
    return res;
}

int m_sub(matrix *m, matrix *n)
{
    int i, j, res = 1, *s_m, *s_n;
    s_m = m_size(m);
    s_n = m_size(n);
    if (s_m[0] == s_n[0] && s_m[1] == s_n[1]) {
        for (i = 0; i < s_m[0]; i++) {
            for (j = 0; j < s_m[1]; j++) {
                m_set(m, i, j, m_get(m, i, j) - m_get(n, i, j));
            }
        } 
    } else {
        res = 0;
    }
    return res;
}

double v_scalar(vector *u, vector *v)
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

matrix *v_mul(vector *u, vector *v)
{
    int i, j;
    matrix *m;

    if (v_size(u) == v_size(v)) {
        m = m_zeros(v_size(u), v_size(u));
        for (i = 0; i < v_size(u); i++) {
            for (j = 0; j < v_size(v); j++) {
                m_set(m, i, j, v_get(u, i) * v_get(v, j));
            }
        } 
    } else {
        //TODO handle error in case vector are not of 
        //the same length
    }
    return m;
}

int v_scalar_mul(vector *v, double x)
{
    int i, res = 1;
    for (i = 0; i < v_size(v); i++) {
        v_set(v, i, v_get(v, i) * x);
    }
    return res;
}

int m_mul(matrix *m, matrix *n)
{
    double c;
    int i, j, k, res = 1, *s_m, *s_n;
    s_m = m_size(m);
    s_n = m_size(n);

    if (s_m[1] == s_n[0]) {
        for (i = 0; i < s_m[0]; i++) {
            for (j = 0; j < s_n[1]; i++) {
                c = 0;
                for (k = 0; k < s_m[1]; k++) {
                    c += m_get(m, i, k) * m_get(n, k, j);
                }
                m_set(m, i, j, c);
            }
        }
    } else {
        res = 0;
    }
    return res;
}

int m_scalar_mul(matrix *m, double x)
{
    int i, j, res = 1, *size;
    for (i = 0; i < size[0]; i++) {
        for (j = 0; j < size[1]; j++) {
            m_set(m, i, j, m_get(m, i, j) * x);
        }
    }
    return res;
}

int v_equal(vector *u, vector *v)
{
    int i, equ = 0;
    if (v_size(u) == v_size(v)) {
        equ = 1;
        for (i = 0; i < v_size(u); ++i) {
            equ = equ && (v_get(u,i) == v_get(v,i));
        }
    }
    return equ;
}

int m_equal(matrix *m, matrix *n)
{
    int i, j, equ = 0;
    int *m_s, *n_s;
    m_s = m_size(m);
    n_s = m_size(n);
    
    if((m_s[0] == n_s[0]) && (m_s[1] == n_s[1])) {
        equ = 1;
        for (i = 0; i < m_s[0]; ++i) {
            for (j = 0; j < m_s[1]; ++j) {
                equ = equ && (m_get(m, i, j) == m_get(n, i, j));
            }
        }
    }
    return equ;
}
double v_euclidian_norm(vector *v)
{
    double norm;
    norm = sqrt(v_scalar(v,v));
    return norm;
}

double m_trace(matrix *m)
{
    double trace = 0;
    int i, j, *size;
    size = m_size(m);
    for (i = 0; i < size[0]; i++) {
        trace += m_get(m,i,i);
    }
    return trace;
}

matrix *m_transpose(matrix *m)
{
    int i, j;
    matrix *n;
    int *size = m_size(m);
    n = m_zeros(size[0], size[1]);
    for (i = 0; i < size[0]; i++) {
        for (j = 0; j < size[1]; j++) {
            m_set(n, j, i, m_get(m, i, j));
        }
    }
    return n;
}

double m_frobenius_norm(matrix *m)
{
    double norm = 0;
    matrix *n;
    n = m_transpose(m);
    m_mul(m, n);
    norm = m_trace(m);
    return norm;
}

void v_free(vector *v)
{
    free(v->values);
    free(v);
}

void m_free(matrix *m)
{
    free(m->values);
    free(m);
}
