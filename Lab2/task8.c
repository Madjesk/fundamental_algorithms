#include <stdio.h>
#include <math.h>

double func(double x) {
    return x * x - 5 * (sin(x));
}

double dihot_method(double (*func)(double), double begin, double end, int acc) {
    double res = 0.0;
    double epsilon = pow(10, -acc);

    do {
        res = (begin + end) / 2;
        if (func(res) * func(begin)<= epsilon) {
            end = res;
        }
        else {
            begin = res;
        }
    }
    while(fabs(begin-end) >= epsilon);

    return res;
}

int main() {
    printf("Answer: %lf\n", dihot_method(func, (double)1.1, (double)3.5, 10));
}