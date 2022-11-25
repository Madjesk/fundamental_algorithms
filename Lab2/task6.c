#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/*
Реализуйте функцию с переменным числом аргументов, принимающую
в качестве входных параметров подстроку и пути к файлам.
Необходимо, чтобы эта функция производила поиск переданной
подстроки в этом списке файлов. Поиск подстроки в строке обеспечить
с использованием собственной реализации функции. Организуйте
наглядный вывод результатов.
*/

enum {
    FILE_NOT_FOUND = -1,
    SUBSTR_FOUND = -2,
    SUBSTR_NOT_FOUND = -3,
};

int find_str(char *str, char *substr) {
    int i, j, str_len, substr_len;
	str_len = strlen(str);
	substr_len = strlen(substr);
	int *prefix = (int*)malloc(substr_len * sizeof(int));

	//Calculate prefix-function
	prefix[0] = 0;
	for(i = 1, j = 0; i < substr_len; i++) {
		while(j > 0 && substr[j] != substr[i])
			j = prefix[j-1];
		if(substr[j] == substr[i])
			j++;
		prefix[i] = j;
	}

	//Search substr in str
	for(i = 0, j = 0; i < str_len; i++){
		while(j > 0 && substr[j] != str[i])
			j = prefix[j - 1];
		if(substr[j] == str[i]) {
            j++;
        }
		if(j == substr_len) {
		    free(prefix);
            return SUBSTR_FOUND;
        }
	}
    free(prefix);
	return SUBSTR_NOT_FOUND;
}


int check_files(char *substr, int num_of_files, ...) {
    FILE *fin;
    char *file_name;
    va_list p;
    va_start(p, num_of_files);
    int is_Found = 0, line =1 ;
    char str[BUFSIZ];
    while(num_of_files != 0) {
        line = 1;
        num_of_files--;
        file_name = va_arg(p, char*);
        fin = fopen(file_name, "r");
        if(fin == NULL) {
            return FILE_NOT_FOUND;
        }
        while(fgets(str, sizeof(str), fin) != NULL) {
            is_Found = find_str(str, substr);
            if(is_Found == SUBSTR_FOUND) {
                printf("Substr %s found in file: %s, in line=%d\n", substr, file_name, line);
            } else if(is_Found == SUBSTR_NOT_FOUND) {
                // printf("Substr %s NOT found in file: %s, in line=%d\n", substr, file_name, line);
            }
            line++;
        }
        fclose(fin);
    }
    va_end(p);
    return 1;
}

int main(int argc, char * argv[]) {
    check_files("klim", 2, "t1","t2");
}
