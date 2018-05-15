/**
 * @author Simon Petit
 *
 * @file
 *
 * Implementation of functions related to the matrix structure.
 */
#include "matrix.h"

matrix *matrix_zeros(int size_n, int size_m)
{
    vector **v = calloc(size_n*size_m, size_n*size_m*sizeof(vector));
    int i;
    for (i = 0; i < size_n; i++) {
        v[i] = vector_zeros(size_m);
    }
    matrix *M = calloc(3, 2*sizeof(int) + sizeof(vector**));
    M->n = size_n;
    M->m = size_m;
    M->values = v;
    return M;
}
    
matrix *matrix_identity(int size)
{
    vector **v = calloc(size*size, size*size*sizeof(vector));
    int j = 0;
    int i;
    for (i = 0; i < size; i++) {
        v[i] = vector_zeros(size);
        set(v[i],j,1);
        j++;
    }
    matrix *m = calloc(3, 2*sizeof(int) + sizeof(double**));
    m->n = size;
    m->m = size;
    m->values = v;
    
    return m;
}

int get_number_of_rows(matrix *m)
{
    return m->n;
}

int get_number_of_columns(matrix *m)
{
    return m->m;
}

vector *get_row(matrix *m, int i)
{
    vector *row = NULL;
    if (i < get_number_of_rows(m)) {
        row = m->values[i];
    }
    return row;
}

vector *get_column(matrix *m, int j)
{
    vector *col = NULL;
    int i;

    if (j < get_number_of_columns(m)) {
        col = vector_zeros(get_number_of_rows(m));

        for (i = 0; i < get_number_of_rows(m); i++) {
            set(col,i,get(get_row(m,i),j));       
        }
    }
    return col;
}

double matrix_get(matrix *m, int i, int j)
{
    double res;

    vector *v = get_row(m, i);

    res = get(v,j);

    return res;
}

void matrix_set(matrix *m, int i, int j, double x)
{
    set(get_row(m, i), j, x);
}

int matrix_add(matrix *m, matrix *n, matrix *o)
{
    int res = 0;
    int i, j;

    if (get_number_of_columns(m) == get_number_of_columns(n)
            && get_number_of_rows(m) == get_number_of_rows(m)) {
        for (i = 0; i < get_number_of_rows(m); i++) {
            for (j = 0; j < get_number_of_columns(m); j++) {
                matrix_set(o, i, j, matrix_get(m, i, j) + matrix_get(n, i, j));
            }
        }
        res = 1;
    } 
    return res;
}

int matrix_sub(matrix *m, matrix *n, matrix *o)
{    
    int res = 0;
    int i, j;

    if (get_number_of_columns(m) == get_number_of_columns(n)
            && get_number_of_rows(m) == get_number_of_rows(m)) {
        for (i = 0; i < get_number_of_rows(m); i++) {
            for (j = 0; j < get_number_of_columns(m); j++) {
                matrix_set(o, i, j, matrix_get(m, i, j) - matrix_get(n, i, j));
            }
        }
        res = 1;
    } 
    return res;

}

int matrix_mul(matrix *m, matrix *n, matrix *o)
{
    int res = 0;
    double c = 0;
    int i, j, k;

    if (get_number_of_rows(n) == get_number_of_columns(m)) {
        for (i = 0; i < get_number_of_columns(m); i++) {
            for (j = 0; j < get_number_of_rows(n); j++) {
                c = 0;
                for (k = 0; k < get_number_of_rows(n); k++) {
                    c += matrix_get(m, i, k) * matrix_get(n, k, j);
                }
                matrix_set(o, i, j, c);
            }
        }
    }

    return res;
}

double determinant(matrix *m)
{
    double res = 0;
//TODO: formula of the determinant


    return res;
}

int is_diagonal(matrix *m)
{
    int r = 1;
    int l = get_number_of_columns(m);
    int n = get_number_of_rows(m);
    int i, j;

    for (i = 0; i < l; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                r = r && (matrix_get(m, i, j) == 0);
            }
        }
    }
    return r;
}


void matrix_destroy(matrix *m)
{       
    int i;

    for (i = 0; i < get_number_of_rows(m); i++) {
        destroy(get_row(m, i));
    }
    free(m);
}
