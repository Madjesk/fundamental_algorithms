#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

enum {
    SUCCESSFULLY = -3,
    WRONG_INPUT = -4,
    SMALL_LEN = -5,
    MEMORY_ERROR = -6,
    WRONG_BASE = -7
};

int check_number(char *number, int base) {
    if(strcmp(number, "0") == 0) {
        return WRONG_INPUT;
    }
    while(*++number) {
        if(isdigit(*number) && (*number - '0' >= base) || isalpha(*number) && *number - 'A' + 10 >= base) {
            return WRONG_INPUT;
        }
    }
    return SUCCESSFULLY;
}

void print_error(int code) {
    switch(code) {
        case -4:
            printf("Wrong input\n");
            break;
        case -5:
            printf("Small len\n");
            break;
        case -6:
            printf("Memory error\n");
            break;
        case -7:
            printf("Wrong base\n");
            break;
        default:
            printf("Wrong error\n");
    }
}

int convert_to_10_system(char *str, int base) {
    if(strcmp(str, "0") == 0) {
        return 0;
    }
    if(base <= 1) {
        return WRONG_BASE;
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
        res = res * base + (isdigit(*p_str) ? (*p_str - '0') : (toupper(*p_str) - 'A' + 10));
    }
    return flag * res;
}

char *reverse(char *str, int len) {
    if (len < 1){
        return  NULL;
    }
    char *reversed_str = (char *)malloc((len + 1)*sizeof(char));
    if(reversed_str == NULL) {
        return NULL;
    }
    reversed_str[len] = 0;

    for(int i=0; i < len; i++) {
        reversed_str[len-i-1] = str[i];
    }
    return reversed_str;
}

char *convert_10_to_other_system(int number, int base, int size) {
    char* reversed_str = (char*)malloc(sizeof(char)*size+1);
    if(reversed_str == NULL) {
        return NULL;
    }
    int tmp, i = 0, minus = number > 0 ? 0 : 1;
    if(base <= 1) {
        return NULL;
    }

    while(abs(number)) {
        tmp = abs(number) % base;
        reversed_str[i] = tmp > 9 ? tmp - 10 + 'A' : tmp + '0';
        number = abs(number) / base;
        i++;
    }
    if(minus) {
        reversed_str[i] = '-';
        i++;
    }
    char* result_str = reverse(reversed_str, i);
    free(reversed_str);
    if(result_str != NULL) {
        return result_str;
    } else {
        return NULL;
    }
}

int get_str(char** buf, int* size){
    char c = getchar();
    char* tmp = NULL;
    int initial_size = 16, len = 0;
    *buf = (char*)malloc(initial_size*sizeof(char));
    if (!*buf){
        return MEMORY_ERROR;
    }
    while(c != EOF && c != '\n' && c != ' '){
        if (len == initial_size){
            initial_size*=2;
            tmp = (char*)realloc(*buf, initial_size);
            if (!tmp){
                free(*buf);
                return MEMORY_ERROR;
            }
            *buf = tmp;
        }
        (*buf)[len++] = c;
        c = getchar();
    }
    if (len == initial_size){
        initial_size++;
        tmp = (char*)realloc(*buf, initial_size);
        if (!tmp){
            free(*buf);
            return MEMORY_ERROR;
        }
        *buf = tmp;
    }
    (*buf)[len] = '\0';
    *size = len;
    return SUCCESSFULLY;
}

int main() {
    int base, max_num = 0, size = 0, result, max_size, is_enter = 0;
    char* buff = NULL;
    char* max_number = NULL;
    printf("Enter base: \n");
    scanf("%d", &base);
    if (base < 2 || base > 36) {
        return WRONG_INPUT;
        print_error(WRONG_INPUT);
    }

    printf("Enter numbers: \n");
    while(1) {
        if(get_str(&buff, &size) == MEMORY_ERROR) {
            print_error(MEMORY_ERROR);
            return MEMORY_ERROR;
        }

        if (!strcmp(buff, "Stop")) {
            break;
        } else {
            if(check_number(buff, base) == SUCCESSFULLY && strcmp(buff, "Stop") != 0) {
                result = convert_to_10_system(buff, base);
                if(abs(result) > abs(max_num)) {
                    is_enter = 1;
                    free(max_number);
                    max_number = NULL;
                    max_number = (char*)malloc(sizeof(char)*size);
                    if(max_number == NULL) {
                        return MEMORY_ERROR;
                    }
                    strcpy(max_number, buff);
                    max_size = size;
                    max_num = result;
                }
                size = 0;
                free(buff);
                buff = NULL;
            } else {
                print_error(WRONG_INPUT);
                return WRONG_INPUT;
            }
        }
    }
    if(is_enter) {
        printf("Max number modulo: %s\n", max_number);
        printf("Max number modulo in 9 number system: %s\n", convert_10_to_other_system(max_num, 9, max_size));
        printf("Max number modulo in 18 number system: %s\n", convert_10_to_other_system(max_num, 18, max_size));
        printf("Max number modulo in 27 number system: %s\n", convert_10_to_other_system(max_num, 27, max_size));
        printf("Max number modulo in 36 number system: %s\n", convert_10_to_other_system(max_num, 36, max_size));
    } else {
        printf("You did not enter numbers!\n");
        return WRONG_INPUT;
    }

}
