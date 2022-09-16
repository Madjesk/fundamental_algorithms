#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int cloneAtoi(char *s) {
    int result = 0;
    for(int i=0; s[i] != '\0'; i++) {
        result = result*10 + s[i] - '0';
    }
    return  result;
}

void printMultiples(int num) {
    int findMultiples = 0;
    for(int i=num; i <=100; i++) {
        if(i % num == 0) {
            printf("%d\n", i);
            findMultiples = 1;
        }
    }
    if (findMultiples == 0) {
        printf("Multiples not found\n");
    }
}

void isPrimeOrComposite(int num) {
    int isComposite = 0;
    for(int i=2;i<=sqrt(num);i++) {
        if(num%i == 0) {
            printf("Number is Сomposite\n");
            isComposite = 1;
            break;
        }
    }
    if(!isComposite) {
        if(num == 1) {
            printf("The number 1 has only one divisor and is neither prime nor composite\n");
        } else {
            printf("Number is Prime\n");
        }
    }
}

void printDigitsOfNumber(int num) {
    if(num != 0){
        printDigitsOfNumber(num/10);
        printf("%d ", num % 10);
    }
    printf("\n");
}

void printSumOfNumbers(int num) {
    unsigned long sum = 0;
    for(int i=1;i<=num;i++) {
        sum += i;
    }
    printf("%ld\n", sum);
}

void printNumberInDegreeN(int n) {
    unsigned long tmp = 1;
    for(int i = 1; i <= 10; i++) {
        printf("%d: ", i);
        for(int j=1; j <=n; j++) {
            tmp = tmp * i;
            printf("%ld ", tmp);
        }
        tmp = 1;
        printf("\n");
    }
}

unsigned long calculateFactorial(int num) {
    unsigned long tmp = num;
    if(tmp == 1) {
        return 1;
    } else {
        return tmp * calculateFactorial(tmp-1);
    }
}

int main(int argc, char * argv[]) {
    if(argc != 3) {
        printf("Wrong! Write: number -flag or /flag\n");
        return 0;
    }

    if(strcmp(argv[2], "-h") == 0 || strcmp(argv[2], "/h") == 0) {
        printMultiples(cloneAtoi(argv[1]));
    }
    else if(strcmp(argv[2], "-p") == 0 || strcmp(argv[2], "/p") == 0) {
        isPrimeOrComposite(cloneAtoi(argv[1]));
    }
    else if(strcmp(argv[2], "-s") == 0 || strcmp(argv[2], "/s") == 0) {
        printDigitsOfNumber(cloneAtoi(argv[1]));
    }
    else if(strcmp(argv[2], "-e") == 0 || strcmp(argv[2], "/e") == 0) {
        if(cloneAtoi(argv[1]) > 10) {
            printf("Your number is too big!\n");
        } else {
            printNumberInDegreeN(cloneAtoi(argv[1]));
        }
    }
    else if(strcmp(argv[2], "-a") == 0 || strcmp(argv[2], "/a") == 0) {
        printSumOfNumbers(cloneAtoi(argv[1]));
    }
    else if(strcmp(argv[2], "-f") == 0 || strcmp(argv[2], "/f") == 0) {
        printf("%ld", calculateFactorial(cloneAtoi(argv[1])));
    }
    else {
        printf("This flag does not exist");
        return 0;
    }
}