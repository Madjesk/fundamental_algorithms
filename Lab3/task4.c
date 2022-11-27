#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

enum {
    WRONG_ARGS = -1,
    SUCCESSFULLY = -2,
    MEMORY_PROBLEM = -3,
    CANT_OPEN_FILE = -4;
};

struct message {
    size_t id;
    char *text;
    size_t length;
    size_t size;
};

int create_csv_filename(char **file_name) {
    char symbol;
    int is_num;
    int len = rand() % 15 + 1;
    len += 5;

    *file_name = (char*)malloc(sizeof(char)*len);
    if(!*file_name) {
        return NO_MEMORY;
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

int message_initialization(message **item) {
    *item = (message*)malloc(sizeof(message));
    if(!*item) {
        return MEMORY_PROBLEM;
    }
    (*item)->id=1;
    (*item)->text = (char*)malloc((*item)->size * sizeof(char));
    if(!(*item)->text){
        return MEMORY_PROBLEM;
    }
    (*item)->size = 16;
    (*item)->length = 0;
    return SUCCESSFULLY;
}

fill_the_file(FILE *filename, message** item, int* size) {

}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    FILE* file;
    char *file_name = NULL;
    message *item;
    int counter_of_items=0;
    if(argc != 2) {
        printf("Wrong args\n", );
        return WRONG_ARGS;
    }

    if(create_csv_filename(&filename) == NO_MEMORY) {
        printf("Faild to create csv file, no memory\n", );
        return NO_MEMORY;
    }

    if(message_initialization(&item) == SUCCESSFULLY) {
        file = fopen(filename, "w");
        if(file == NULL) {
            return CANT_OPEN_FILE;
        }
        add_to_file(file, &item, argv[1], &counter_of_items)
    } else {
        printf("No Memory\n");
        return NO_MEMORY;
    }

}
