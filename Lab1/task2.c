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

void isRightTriangle(int a, int b, int c) { //type?
    int aSquared = a*a;
    int bSquared = b*b;
    int cSquared = c*c;
    if(((aSquared+bSquared) == cSquared) || ((aSquared+cSquared) == bSquared) || ((cSquared+bSquared) == aSquared)) {
        printf("Yes, %d,%d,%d can be sides of a right triangle\n", a,b,c);
    } else {
        printf("No, %d,%d,%d can't be sides of a right triangle\n", a,b,c);
    }
}

void isMultiple(float a, float b) { //type?
    if (((int)a) % ((int)b) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}


//file flag 1 2 3
int main(int argc, char * argv[]) {
    if(argc > 5 || argc <4 ){
        printf("Wrong input!\n");
        return 0;
    }
    printf("%d", cloneAtoi(argv[2]));
    if((strcmp(argv[1], "-q") == 0 || strcmp(argv[1], "/q") == 0) && (argc == 5)) {
//        solveEquation();
    }
    else if((strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "/m") == 0) && (argc ==4)) {
        isMultiple(cloneAtoi(argv[2]),cloneAtoi(argv[3]));
    }
    else if((strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "/t") == 0) && (argc ==5))  {
        isRightTriangle(cloneAtoi(argv[2]),cloneAtoi(argv[3]),cloneAtoi(argv[4]));
    }
    else {
        printf("This flag does not exist");
        return 0;
    }
}