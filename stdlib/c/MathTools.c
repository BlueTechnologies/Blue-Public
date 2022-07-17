#include <math.h>

double arcsine(void* x) {
    double* x2 = (double*)x;
    double x3 = *x2;
    return asin(x3);
}

double arccos(void* x) {
    double* x2 = (double*)x;
    double x3 = *x2;
    return acos(x3);
}

double cosine(void* x) {
    double* x2 = (double*)x;
    double x3 = *x2;
    return cos(x3);
}

double power(void* x, void* y) {
    double* x2 = (double*)x;
    double x3 = *x2;
    double* y2 = (double*)y;
    double y3 = *y2;
    return pow(x3, y3);
}

double sine(void* x) {
    double* x2 = (double*)x;
    double x3 = *x2;
    return sin(x3);
}

double floorValue(void* x) {
    double* x2 = (double*)x;
    double x3 = *x2;
    return floor(x3);
}