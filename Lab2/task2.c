#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int count_len(char *str) {
    int len=0;
    while(*str) {
        str++;
        len++;
    }
    return len;
}

char *reverse(char *str, int len) {
    char *reversed_str = (char *)malloc((len + 1)*sizeof(char));
    reversed_str[len] = 0;

    for(int i=0; i < len; i++) {
        reversed_str[len-i-1] = str[i];
    }
    return reversed_str;
}

char to_upper_clone(char ch){
    if(ch > 96 && ch < 123) {
        return ch-32;
    } else {
        return ch;
    }
}

char *odd_index_up(char *str, int len) {
    char *result_str = (char *)malloc((len + 1)*sizeof(char));
    result_str[len] = 0;

    for(int i =0; i < len; i++){
        if(i % 2 == 0) {
            result_str[i] = toupper(str[i]);
        } else {
            result_str[i] = str[i];
        }
    }
    return result_str;
}

int is_letter(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        return 1;
    } else {
        return 0;
    }
}

int is_digit(char ch){
    if (ch >= '0' && ch <= '9') {
        return 1;
    } else {
        return 0;
    }
}

char *str_in_order_digits_letters_other(char *str, int len) {
    char *result_str = (char *)malloc((len+1)*sizeof(char));
    char *p_result_str = result_str;
    char *p_str = str;

    while(*p_str) {
        if(is_digit(*p_str)) {
            *p_result_str++ = *p_str;
        }
        p_str++;
    }
    p_str = str;

    while(*p_str) {
        if(is_letter(*p_str)) {
            *p_result_str++ = *p_str;
        }
        p_str++;
    }
    p_str = str;

    while(*p_str) {
        if(is_letter(*p_str) == 0 && is_digit(*p_str) == 0) {
            *p_result_str++ = *p_str;
        }
        p_str++;
    }
    *p_result_str = 0;
    return result_str;

}

char * contact_clone(char *str1, char *str2, int len1, int len2) {
    char * result_str = (char *)malloc((len1+1)*sizeof(char) + len2 * sizeof(char));
    char *p_result_str = result_str;

    while(*str1) {
        *p_result_str++ = *str1++;
    }
    while(*str2) {
        *p_result_str++ = *str2++;
    }

    *p_result_str = 0;
    return result_str;
}

int main(int argc, char * argv[]) {
    if(argc < 3 || argc > 4) {
        printf("Wrong args");
        return 0;
    }

    if(strcmp(argv[1], "-l") == 0) {
        printf("%d\n", count_len(argv[2]));
    }
    else if(strcmp(argv[1], "-r") == 0) {
        printf("%s\n", reverse(argv[2], count_len(argv[2])));
    }
    else if(strcmp(argv[1], "-u") == 0) {
        printf("%s\n", odd_index_up(argv[2], count_len(argv[2])));
    }
    else if(strcmp(argv[1], "-n") == 0) {
        printf("%s\n", str_in_order_digits_letters_other(argv[2], count_len(argv[2])));
    }
    else if(strcmp(argv[1], "-c") == 0) {
        printf("%s\n", contact_clone(argv[2], argv[3], count_len(argv[2]), count_len(argv[3])));
    }
}