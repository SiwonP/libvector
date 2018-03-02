#include <criterion/criterion.h>
#include "../src/matrix.h"
#include "../src/vector.h"
#include "../src/complex.h"

TestSuite(vector);

Test(vector, creation)
{
    vector *v = vector_zeros(1);
    cr_assert(size(v) == 1);
    cr_assert(get(v,0) == 0);
    destroy(v);

    vector *u = vector_zeros(5);
    cr_assert(size(u) == 5);
    for (int i = 0; i < size(u); i++) {
        cr_assert(get(u, i) == 0);
    }
    destroy(u);
}

Test(vector, setters_getters)
{
    vector *v = vector_zeros(4);
    set(v,2,2);
    cr_assert(get(v,2) == 2);

    cr_assert(get(v,0) == 0);

    set(v,0,3);
    cr_assert(get(v,0) == 3);

    destroy(v);
}

Test(vector, vector_add)
{
    vector *u = vector_zeros(6);
    vector *v = vector_zeros(5);
    vector *w = vector_zeros(5);

    cr_assert(vector_add(u,v) == 0);
    cr_assert(vector_add(v,w) > 0);

    set(w,0,1);
    vector_add(v, w);
    cr_assert(get(v,0) == 1);

    destroy(u);
    destroy(v);
    destroy(w);

}

Test(vector, scalar)
{
    vector *v = vector_zeros(3);
    vector *u = vector_zeros(3);

    set(v,0,5);
    set(u,1,4);

    cr_assert(scalar(u,v) == 0); 

    set(u,0,3);

    cr_assert(scalar(u,v) == 15);

    destroy(u);
    destroy(v);
}

Test(vector, norm)
{
    vector *v = vector_zeros(3);

    set(v,0,1);
    cr_assert(norm(v) == 1);

    set(v,1,1);
    cr_assert(norm(v) == sqrt(2));

    set(v,2,1);
    cr_assert(norm(v) == sqrt(3));

    destroy(v);
}

Test(complex_num, cartesian)
{
    complex_num *z = cartesian(1,1);
    cr_assert(real_part(z) == 1);
    cr_assert(im_part(z) == 1);

    complex_destroy(z);
}

Test(complex_num, polar)
{
    complex_num *z = polar(1, 2);
    cr_assert(real_part(z) == cos(2));
    cr_assert(im_part(z) == sin(2));

    complex_destroy(z);
}

Test(complex_num, complex_add)
{
    complex_num *u = cartesian(3, 5);
    complex_num *v = cartesian(6 ,-4);

    complex_num *z = complex_add(u, v);

    cr_assert(real_part(z) == 9);
    cr_assert(im_part(z) == 1);

    complex_destroy(z);
    complex_destroy(u);
    complex_destroy(v);
}

Test(complex_num, complex_sub)
{
    complex_num *u = cartesian(3, 5);
    complex_num *v = cartesian(6 ,-4);

    complex_num *z = complex_sub(u, v);

    cr_assert(real_part(z) == -3);
    cr_assert(im_part(z) == 9);

    complex_destroy(z);
    complex_destroy(u);
    complex_destroy(v);

}

Test(matrix, matrix_zero)
{
    matrix *m = matrix_zeros(3,3);
    cr_assert(m->n == 3);
    cr_assert(m->m == 3);

    matrix_destroy(m);
}

Test(matrix, get_number_of_rows)
{
    matrix *m = matrix_zeros(4,8);
    matrix *m2 = matrix_identity(7);

    cr_assert(get_number_of_rows(m) == 4);
    cr_assert(get_number_of_rows(m2) == 7);

    matrix_destroy(m);
    matrix_destroy(m2);
}

Test(matrix, get_number_of_columns)
{
    matrix *m = matrix_zeros(4,8);
    matrix *m2 = matrix_identity(7);

    cr_assert(get_number_of_columns(m) == 8);
    cr_assert(get_number_of_columns(m2) == 7);

    matrix_destroy(m);
    matrix_destroy(m2);
}

Test(matrix, matrix_identity)
{
    matrix *m = matrix_identity(4);
    for (int i = 0; i < get_number_of_rows(m); i++) {
        for (int j = 0; j < get_number_of_columns(m); j++) {
            if( i == j) {
               cr_assert(matrix_get(m, i, j) == 1);
            } else {
               cr_assert(matrix_get(m, i, j) ==  0);
            }
        }
    }

    matrix_destroy(m);
}

