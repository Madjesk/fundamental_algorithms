#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMax(int *arr, int size) {
    int maxItem = arr[0], index=0;
    for(int i=0; i < size; i++){
        if(arr[i] > maxItem) {
            maxItem = arr[i];
            index = i;
        }
    }
    return index;
}

int findMin(int *arr, int size) {
    int minItem = arr[0], index=0;
    for(int i=0; i < size; i++){
        if(arr[i] < minItem) {
            minItem = arr[i];
            index = i;
        }
    }
    return index;
}

void printArr(int *arr, int size) {
    for(int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
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

    int indexMaxItem = findMax(arr,size);
    int indexMinItem = findMin(arr,size);
    int maxItem = arr[indexMaxItem];
    int minItem = arr[indexMinItem];
    printf("Max item is %d\n", maxItem);
    printf("Min item is %d\n", minItem);

    arr[indexMaxItem] = minItem;
    arr[indexMinItem] = maxItem;

    printArr(arr, size);
}