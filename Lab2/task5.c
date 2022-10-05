#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void find_min_and_max_index(int *arr, int size,int *index_min, int *index_max) {
    for(int i=1; i < size; i++){
        if(arr[*index_max] < arr[i]) {
            *index_max = i;
        }
        if(arr[*index_min] > arr[i]) {
            *index_min = i;
        }
    }
}

void print_arr(int *arr, int size) {
    for(int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *x, int *y) {
    int tmp= *x;
    *x = *y;
    *y = tmp;
}

void fill_arr_numbers_from_range(int *arr, int size, int left, int right) {
    for(int i=0; i < size; i++) {
        arr[i] = rand() % (right-left+1) + left;
    }
}

int * create_unique_arr(int *arr, int size, int *new_size) {
    int count_founded_numbers[size], counter;

    for(int i =0; i< size; i++) {
        counter=0;
        for(int j =0; j< size; j++) {
            if(arr[i] == arr[j]){
                counter++;
            }
        }
        count_founded_numbers[i] = counter;
        if(count_founded_numbers[i] == 1) {
            *new_size+=1;
        }
    }

    int *new_arr= malloc((*new_size)*sizeof(int));
    int *p_new_arr = new_arr;
    for(int i=0; i<size; i++){
        if(count_founded_numbers[i]==1) {
            *p_new_arr = arr[i];
            p_new_arr++;
        }
    }
//    printf("new size:%d\n", *new_size);
    return new_arr;
}

int main(int argc, char * argv[]) {
    srand(time(NULL));
    int size, left, right;
    if(argc != 2) {
        printf("Wrong! Add flag: -swap or -unique\n");
        return 0;
    }
    printf("Input size of array: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("wrong size");
        return 0;
    }
    int arr[size];

    printf("Input range: ");
    scanf("%d %d", &left, &right);
    fill_arr_numbers_from_range(arr, size, left, right);
    printf("Array: \n");
    print_arr(arr, size);

    if(strcmp(argv[1], "-swap") == 0) {
        int index_max=0, index_min=0;
        find_min_and_max_index(arr, size, &index_max, &index_min);
        swap(&arr[index_max],&arr[index_min]);
        printf("Array with swapped elements: \n");
        print_arr(arr,size);
    }

    else if(strcmp(argv[1], "-unique") == 0) {
        int new_size=0;
        int * new_arr = create_unique_arr(arr,size, &new_size);
        if(new_size == 0) {
            printf("Can't find unique elems\n");
            return 0;
        }
        print_arr(new_arr, new_size);
    }
}