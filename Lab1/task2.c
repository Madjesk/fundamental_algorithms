#include "stdio.h"
#include "string.h"

int cloneAtoi(char s[]) {
    int n = 0;
    for (int i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

//void solveEquation() {
//
//}
//
//void isMultiple() {
//
//}

void isRightTriangle(int a, int b, int c) {
    int aSquared = a*a;
    int bSquared = b*b;
    int cSquared = c*c;
    if(((aSquared+bSquared) == cSquared) || ((aSquared+cSquared) == bSquared) || ((cSquared+bSquared) == aSquared)) {
        printf("Yes, %d,%d,%d can be sides of a right triangle", a,b,c);
    } else {
        printf("No, %d,%d,%d can't be sides of a right triangle", a,b,c);
    }
}

//file flag 1 2 3
int main(int argc, char * argv[]) {
    if(argc > 5 || argc <4 ){
        printf("Wrong input");
        //выход
    }
    if((strcmp(argv[1], "-q") == 0 || strcmp(argv[1], "/q") == 0) && (argc == 5)) {
//        solveEquation();
    }
    else if((strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "/m") == 0) && (argc ==4)) {
//        isMultiple();
    }
    else if((strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "/t") == 0) && (argc ==5))  {
        isRightTriangle(cloneAtoi(argv[2]),cloneAtoi(argv[3]),cloneAtoi(argv[4]));
    }
}