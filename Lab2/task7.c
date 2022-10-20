#include <stdio.h>
#include <stdarg.h>
#define EPSILON 1e-7

typedef struct position {
    double x;
    double y;
} position;

int is_convex(int n, ...) {
    int peaks = n / 2;
    position pos[peaks];

    if (n % 2 == 0 && n > 5) {
        double x1,y1,x2,y2, determinant;
        int sign, tmp_sign;
        va_list numbers;
        va_start(numbers, n);

        for (int i = 0; i < peaks; i++) {
            pos[i].x = va_arg(numbers, double);
            pos[i].y = va_arg(numbers, double);
        }
        va_end(numbers);

        for (int i = 0; i < peaks; i++) {
            x1 = pos[(i + 1) % peaks].x - pos[i % peaks].x;
            y1 = pos[(i + 1) % peaks].y - pos[i % peaks].x;

            x2 = pos[(i + 2) % peaks].x - pos[i % peaks].x;
            y2 = pos[(i + 2) % peaks].y - pos[i % peaks].x;

            determinant = x1 * y2 - x2 * y1;
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

    int is_convex_ans = is_convex(8 ,1.,1.,2.,2.,3.,3.,4.,4.);
    if(is_convex_ans == 1) {
        printf("Convex\n");
    }
    else if(is_convex_ans == 0) {
        printf("Not convex\n");
    }
    else {
        printf("Wrong convex\n");
    }
}