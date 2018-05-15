#include <criterion/criterion.h>
#include "../src/matrix.h"
#include "../src/vector.h"
#include "../src/complex.h"

TestSuite(complex_num);

Test(complex_num, cartesian)
{
    complex_num *z = cartesian(1,1);
    cr_assert(real_part(z) == 1);
    cr_assert(im_part(z) == 1);

    complex_free(z);
}

Test(complex_num, polar)
{
    complex_num *z = polar(1, 2);
    cr_assert(real_part(z) == cos(2));
    cr_assert(im_part(z) == sin(2));

    complex_free(z);
}

Test(complex_num, complex_add)
{
    complex_num *u = cartesian(3, 5);
    complex_num *v = cartesian(6 ,-4);

    complex_num *z = complex_add(u, v);

    cr_assert(real_part(z) == 9);
    cr_assert(im_part(z) == 1);

    complex_free(z);
    complex_free(u);
    complex_free(v);
}

Test(complex_num, complex_sub)
{
    complex_num *u = cartesian(3, 5);
    complex_num *v = cartesian(6 ,-4);

    complex_num *z = complex_sub(u, v);

    cr_assert(real_part(z) == -3);
    cr_assert(im_part(z) == 9);

    complex_free(z);
    complex_free(u);
    complex_free(v);

}


