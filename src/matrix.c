/**
 * @author Simon Petit
 *
 * @file matrix.c
 */
#include "matrix.h"

matrix *matrix_zeros(int size_n, int size_m)
{
    vector **v = calloc(size_n*size_m, size_n*size_m*sizeof(vector));
    for(int i = 0; i < size_n; i++) {
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
    for (int i = 0; i < size; i++) {
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
    //TODO: Make sure i is < get_number_of_rows(m)
    return m->values[i];
}

vector *get_column(matrix *m, int j)
{
    //TODO: Make sure j is <= get_number_of_columns
    vector *v = vector_zeros(get_number_of_rows(m));
    
    for (int i = 0; i < get_number_of_rows(m); i++) {
        set(v,i,get(get_row(m,i),j));       
    }
    return v;
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

int matrix_add(matrix *m, matrix *n)
{
    int res = 0;
    
    if (get_number_of_columns(m) == get_number_of_columns(n)
            && get_number_of_rows(m) == get_number_of_rows(m)) {
        for (int i = 0; i < get_number_of_rows(m); i++) {
            for (int j = 0; j < get_number_of_columns(m); j++) {
                matrix_set(m, i, j, matrix_get(m, i, j) + matrix_get(n, i, j));
            }
        }
        res = 1;
    } 
    return res;
}

int matrix_sub(matrix *m, matrix *n)
{    
    int res = 0;
    
    if (get_number_of_columns(m) == get_number_of_columns(n)
            && get_number_of_rows(m) == get_number_of_rows(m)) {
        for (int i = 0; i < get_number_of_rows(m); i++) {
            for (int j = 0; j < get_number_of_columns(m); j++) {
                matrix_set(m, i, j, matrix_get(m, i, j) - matrix_get(n, i, j));
            }
        }
        res = 1;
    } 
    return res;

}

double determinant(matrix *m)
{
    double res = 0;

    return res;
}

void matrix_destroy(matrix *m)
{       
    for (int i = 0; i < get_number_of_rows(m); i++) {
        destroy(get_row(m, i));
    }
    free(m);
}
