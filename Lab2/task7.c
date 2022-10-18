#include <stdio.h>
#include <stdarg.h>
#define EPSILON 1e-7

typedef struct position {
    double x;
    double y;
} position;

int is_convex(int n, ...) {
    int step = n / 2;
    position pos[step];

    if (n % 2 == 0 && n > 5) {
        va_list numbers;
        va_start(numbers, n);
        for (int i = 0; i < step; i++) {
            pos[i].x = va_arg(numbers, double);
            pos[i].y = va_arg(numbers, double);
        }
        va_end(numbers);

        int sign, tmp_sign;
        for (int i = 0; i < step; i++) {
            int x1 = pos[(i + 1) % step].x - pos[i % step].x;
            int y1 = pos[(i + 1) % step].y - pos[i % step].x;

            int x2 = pos[(i + 2) % step].x - pos[i % step].x;
            int y2 = pos[(i + 2) % step].y - pos[i % step].x;

            int determinant = x1 * y2 - x2 * y1;
            tmp_sign = determinant > EPSILON ? 1 : 0;

            if (i==0)
                sign = tmp_sign;
            else if (sign != tmp_sign)
                return 0;
        }
        return 1;
    }
    return -1;
}

double find_value_polinom(double point, int degree, ...) {
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
    printf("The result: %lf\n", find_value_polinom(2.,3,1.,2.,3.));

    if(is_convex(2,1.,2.) == 1) {
        printf("Convex\n");
    }
    else if(is_convex(2,1.,2.) == 0) {
        printf("Not convex\n");
    }
    else {
        printf("Wrong convex\n");
    }
}
