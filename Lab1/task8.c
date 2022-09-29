#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 128

float cloneAtoi(char *s) {
    int negative = 1, i = 0;
    float result= 0;
    if (s[0] == '-') {
        i++;
        negative = -1;
    }

    for (; s[i] != '\0'; i++) {
        result = result * 10 + (s[i] - '0');
    }

    return result * negative;
}

int isNum(char *s) {
    if(*s=='-') {
        s++;
    }
    while(*s) {
        if(isdigit(*s)) {
            s++;
        } else {
            return 0;
        }
    }
    return 1;
}

void printArray(int *arr, int size) {
    for(int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int *getArrWithOddPositionNumbers(int *oldArr, int size, int *newArr) {
    for(int i=0, m=1; i < size; i++, m+=2) {
        newArr[i]=oldArr[m];
    }
    return newArr;
}

int countEvenNumbers(int *arr, int size) {
    int counter = 0;
    for(int i=0; i < size; i++) {
        if((arr[i] % 2 ==0) && (arr[i] >= 0)) {
            counter+=1;
        }
    }
    return counter;
}

int sumOfPreviousNumbers(int *arr, int size, int index) {
    int sum=0;
    for(int i=0; i< index; i++) {
        sum+=arr[i];
    }
    return sum;
}

int *getArrWithEvenNumbers(int *oldArr, int size, int *newArr) {
    for(int i=0, m=0; i <= size; i++) {
        if(oldArr[i]% 2 ==0 && oldArr[i] >= 0) {
            newArr[m]=oldArr[i];
            m++;
        }
    }
    return newArr;
}

int findTheMostDistantNum(int *arr, int size, int index) {
    int answerIndex = 0;
    for(int i =0; i < size; i++) {
        if(abs(arr[index]-arr[answerIndex]) < abs(arr[index] - arr[i])) {
            answerIndex= i;
        }
    }
    return arr[answerIndex];
}

int sumOfLowerNumbers(int *arr, int size, int index) {
    int sum = 0, initialNum = arr[index];
    for(int i =0; i < size; i++) {
        if(arr[i] < initialNum) {
            sum+=arr[i];
        }
    }
    return sum;
}

int main(int argc, char * argv[]) {
    FILE *fin;
    int arr[MAX_SIZE];
    char number[11];
    int counterElems = 0, i= 0, counterChet=0, initialNum=0;

    if (argc != 3) {
        printf("Wrong input!\n");
        return 0;
    }

    fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("Error, can't open file\n");
        return 0;
    }

    while(!feof(fin)) {
        if((counterElems<129) && fscanf(fin, "%s", number) != EOF && isNum(number)) {
            arr[counterElems] = cloneAtoi(number);
            counterElems+=1;
        }
    }

//    while (fscanf(fin, "%d", &arr[counterElems]) != EOF) {
//        counterElems++;
//    }

    if(counterElems == 0) {
        printf("Add numbers in file");
        return 0;
    }

    printf("Array:\n");
    printArray(arr, counterElems);

    if(strcmp(argv[2], "-a") == 0) {
        int newSize = counterElems/2;
        int newArr[counterElems/2];

        printf("Result: \n");
        printArray(getArrWithOddPositionNumbers(arr, newSize, newArr), newSize);
    }
    else if(strcmp(argv[2], "-b") == 0) {
        int counterEven = countEvenNumbers(arr, counterElems);
        int newArr[counterEven];
        printf("кол-во чет %d\n", counterEven);
        printf("Result: \n");
        printArray(getArrWithEvenNumbers(arr,counterElems, newArr), counterEven);
    }
    else if(strcmp(argv[2], "-c") == 0) {
        int index=0;
        printf("Enter index : ");
        scanf("%d", &initialNum);

        if (index > counterElems-1 || index < 0) {
            printf("Wrong index\n");
            return 0;
        }
        printf("Answer: %d\n", findTheMostDistantNum(arr,counterElems, initialNum));
    }
    else if(strcmp(argv[2], "-d") == 0) {
        int index=0;
        printf("Enter index : ");
        scanf("%d", &initialNum);

        if (index > counterElems-1 || index < 0) {
            printf("Wrong index\n");
            return 0;
        }
        printf("Sum of previous numbers: %d\n", sumOfPreviousNumbers(arr,counterElems, initialNum));
    }
    else if(strcmp(argv[2], "-e") == 0) {
        int index=0;
        printf("Enter index : ");
        scanf("%d", &initialNum);

        if (index > counterElems-1 || index < 0) {
            printf("Wrong index\n");
            return 0;
        }
        printf("Sum of lower numbers: %d\n", sumOfLowerNumbers(arr,counterElems, initialNum));
    }
    fclose(fin);
}