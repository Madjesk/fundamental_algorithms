#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define EPSILON 1e-7

float cloneAtof(char *s) {
    int negative = 1, i = 0, findDot = 0;
    float result= 0, otstup = 1;

    if (s[0] == '-') {
        i++;
        negative = -1;
    }

    for (; s[i] != '\0'; i++) {
        if (findDot) {
            otstup = otstup / 10;
            result = result + (s[i] - '0') * otstup;
        } else {
            if (s[i] == '.') {
                findDot = 1;
            } else {
                result = result * 10 + (s[i] - '0');
            }
        }
    }
    return result * negative;
}

void findRoots(float a, float b, float c){
    float d = b*b - 4*a*c;

    if (fabs(d) > EPSILON) {
        float x1 = ((-b)+(sqrt(d)))/(2*a);
        float x2 = ((-b)-(sqrt(d)))/(2*a);
        printf("%fx^2 + %fx + %f: x1=%f x2=%f\n", a,b,c,x1,x2);
    }
    else if(fabs(d) < EPSILON) {
        float x1 = (-b)/(2*a);
        printf("%fx^2 + %fx + %f: x=%f\n", a,b,c,x1);
    } else {
        printf("No roots\n");
    }
}

void solveEqation(float a, float b, float c) {
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

void isRightTriangle(float a, float b, float c) {
    float aSquared = a*a;
    float bSquared = b*b;
    float cSquared = c*c;

    if(((aSquared+bSquared) == cSquared) || ((aSquared+cSquared) == bSquared) || ((cSquared+bSquared) == aSquared)) {
        printf("Yes, %f,%f,%f can be sides of a right triangle\n", a,b,c);
    } else {
        printf("No, %f,%f,%f can't be sides of a right triangle\n", a,b,c);
    }
}

int isMultiple(float a, float b) {
    if(fabs(b) < EPSILON) {
        printf("you wrote 0\n!");
        return 0;
    }
    if(((int)a) % ((int)b) == 0) {
        return 1;
    } else {
        return 0;
    }
}

//file flag 1 2 3
int main(int argc, char * argv[]) {
    if(argc > 5 || argc < 4 ) {
        printf("Wrong input!\n");
        return 0;
    }
    if((strcmp(argv[1], "-q") == 0 || strcmp(argv[1], "/q") == 0) && (argc == 5)) {
        solveEqation(cloneAtof(argv[2]),cloneAtof(argv[3]), cloneAtof(argv[4]));
    }
    else if((strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "/m") == 0) && (argc ==4)) {
        if(isMultiple(cloneAtof(argv[2]),cloneAtof(argv[3]))) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    else if((strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "/t") == 0) && (argc ==5))  {
        if(cloneAtof(argv[2]) > 0 && cloneAtof(argv[3]) > 0 && cloneAtof(argv[4]) > 0) {
            isRightTriangle(cloneAtof(argv[2]),cloneAtof(argv[3]),cloneAtof(argv[4]));
        } else {
            printf("Enter the positive sides of the triangle\n");
        }
    }
    else {
        printf("This flag does not exist\n");
        return 0;
    }
}