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
    FOUND = -2
};

// int find_str(char *str, char *substr) {
//
// }
int KMP(char *str,char *substr){
    int i,j,n,m;
    n = strlen(str);
    m = strlen(substr);
    if(m == 0 || *substr == '\0')
        return -5;
    if(n < m || n == 0)
        return -5;
    int *proc = (int*)malloc(m*sizeof(int));
    //Prefix-function evaluation
    *(proc) = 0;
    for( i = 1,j = 0;i < m;i++){
        while(j > 0 && *(substr + j) != *(substr + i))
            j = *(proc + j - 1);
        if(*(substr + j) == *(substr + i))
            j++;
        *(proc + i) = j;
    }
    //Searching for substr in str
    for(i = 0,j = 0;i < n;i++){
        while(j > 0 && *(substr + j) != *(str + i))
            j=*(proc + j - 1);
        if(*(substr + j)==*(str + i))
            j++;
        if(j == m){
            free(proc);
            return FOUND;
            //position is i-j+1
        }
    }
    free(proc);
    return -100;
}

int check_files(char *substr, int num_of_files, ...) {
    FILE *fin;
    char *file_name;
    va_list p;
    va_start(p, num_of_files);
    int isFound = 0, line =1 ;
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
            isFound = KMP(str, substr);
            if(isFound == FOUND) {
                printf("Substr %s found in file: %s, line=%d\n", substr, file_name, line);
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
