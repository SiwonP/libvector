#include <stdio.h>
#include "matrix.h"
#include "vector.h"

int main()
{
    Vector *x = zero(2);
    printf("%d\n", x->n);
    printf("%lf\n", x->values[0]);
    return 1;
}
