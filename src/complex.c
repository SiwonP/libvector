#include "complex.h"

complex_num *cartesian(double a, double b)
{
    complex_num *z = malloc(2*sizeof(double));
    z->x = a;
    z->y = b;

    return z;
}

complex_num *polar(double r, double theta)
{
    complex_num *z = malloc(2*sizeof(double));
    z->x = r*cos(theta);
    z->y = r*sin(theta);

    return z;
}

complex_num *cartesian_from_array(double a[2])
{
    complex_num *z = malloc(2*sizeof(double));
    z->x = a[0];
    z->y = a[1];

    return z;
}

complex_num *polar_from_array(double r[2])
{
    complex_num *z = malloc(2*sizeof(double));
    z->x = r[0]*cos(r[1]);
    z->y = r[0]*sin(r[1]);

    return z;
}

complex_num *cartesian_from_vector(vector *v)
{
    complex_num *z;
    if(size(v) == 2) {
        z = cartesian(get(v,0), get(v,1));
    }
    return z;
}

double real_part(complex_num *z)
{
    return z->x;
}

double im_part(complex_num *z)
{
    return z->y;
}

void print_complex(complex_num *z)
{
    printf("%lf + i %lf", real_part(z), im_part(z));
}

complex_num *complex_add(complex_num *u, complex_num *v)
{
    complex_num *z = cartesian(real_part(u) + real_part(v),
            im_part(u) + im_part(v));

    return z;
}

complex_num *complex_sub(complex_num *u, complex_num *v)
{
    complex_num *z = cartesian(real_part(u) - real_part(v),
            im_part(u) - im_part(v));

    return z;
}

complex_num *conjugate(complex_num *z)
{
    complex_num *z1 = cartesian(real_part(z), -im_part(z));
    return z1;
}

double modulus(complex_num *z)
{
    return sqrt(real_part(z)*real_part(z) + im_part(z)*im_part(z));
}
