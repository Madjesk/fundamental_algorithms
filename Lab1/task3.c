#include <stdio.h>
#include <string.h>
#include <ctype.h>


void deleteAllNumbers(FILE* fin, FILE* fout) {
    char el;
    while(!feof(fin)){
        el = fgetc((fin));
        if((el < '0' || el > '9') && (el != EOF)) {
            fprintf(fout,"%c",el);
        } else {
            fputc(' ', fout);
        }
    }
}

void countLettersInLine(FILE* fin, FILE* fout) {
    int counter = 0;
    char el;
    while (!feof(fin)) {
        el = fgetc((fin));
        if (el == EOF || el == '\n') {
            fprintf(fout, "Sum of letters: %d\n", counter);
            counter = 0;
        }
        else if ((el >= 'a' && el <= 'z') || (el >= 'A' && el <= 'Z')) {
            counter += 1;
        }
    }
}

int isSpecialElement(char el) {
    if((el >= 'A' && el <= 'Z') || (el >= 'a' && el <= 'z') || (el > '0' && el < '9') || (el == ' ')) {
        return 0;
    } else {
        return 1;
    }
}

void countSpecialElements(FILE* fin, FILE* fout) {
    int counter = 0;
    char el;
    while (!feof(fin)) {
        el = fgetc((fin));
        if ((el == EOF) || (el == '\n')) {
            fprintf(fout, "Sum of special elements: %d\n", counter);
            counter = 0;
        }
        else if (isSpecialElement(el)) {
            counter += 1;
        }
    }

}

void lettersToAski(FILE* fin, FILE* fout) {
      char el;
      while((el=fgetc(fin)) != EOF) {
            if (el >= '0' && el <= '9') {
                fputc(el, fout);
            } else {
                fprintf(fout, "%d", (int)el);
            }
        }
    }

void changeLeksemsUsingRules(FILE* fin, FILE* fout) {
    int counterLeksem =1, inLeksem =1;
    char el;

    while (!feof(fin)) {
        el = fgetc(fin);
        if(el == '\n' || el == '\t' || el == ' ') {
            if(inLeksem) {
                counterLeksem+=1;
                inLeksem = 0 ;
            }
            fputc(el,fout);
        } else if(el != EOF) {
            inLeksem = 1;
            if((counterLeksem % 2 == 0) && isalpha(el)) {
                fputc(tolower(el), fout);
            }
            if((counterLeksem % 5 == 0) && isalpha(el)) {
                fprintf(fout, "%d", (int)el);
            }
            if ((counterLeksem % 2 != 0) && (counterLeksem % 5 != 0)) {
                putc(el,fout);
            }
        }

    }
}

int main(int argc, char * argv[]) {
    FILE *fin;
    FILE *fout;

    if(argc > 4 || argc < 3 ) {
        printf("Wrong input!\n");
        return 0;
    }

    if((argv[1][0] == '-' || argv[1][0] == '/') && argv[1][1] == 'n') {
        fin = fopen(argv[2], "r");
        if(fin == NULL) {
            printf("Wrong fin");
            return 0;
        }

        fout = fopen(argv[3], "w");
        if(fout == NULL ) {
            printf("Wrong fout");
            return 0;
        }
    }
    else if((argv[1][0] == '-' || argv[1][0] == '/') && strlen(argv[1]) == 2) {
        if(argc != 3) {
            printf("Wrong input!\n");
            return 0;
        }

        fin = fopen(argv[2], "r");
        if(fin == NULL) {
            printf("Wrong fin");
            return 0;
        }

        char * pref = "out_";
        int sumLen = strlen( argv[2] ) + 5;

        char store[sumLen];
        strcpy(store, pref);
        strcat(store, argv[2]);

        fout = fopen(store, "w");
        if(fout == NULL) {
            printf("Wrong fin");
            return 0;
        }


    } else {
        printf("Wrong flag!\n");
        return 0;
    }

    if(strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "/d") == 0 || strcmp(argv[1], "/nd") == 0 || strcmp(argv[1], "-nd") == 0) {
        deleteAllNumbers(fin, fout);
    }
    else if(strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "/i") == 0 || strcmp(argv[1], "/ni") == 0 || strcmp(argv[1], "-ni") == 0) {
        countLettersInLine(fin, fout);
    }
    else if(strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "/s") == 0 || strcmp(argv[1], "/ns") == 0 || strcmp(argv[1], "-ns") == 0) {
        countSpecialElements(fin, fout);
    }
    else if(strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "/a") == 0 || strcmp(argv[1], "/na") == 0 || strcmp(argv[1], "-na") == 0) {
        lettersToAski(fin, fout);
    }
    else if(strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "/f") == 0 || strcmp(argv[1], "/nf") == 0 || strcmp(argv[1], "-nf") == 0) {
        changeLeksemsUsingRules(fin, fout);
    }
    fclose(fin);
    fclose(fout);
}