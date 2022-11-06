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

int is_alpha(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        return 1;
    } else {
        return 0;
    }
}

int is_digit(char ch){
    if (ch >= '0' && ch <= '9') { // return это
        return 1;
    } else {
        return 0;
    }
}

char to_upper(char ch){
    if(ch > 96 && ch < 123) {
        return ch-32;
    } else {
        return ch;
    }
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

int find_the_smallest_number_system(char *str) {
    char *str_ptr;
    int smallest_system = 0;
    if(*str == '-') {
        str_ptr = str;
    } else {
        str_ptr = str-1;
    }
    if(strcmp(str, "0") == 0 || strcmp(str, "1") ==0) {
        return 2;
    }
    while(*++str_ptr) {
        if(is_digit(*str_ptr) && (*str_ptr - '0' > smallest_system)) {
            smallest_system = *str_ptr - '0';
        }
        else if (is_alpha(*str_ptr) && (to_upper(*str_ptr) - 'A' + 10 > smallest_system)) {
            smallest_system = to_upper(*str_ptr) - 'A' + 10;
        }
    }
    return  1+smallest_system;
}

int convert_to_10_system(char *str, int base) {
    if(strcmp(str, "0") == 0) {
        return 0;
    }
    int flag = 1, res=0;
    char *p_str;
    if (*str == '-') {
        flag = -1;
        p_str = str;
     } else {
        p_str = str-1;
    }
    while (*++p_str) {
        res = res * base + (is_digit(*p_str) ? (*p_str - '0') : (to_upper(*p_str) - 'A' + 10));
    }
    return flag * res;
}

int main(int argc, char * argv[]) {
    FILE *fin, *fout;
    char number[50];
    int smallest_system, number_in_10_system;
    fin = fopen(argv[1], "r");
    fout = fopen("out.txt", "w");
    if (!fin){
        return FILE_NOT_FOUND;
    }

    while(!feof(fin)) {
        if(fscanf(fin, "%s", number) != EOF && is_number(number)) {
            smallest_system = find_the_smallest_number_system(number);
            number_in_10_system = convert_to_10_system(number, smallest_system);
            fprintf(fout, "Number: %s; The smallest system %d; In 10: %d\n", number, smallest_system, number_in_10_system);
        }
    }
    fclose(fin);
    fclose(fout);
}