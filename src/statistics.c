#include "statistics.h"

double v_mean(vector *v)
{
    double mean = 0;
    int i;
    for (i = 0; i < v_size(v); ++i) {
        mean += v_get(v, i);
    }
    mean = mean/v_size(v);
    return mean;
}

double v_variance(vector *v)
{
    return v_covariance(v, v);
}

double v_covariance(vector *u, vector *v)
{
    double mean1, mean2, covar = 0;
    int i;
    mean1 = v_mean(u);
    mean2 = v_mean(v);

    //TODO: handle error in case both vector are not of the same dimension

    for (i = 0; i < v_size(u); ++i) {
        covar += (v_get(u, i) - mean1)*(v_get(v, i) - mean2);
    }

    covar = covar / (v_size(u) - 1);

    return covar;
}

