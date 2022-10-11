#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define EPSILON 1e-7

double clone_pow(double number, int degree) {
    if(degree==0) {
        return 1;
    }

    if(degree > 0) {
        return number*clone_pow(number, degree-1);
    } else {
        return 1.0 / (number*clone_pow(number, (-degree)-1));
    }
}

double avg_geom(int count, ...) {
    double res=1.0;
    va_list numbers;
    va_start(numbers, count);

    for(int i=0; i< count; i++){
        res*= va_arg(numbers, double);
    }
    va_end(numbers);
    if((count % 2 == 0) && (res < EPSILON)) {
        return NAN;
    }
    return pow(res, 1.0/count);
}

int main() {
    double res=avg_geom(2, (double)1, (double)2);

    if(isnan(res)) {
        printf("NAN");
        return 0;
    } else {
        printf("Average geom= %lf\n", res);
    }

    printf("2^5= %lf\n", clone_pow(2,5));
    printf("2^(-5)= %lf\n", clone_pow(2, -5));
}