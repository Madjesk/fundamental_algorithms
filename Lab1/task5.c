#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {
    WRONG_INPUT = -1,
    FILE_NOT_FOUND = -2,
    SUCCESSFULLY = -3,
    WRONG_FLAG = -4
};

int write_files_from_file(const char * files) {
    FILE *file_with_files, *out, *in;
    char file_name[200],  c;
    out = fopen("out.txt", "w");
    file_with_files = fopen(files, "r");
    int flag = 1;
    if (!files){
        return FILE_NOT_FOUND;
    }

    while (!feof(file_with_files)){
        fscanf(file_with_files, "%s", file_name);
        in = fopen(file_name, "r");
        if (!in){
            return FILE_NOT_FOUND;
        }
        if(!flag) {
            fputc('\n', out);
        } else {
            flag = 0;
        }
        while ((c = fgetc(in)) != EOF) {
            fputc(c, out);
        }
        fclose(in);
    }

    fclose(out);
    fclose(file_with_files);
    return SUCCESSFULLY;
}

int write_files_from_stdin() {
    FILE *out, *in;
    char file_name[200], c;
    out = fopen("out.txt", "w");
    printf("Enter files: \n");
    scanf("%s", file_name);
    int flag = 1;
    while (!feof(stdin)) {
        in = fopen(file_name, "r");
        if (!in) {
            return FILE_NOT_FOUND;
        }

        if(!flag) {
            fputc('\n', out);
        } else {
            flag = 0;
        }
        while ((c = fgetc(in)) != EOF) {
            fputc(c, out);
        }
        fclose(in);
        scanf("%s", file_name);
}
    fclose(out);
    return SUCCESSFULLY;
}

int write_files_from_args(const char *argv[], int argc) {
    FILE *out, *in;
    char c;

    out = fopen("out.txt", "w");
    if(!out) {
        return FILE_NOT_FOUND;
    }
    for (int i = 2; i < argc; i++) {
        in = fopen(argv[i], "r");
        if (!in) {
            return FILE_NOT_FOUND;
        }

        while ((c = fgetc(in)) != EOF) {
            fputc(c, out);
        }
        fclose(in);
        if(i != argc-1) {
            fputc('\n', out);
        }


    }
    fclose(out);
    return SUCCESSFULLY;
}

int main(int argc, char const *argv[]) {
    if(argc == 1) {
        return WRONG_FLAG;
    }
    if(strcmp(argv[1], "-fi") == 0) { //список файлов в файле
        if (argc != 3){;
            return WRONG_INPUT;
        }
       write_files_from_file(argv[2]);
    }
    else if(strcmp(argv[1], "-cin") == 0) { //считать файлы из stdin
        write_files_from_stdin();
    }
    else if(strcmp(argv[1], "-arg") == 0) { //через аргв
        if (argc < 3) {
            return  WRONG_INPUT;
        }
        write_files_from_args(argv, argc);
    }
    else {
        return WRONG_FLAG;
    }
}