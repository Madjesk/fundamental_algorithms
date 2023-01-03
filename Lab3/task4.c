#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

enum {
    WRONG_ARGS = -1,
    SUCCESSFULLY = -2,
    MEMORY_PROBLEM = -3,
    CANT_OPEN_FILE = -4,
};

typedef struct message {
    int id;
    char *text;
    size_t len;
    size_t size;
} message;

int create_csv_filename(char** file_name) {
    char symbol;
    int is_num;
    int len = rand() % 15 + 1;
    len += 5;

    *file_name = (char*)malloc(sizeof(char)*len);
    if(!*file_name) {
        return MEMORY_PROBLEM;
    }

    for(int i = 0; i < len - 5; i++) {
        is_num = rand() % 2;
        if(is_num) {
            symbol = '0' + rand() % 10;
            (*file_name)[i] = symbol;
        } else {
            symbol = 'A' + rand() % 26;
            (*file_name)[i] = symbol;
        }
    }

    strcat(*file_name, ".csv");
    return SUCCESSFULLY;
}

int message_initialization(message** item) {
    *item = (message*)malloc(sizeof(message));
    if(!*item) {
        return MEMORY_PROBLEM;
    }
    (*item)->id=1;
    (*item)->size = 2;
    (*item)->text = (char*)malloc((*item)->size * sizeof(char));
    if(!(*item)->text){
        return MEMORY_PROBLEM;
    }
    (*item)->len = 0;

    return SUCCESSFULLY;
}

int reset_message(message** item) {
    (*item)->id++;
    (*item)->len = 0;
    (*item)->size = 2;
    free((*item)->text);
    (*item)->text = (char*)malloc((*item)->size * sizeof(char));
    if((*item)->text == NULL){
        return MEMORY_PROBLEM;
    }
    return SUCCESSFULLY;
}

int realloc_text(message** item) {
    char *new_ptr = (char*)realloc((*item)->text, (*item)->size);
    if(new_ptr != NULL) {
        (*item)->text = new_ptr;
    } else {
        free(new_ptr);
        return MEMORY_PROBLEM;
    }
    (*item)->size*=2;
    if((*item)->text == NULL) {
        return MEMORY_PROBLEM;
    }
    return SUCCESSFULLY;
}

int fill_the_file(FILE* file, message** item, int* size) {
    char ch;
    int read = 1;
    while(read) {
        ch = getchar();
        if(ch != '\n') {
            if((*item)->size == (*item)->len) {
                if (realloc_text(item) == MEMORY_PROBLEM) {
                    free((*item)-> text);
                    free((*item));
                    return MEMORY_PROBLEM;
                }
            }
            (*item)->text[(*item)->len++] = ch;
        } else {
            if((*item)->size == (*item)->len) {
                if (realloc_text(item) == MEMORY_PROBLEM) {
                    free((*item)-> text);
                    free((*item));
                    return MEMORY_PROBLEM;
                }
            }
            (*item)->text[(*item)->len] = '\0';
            if(strcmp((*item)->text, "stop") == 0) {
                *size = (*item)->id;
                free((*item)-> text);
                free((*item));
                break;
            }
            fprintf(file, "%d %s\n", (*item)->id, (*item)->text);
            if(reset_message(item) == MEMORY_PROBLEM) {
                free((*item)->text);
                free((*item));
                return MEMORY_PROBLEM;
            }
        }
    }
    return SUCCESSFULLY;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    FILE* file;
    char *file_name = NULL;
    message *item;
    int counter_of_items=0;
    if(argc != 1) {
        printf("Wrong args\n");
        return WRONG_ARGS;
    }

    if(create_csv_filename(&file_name) == MEMORY_PROBLEM) {
        printf("Faild to create csv file, no memory\n");
        return MEMORY_PROBLEM;
    }

    if(message_initialization(&item) == SUCCESSFULLY) {
        file = fopen(file_name, "w");
        if(file == NULL) {
            return CANT_OPEN_FILE;
        }
        printf("Enter messages, enter stop if you don't want to enter messages anymore\n");
        if (fill_the_file(file, &item, &counter_of_items) == MEMORY_PROBLEM) {
            printf("MEMORY_PROBLEM\n");
            return MEMORY_PROBLEM;
        }
    } else {
        printf("Memory problem\n");
        return MEMORY_PROBLEM;
    }

}
