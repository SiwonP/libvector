#include <criterion/criterion.h>
#include "../src/vector.h"

TestSuite(VectorBasics);

Test(VectorBasics, v_zeros)
{
    vector *v = v_zeros(1);
    cr_assert(v_size(v) == 1);
    cr_assert(v_get(v,0) == 0);
    v_free(v);

    vector *u = v_zeros(5);
    cr_assert(v_size(u) == 5);
    int i;
    for (i = 0; i < v_size(u); i++) {
        cr_assert(v_get(u, i) == 0);
    }
    v_free(u);
}

Test(VectorBasics, v_setters_v_getters)
{
    vector *v = v_zeros(4);
    v_set(v,2,2);
    cr_assert(v_get(v,2) == 2);

    cr_assert(v_get(v,0) == 0);

    v_set(v,0,3);
    cr_assert(v_get(v,0) == 3);

    v_free(v);
}

Test(VectorBasics, v_add)
{
    vector *u = v_zeros(6);
    vector *v = v_zeros(5);
    vector *w = v_zeros(5);

    cr_assert(v_add(u,v) == 0);
    cr_assert(v_add(v,w) > 0);

    v_set(w,0,1);
    v_add(v, w);
    cr_assert(v_get(v,0) == 1);

    v_free(u);
    v_free(v);
    v_free(w);

}

Test(VectorBasics, scalar)
{
    vector *v = v_zeros(3);
    vector *u = v_zeros(3);

    v_set(v,0,5);
    v_set(u,1,4);

    cr_assert(v_scalar(u,v) == 0); 

    v_set(u,0,3);

    cr_assert(v_scalar(u,v) == 15);

    v_free(u);
    v_free(v);
}

Test(VectorBasics, v_norm)
{
    vector *v = v_zeros(3);

    v_free(v);
}

Test(VectorBasics, size)
{
    vector *v = v_zeros(3);
    cr_assert(v_size(v) == 3);
    v_free(v);
}
