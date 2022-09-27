#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *createDinamichString(int *k) {
    char* leksema = (char*)malloc((*k)*sizeof(char));
    if(leksema == NULL) {
        printf("Malloc error");
        return 0;
    }
    return leksema;
}

int isShortLine(char *ch) {
    if (*ch == '\n' || *ch == EOF) {
        printf("Error! You wrote short string, add words\n");
        return 1;
    } else {
        return 0;
    }
}

char *doRealloc(char **leksemaN, char **pLeksemaN, int *k) {
    *k*=2;
    char* p = (char*)realloc(*leksemaN, *k*sizeof(char));
    return p;
}

int main(int argc, char * argv[]) {
    FILE *fin;
    FILE *ftmp;
    char *leksema1, *leksema2, *leksema3;
    char *pLeksema1, *pLeksema2, *pLeksema3;
    char ch = 0;
    int k = 16;

    if (argc != 2) {
        printf("Wrong input!\n");
        return 0;
    }

    char * pref = "tmp_";
    int sumLen = strlen( argv[1] ) + 5;

    char store[sumLen];
    strcpy(store, pref);
    strcat(store, argv[1]);

    fin = fopen(argv[1], "r");
    ftmp = fopen(store, "w");

    if (fin == NULL || ftmp == NULL) {
        printf("Error, can't open file\n");
        return 0;
    }

    while (ch != EOF) {
        ch = 0;
        leksema1 = createDinamichString(&k);
        pLeksema1 = leksema1;
        while (ch != ' ') {
            ch = fgetc(fin);
            if(isShortLine(&ch)) {
                free(leksema1);
                fclose(fin);
                fclose(ftmp);
                remove(store);
                return 0;
            }

            if ((pLeksema1 - leksema1) == k) {
                char *newP = doRealloc(&leksema1, &pLeksema1, &k);
                if(newP != NULL) {
                    leksema1 = newP;
                    pLeksema1 = newP + (k / 2);
                } else {
                    printf("Realloc error");
                    free(leksema1);
                    fclose(fin);
                    fclose(ftmp);
                    remove(store);
                    return 0;
                }
            }

            if (ch != ' ') {
                *pLeksema1 = ch;
                pLeksema1++;
            } else {
                k = 16;
                *pLeksema1 = 0;
            }
        }

        ch = 0;
        leksema2 = createDinamichString(&k);
        pLeksema2 = leksema2;
        while (ch != ' ') {
            ch = fgetc(fin);
            if(isShortLine(&ch)) {
                free(leksema1);
                free(leksema2);
                fclose(fin);
                fclose(ftmp);
                remove(store);
                return 0;
            }

            if ((pLeksema2 - leksema2) == k) {
                char *newP = doRealloc(&leksema2, &pLeksema2, &k);
                if(newP != NULL) {
                    leksema2 = newP;
                    pLeksema2 = newP + (k / 2);
                } else {
                    printf("Realloc error");
                    free(leksema2);
                    fclose(fin);
                    fclose(ftmp);
                    return 0;
                }
            }

            if (ch != ' ') {
                *pLeksema2 = ch;
                pLeksema2++;
            } else {
                k = 16;
                *pLeksema2 = 0;
            }
        }

        ch = 0;
        leksema3 = createDinamichString(&k);
        pLeksema3 = leksema3;
        while (ch != '\n' && ch != EOF) {
            ch = fgetc(fin);
            if (ch == ' ') {
                free(leksema1);
                free(leksema2);
                free(leksema3);
                printf("Error! You wrote long string, delete words\n");
                fclose(fin);
                fclose(ftmp);
                remove(store);
                return 0;
            }

            if ((pLeksema3 - leksema3) == k) {
                char *newP = doRealloc(&leksema3, &pLeksema3, &k);
                if(newP != NULL) {
                    leksema3 = newP;
                    pLeksema3 = newP + (k / 2);
                } else {
                    printf("Realloc error");
                    free(leksema3);
                    fclose(fin);
                    fclose(ftmp);
                    remove(store);
                    return 0;
                }
            }

            if (ch != '\n') {
                if (ch == EOF) {
                    *pLeksema3 = 0;
                    fprintf(ftmp, "%s %s %s", leksema3, leksema1, leksema2);
                    free(leksema1);
                    free(leksema2);
                    free(leksema3);
                    remove(argv[1]);
                    rename(store, argv[1]);
                    fclose(fin);
                    fclose(ftmp);
                } else {
                    *pLeksema3 = ch;
                    pLeksema3++;
                }
            } else {
                k = 16;
                *pLeksema3 = 0;
                fprintf(ftmp, "%s %s %s\n", leksema3, leksema1, leksema2);
                free(leksema1);
                free(leksema2);
                free(leksema3);
            }
        }
    }
}