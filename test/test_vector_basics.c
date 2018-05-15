#include <criterion/criterion.h>
#include "../src/matrix.h"
#include "../src/vector.h"
#include "../src/complex.h"

TestSuite(vector);

Test(vector, vector_zeros)
{
    vector *v = vector_zeros(1);
    cr_assert(size(v) == 1);
    cr_assert(get(v,0) == 0);
    vector_free(v);

    vector *u = vector_zeros(5);
    cr_assert(size(u) == 5);
    int i;
    for (i = 0; i < size(u); i++) {
        cr_assert(get(u, i) == 0);
    }
    vector_free(u);
}

Test(vector, setters_getters)
{
    vector *v = vector_zeros(4);
    set(v,2,2);
    cr_assert(get(v,2) == 2);

    cr_assert(get(v,0) == 0);

    set(v,0,3);
    cr_assert(get(v,0) == 3);

    vector_free(v);
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

    vector_free(u);
    vector_free(v);
    vector_free(w);

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

    vector_free(u);
    vector_free(v);
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

    vector_free(v);
}


