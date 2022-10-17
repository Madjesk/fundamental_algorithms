#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double polinom(double point, int degree, ...) {
    double result = 0.0;
    va_list numbers;
    va_start(numbers, degree);

    for(int i =0; i < degree+1; i++) {
        result = result * point + va_arg(numbers,double);
    }
    va_end(numbers);
    return result;
}

int main() {
    printf("The result: %lf", polinom(2.,3,1.,2.,3.));
}
