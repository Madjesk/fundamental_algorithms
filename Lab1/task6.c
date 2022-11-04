#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

enum {
    WRONG_INPUT = -1,
    FILE_NOT_FOUND = -2,
    SUCCESSFULLY = -3,
    WRONG_FLAG = -4
};

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

int find_the_smallest_number_system(char *str) {
    char *str_ptr;
    int smallest_system = 0;
    if(*str == '-') {
        str_ptr = str++;
    } else {
        str_ptr = str;
    }

    while(*str_ptr++) {
        if(isdigit(*str_ptr) && (*str_ptr - '0' > smallest_system)) {
            smallest_system = *str_ptr - '0';
        }
        else if (isalpha(*str_ptr) && (toupper(*str_ptr) - 'A' + 10 > smallest_system)) {
            smallest_system = toupper(*str_ptr) - 'A' + 10;
        }
    }
    return  1+smallest_system;
}

int main(int argc, char * argv[]) {
    FILE *fin, *fout;
    char number[15];
    fin = fopen(argv[1], "r");
    if (!fin){
        return FILE_NOT_FOUND;
    }
    while(!feof(fin)) {
        if(fscanf(fin, "%s", number) != EOF && is_number(number)) {
            printf("%s %d \n", number, find_the_smallest_number_system(number));
        }
    }
}