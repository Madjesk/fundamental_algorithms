#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(int *arr, int size) {
    for(int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void random_fill_arr(int *arr, int size) {
    for(int i=0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void fill_arr_closest_elems(int *arr_a, int *arr_b, int *arr_c, int len_a, int len_b, int len_c) {
    int min_len;
    if(len_a > len_b) {
        min_len = len_b;
    } else {
        min_len = len_a;
    }

    for(int i=0; i < len_c; i++) {
        if(min_len > i) {
            arr_c[i] = arr_a[i]+arr_b[i];
        }else {
            if(min_len == len_b) {
                arr_c[i] = arr_a[i] + arr_b[len_b-1];
            } else {
                arr_c[i] = arr_b[i] + arr_a[len_a-1];
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int len_a, len_b, len_c;

    printf("Enter length of array A: ");
    scanf("%d", &len_a);
    printf("Enter length of array B: ");
    scanf("%d", &len_b);
    if(len_a > len_b) {
        len_c = len_a;
    } else {
        len_c = len_b;
    }
    int arr_a[len_a];
    int arr_b[len_b];
    int arr_c[len_c];

    printf("Array A:\n");
    random_fill_arr(arr_a, len_a);
    print_arr(arr_a, len_a);

    printf("Array B:\n");
    random_fill_arr(arr_b, len_b);
    print_arr(arr_b, len_b);

    printf("Array C:\n");
    fill_arr_closest_elems(arr_a,arr_b,arr_c,len_a,len_b,len_c);
    print_arr(arr_c, len_c);
}