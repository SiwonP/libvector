#include <criterion/criterion.h>
#include "../src/vector.h"

TestSuite(vector);

Test(vector, creation)
{
    vector *v = zero(1);
    cr_assert(size(v) == 1, "size");
    cr_assert(get(v,0) == 0, "value");
    destroy(v);

    vector *u = zero(5);
    cr_assert(size(u) == 5, "size");
    for (int i = 0; i < size(u); i++) {
        cr_assert(get(u, i) == 0, "values");
    }
    destroy(u);
}

Test(vector, setters_getters)
{
    vector *v = zero(4);
    set(v,2,2);
    cr_assert(get(v,2) == 2, "setter-getter");

    cr_assert(get(v,0) == 0, "getter");

    set(v,0,3);
    cr_assert(get(v,0) == 3, "setter-getter");

    destroy(v);
}

Test(vector, add_vector)
{
    vector *u = zero(6);
    vector *v = zero(5);
    vector *w = zero(5);

    cr_assert(add_vector(u, v) == -1);
    cr_assert(add_vector(v,w) > 0);

    set(w,0,1);
    add_vector(v, w);
    cr_assert(get(v,0) == 1);

    destroy(u);
    destroy(v);
    destroy(w);

}

Test(vector, scalar)
{
    vector *v = zero(3);
    vector *u = zero(3);

    set(v,0,5);
    set(u,1,4);

    cr_assert(scalar(u,v) == 0, "scalar product");

    set(u,0,3);

    cr_assert(scalar(u,v) == 15, "scalar product");

    destroy(u);
    destroy(v);
}

Test(vector, norm)
{
    vector *v = zero(3);

    set(v,0,1);
    cr_assert(norm(v) == 1, "norm");

    set(v,1,1);
    cr_assert(norm(v) == sqrt(2), "norm");

    set(v,2,1);
    cr_assert(norm(v) == sqrt(3), "norm");

    destroy(v);
}


