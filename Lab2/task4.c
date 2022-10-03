#include <stdio.h>
#include <stdlib.h>
#include <stdarg>

double clone_pow() {

}

double avg_geom(int count, ...) {
    double res=1.0;
    va_list args;
    va_start(numbers, count);

    for(int i=0; i< count; i++){
        res*= v_arg(numbers, double)
    }
    va_end(numbers);
    //добавить проверки
    return pow(res, 1./count);
}

int main() {
    printf("Average geom %lf", avg_geom(2, (double)1, (double)2));
}