#include <criterion/criterion.h>
#include "../src/vector.h"

TestSuite(MatrixBasics);

Test(MatrixBasics, m_zeros)
{
    matrix *m = m_zeros(2,2);
    m_print(m);
    m_free(m);
}
