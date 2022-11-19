#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum {
    SUCCESSFULLY = -3,
    WRONG_INPUT = -4,
    SMALL_LEN = -52
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
        return  SMALL_LEN;
    }
    char *reversed_str = (char *)malloc((len + 1)*sizeof(char));
    if(reversed_str == NULL) {
        printf("Malloc error");
        return 0;
    }
    reversed_str[len] = 0;

    for(int i=0; i < len; i++) {
        reversed_str[len-i-1] = str[i];
    }
    return reversed_str;
}

char *convert_10_to_other_system(int number, int base) {
    char reversed_str[50];
    int tmp, i=0;
    while(number) {
        tmp = number % base;
        reversed_str[i] = tmp > 9 ? tmp - 10 + 'A' : tmp + '0';
        number /= base;
        i++;
    }
    char * result_str = reverse(reversed_str, i);
    return result_str;
}

int main() {
    int base, result = 0, max_num = 0;
    char number[50], max_number[50];
    char *ptr;

    printf("Enter base: \n");
    scanf("%d", &base);
    if (base < 2 || base > 36) {
        return WRONG_INPUT;
    }

    printf("Enter numbers: \n");
    while(strcmp(number, "Stop") != 0) {
        scanf("%s", number);
        if(strcmp(number, "Stop") != 0) {
            if(check_number(number, base) == -3) {
                result = abs(convert_to_10_system(number, base));
                if(result > max_num) {
                    max_num = result;
                    strcpy(max_number, number);
                }
            } else {
                return WRONG_INPUT;
            }
        }
    }

    printf("Max number modulo: %s\n", max_number);
    printf("Max number modulo in 9 number system: %s\n", convert_10_to_other_system(max_num, 9));
    printf("Max number modulo in 18 number system: %s\n", convert_10_to_other_system(max_num, 18));
    printf("Max number modulo in 27 number system: %s\n", convert_10_to_other_system(max_num, 27));
    printf("Max number modulo in 36 number system: %s\n", convert_10_to_other_system(max_num, 36));
}