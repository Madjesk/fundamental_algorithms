#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

enum {
  WRONG_RANGE = -1,
  WRONG_SIZE = -2,
  SUCCESSFULLY = -3
};

typedef struct stats {
    int max_index;
    int min_index;
    int max_item;
    int min_item;
    int size
} stats;

stats findIndexMinAndMax(int *arr, int size) {
    int indexMax=0, indexMin =0, size = 1;
    answer ans;
    for(int i=1; i < size; i++){
        size++;
        if(arr[indexMax] < arr[i]) {
            index_max = i;
            max_item = arr[i]
        }
        if(arr[IndexMin] > arr[i]) {
            index_min = i;
            min_item = arr[i]
        }
    }
    ans.max = indexMax;
    ans.min = indexMin;
    return ans;
}

int count_len(int *arr) {
    int len=0;
    while(*arr++) {
        len++;
    }
    return len;
}

int print_arr(int *arr, int size) {
    if(size <= 0) {
      return WRONG_SIZE;
    }
    for(int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return SUCCESSFULLY;
}

int print_arr_range(int *arr, int left, int right) {
  if(left > 0 && right > 0 && (left < right)) {
    for(; left<=right; left++ ){
      printf("%d", arr[left-1]);
    }
    printf("\n");
    return SUCCESSFULLY;
  } else {
    return WRONG_RANGE;
  }
}

void shuffle_arr(int* arr, int n) {
    for (int i = n - 1; i >= 1; i--)  {
        int j = rand() % (i + 1);
        int tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }
}

void fill_arr_numbers_from_range(int *arr, int size, int left, int right) {
    for(int i=0; i < size; i++) {
        arr[i] = rand() % (right-left+1) + left;
    }
}

int comp_lower_to_up(const void *i, const void *j) {
  return *(int *)i - *(int *)j;
}

int comp_up_to_lower(const void *i, const void *j) {
  return -(*(int *)i - *(int *)j);
}

int is_number(char *s) {
    if(*s=='-') {
        s++;
    }
    while(*s) {
        if(isdigit(*s) || isalpha(*s)) {
            s++;
        } else {
            return 0;
        }
    }
    return 1;
}
//
//void print_arr_range(int *arr, int left, int right) {
//
//}
//
//void arr_stat() {
//
//}
//
//void shuffle_arr() {
//
//}
//
//void sort() {
//
//}
//
void contact_arrs(int *arr_A, int *arr_B) {
//    len_total = count_len(arr_A) + count_len(arr_B);
//    int *
}
//
//void load_arr_from_file(){
//
//}
//
//void save_arr_in_file() {
//
//}

int main(int argc, char * argv[]) {
    srand(time(NULL));
    FILE *fin;
    int arr[50], k =0;
    int arr_A[8] = {7,4,9,2,1,23,12,2};
    shuffle_arr(arr_A, 8);
    print_arr(arr_A, 8);
   // fin = fopen(argv[2], "r");
   // if (!fin){
   //     return FILE_NOT_FOUND;
   // }

   // if (strcmp(argv[1], "Load") == 0) {
   //
   // }
   // else if(strcmp(argv[1], "Save") == 0) {
   //
   // }
   // else if(strcmp(argv[1], "Rand") == 0) {
   //     // fill_arr_numbers_from_range();
   // }
   // else if(strcmp(argv[1], "Concat") == 0) {
   //
   // }
   // else if(strcmp(argv[1], "Free") == 0) {
   //
   // }
   // else if(strcmp(argv[1], "Remove") == 0) {
   //
   // }
   // else if(strcmp(argv[1], "Copy") == 0) {
   //
   // }
   // else if(strcmp(argv[1], "Shuffle") == 0) {
   //
   // }
   // else if(strcmp(argv[1], "Sort") == 0) {
     // qsort(arr_A, 8, sizeof(int), comp_lower_to_up);
     // qsort(arr_A, 8, sizeof(int), comp_up_to_lower);

   // }
   // else if(strcmp(argv[1], "Stats") == 0) {
   //
   // }
   // else if(strcmp(argv[1], "Print") == 0) {
      // print_arr();
   // }
   // else if(strcmp(argv[1], "Print") == 0) {
      // print_arr_range(arr_A, 1,4);
   // }

}
