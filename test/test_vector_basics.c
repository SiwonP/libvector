#include <criterion/criterion.h>
#include "../src/vector.h"

TestSuite(VectorBasics);

Test(VectorBasics, vector_zeros)
{
    vector *v = vector_zeros(1);
    cr_assert(vector_size(v) == 1);
    cr_assert(vector_get(v,0) == 0);
    vector_free(v);

    vector *u = vector_zeros(5);
    cr_assert(vector_size(u) == 5);
    int i;
    for (i = 0; i < vector_size(u); i++) {
        cr_assert(vector_get(u, i) == 0);
    }
    vector_free(u);
}

Test(VectorBasics, vector_setters_vector_getters)
{
    vector *v = vector_zeros(4);
    vector_set(v,2,2);
    cr_assert(vector_get(v,2) == 2);

    cr_assert(vector_get(v,0) == 0);

    vector_set(v,0,3);
    cr_assert(vector_get(v,0) == 3);

    vector_free(v);
}

Test(VectorBasics, vector_add)
{
    vector *u = vector_zeros(6);
    vector *v = vector_zeros(5);
    vector *w = vector_zeros(5);

    cr_assert(vector_add(u,v) == 0);
    cr_assert(vector_add(v,w) > 0);

    vector_set(w,0,1);
    vector_add(v, w);
    cr_assert(vector_get(v,0) == 1);

    vector_free(u);
    vector_free(v);
    vector_free(w);

}

Test(VectorBasics, scalar)
{
    vector *v = vector_zeros(3);
    vector *u = vector_zeros(3);

    vector_set(v,0,5);
    vector_set(u,1,4);

    cr_assert(scalar(u,v) == 0); 

    vector_set(u,0,3);

    cr_assert(scalar(u,v) == 15);

    vector_free(u);
    vector_free(v);
}

Test(VectorBasics, vector_norm)
{
    vector *v = vector_zeros(3);

    vector_set(v,0,1);
    cr_assert(vector_norm(v) == 1);
    cr_assert(vector_norm(v, "1") == 1);
    cr_assert(vector_norm(v, "2") == 1);
    cr_assert(vector_norm(v, "infinity") == 1);

    vector_set(v,1,1);
    cr_assert(vector_norm(v) == sqrt(2));
    cr_assert(vector_norm(v, "1") == 2);
    cr_assert(vector_norm(v, "2") == sqrt(2));
    cr_assert(vector_norm(v, "infinity") == 1);

    vector_set(v,2,2);
    cr_assert(vector_norm(v) == sqrt(6));
    cr_assert(vector_norm(v, "1") == 4);
    cr_assert(vector_norm(v, "infinity") == 2);

    vector_free(v);
}


