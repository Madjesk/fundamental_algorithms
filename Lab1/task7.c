#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct answer {
    int max;
    int min;
} answer;

answer findIndexMinOrMax(int *arr, int size) {
    int indexMax=0, indexMin =0;
    answer ans;
    for(int i=1; i < size; i++){
        if(arr[IndexMax] < arr[i]) {
            IndexMax = i;
        }
        if(arr[IndexMin] > arr[i]) {
            indexMin = i;
        }
    }
    ans.max = indexMax;
    ans.min = indexMin;
    return ans;
}

void printArr(int *arr, int size) {
    for(int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    answer ans;
    int size=0;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    srand(time(NULL));
    for(int i; i < size; i++) {
        arr[i] = rand();
        printf("%d ", arr[i]);
    }
    printf("\n");

    ans = findIndexMax(arr,size);

    printf("Max item is %d\n", ans.max);
    printf("Min item is %d\n", ans.min);

    arr[ans.max] = ans.min;
    arr[ans.min] = ans.max;

    printArr(arr, size);
}