#include <criterion/criterion.h>
#include "../src/matrix.h"
#include "../src/vector.h"
#include "../src/complex.h"

TestSuite(matrix);

Test(matrix, matrix_zero)
{
    matrix *m = matrix_zeros(3,3);
    cr_assert(m->n == 3);
    cr_assert(m->m == 3);

    matrix_free(m);
}

Test(matrix, get_number_of_rows)
{
    matrix *m = matrix_zeros(4,8);
    matrix *m2 = matrix_identity(7);

    cr_assert(get_number_of_rows(m) == 4);
    cr_assert(get_number_of_rows(m2) == 7);

    matrix_free(m);
    matrix_free(m2);
}

Test(matrix, get_number_of_columns)
{
    matrix *m = matrix_zeros(4,8);
    matrix *m2 = matrix_identity(7);

    cr_assert(get_number_of_columns(m) == 8);
    cr_assert(get_number_of_columns(m2) == 7);

    matrix_free(m);
    matrix_free(m2);
}

Test(matrix, matrix_identity)
{
    matrix *m = matrix_identity(4);
    int i, j;
    for (i = 0; i < get_number_of_rows(m); i++) {
        for (j = 0; j < get_number_of_columns(m); j++) {
            if( i == j) {
               cr_assert(matrix_get(m, i, j) == 1);
            } else {
               cr_assert(matrix_get(m, i, j) ==  0);
            }
        }
    }

    matrix_free(m);
}

