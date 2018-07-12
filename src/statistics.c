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

double v_auto_correlation(vector *u, int k)
{
    double mean, var = 0, autocorr = 0;
    int i;

    mean = v_mean(u);

    for (i = 0; i < v_size(u); ++u) {
        var += (v_get(u, i) - mean) * (v_get(u, i) - mean);
        autocorr += (v_get(u, i) - mean) * (v_get(u, (i + k) % v_size(u)) -mean);
    }
 
    autocorr = autocorr / var;

    return autocorr;
}

double v_correlation(vector *u, vector *v)
{
    double var1, var2, covar, corr = 0;
    int i;

    var1 = v_variance(u);
    var2 = v_variance(v);

    covar = v_covariance(u, v);

    corr = covar / (sqrt(var1) * sqrt(var2));

    return corr;
}

