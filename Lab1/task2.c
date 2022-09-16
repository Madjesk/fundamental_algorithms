#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int cloneAtoi(char *s) {
    int result = 0, flag = 1,i=0;
    if(s[0] == '-') {
        i++;
        flag = -1;
    }

    for(i; s[i] != '\0'; i++) {
        result = result*10 + s[i] - '0';
    }
    return result*flag;

}

void findRoots(double a, double b, double c){
    double d = b*b - 4*a*c;
    if (d > 0) {
        double x1 = ((-b)+(sqrt(d)))/(2*a);
        double x2 = ((-b)-(sqrt(d)))/(2*a);
        printf("%fx^2 + %fx + %f: x1=%f x2=%f\n", a,b,c,x1,x2);
    }
    else if(d == 0) {
        double x1 = (-b)/(2*a);
        printf("%fx^2 + %fx + %f: x=%f\n", a,b,c,x1);
    } else {
        printf("No roots");
    }
}

void solveEqation(int n1, int n2, int n3) {
    double a = n1;
    double b = n2;
    double c = n3;
    double arr[3] = {a,b,c};
    int counter = 1;

    for (int i = 0; i <= 2; i++) {
        for (int j =0; j <= 2; j++) {
            for (int k = 0; k <= 2; k++) {
                if(i!=j && i!=k && j!=k){
                    printf("%d) ", counter);
                    counter++;
                    findRoots(arr[i],arr[j],arr[k]);
                }
            }
        }
    }

}

void isRightTriangle(int a, int b, int c) {
    unsigned long aSquared = a*a;
    unsigned long bSquared = b*b;
    unsigned long cSquared = c*c;

    if(((aSquared+bSquared) == cSquared) || ((aSquared+cSquared) == bSquared) || ((cSquared+bSquared) == aSquared)) {
        printf("Yes, %d,%d,%d can be sides of a right triangle\n", a,b,c);
    } else {
        printf("No, %d,%d,%d can't be sides of a right triangle\n", a,b,c);
    }
}

void isMultiple(int a, int b) {
    if((a % b) == 0) {
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

    if((strcmp(argv[1], "-q") == 0 || strcmp(argv[1], "/q") == 0) && (argc == 5)) {
        solveEqation(cloneAtoi(argv[2]),cloneAtoi(argv[3]), cloneAtoi(argv[4]));
    }
    else if((strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "/m") == 0) && (argc ==4)) {
        isMultiple(cloneAtoi(argv[2]),cloneAtoi(argv[3]));
    }
    else if((strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "/t") == 0) && (argc ==5))  {
        if(cloneAtoi(argv[2]) > 0 && cloneAtoi(argv[3]) > 0 && cloneAtoi(argv[4]) > 0) {
            isRightTriangle(cloneAtoi(argv[2]),cloneAtoi(argv[3]),cloneAtoi(argv[4]));
        } else {
            printf("Enter the positive sides of the triangle\n");
        }
    }
    else {
        printf("This flag does not exist\n");
        return 0;
    }
}