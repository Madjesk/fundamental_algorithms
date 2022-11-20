#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

enum {
    SUCCESSFULLY = -3,
    WRONG_MATRICES = -4
};

float **generate_matrix(int *rows, int *columns) {
    *rows = rand() % 10 + 1;
    *columns = rand() % 10 + 1;
    *rows=3;
    *columns=3;
    float **matrix = (float**)malloc(sizeof(float *) * *rows);

    for(int i =0; i < *rows; i++) {
        matrix[i] = (float*)malloc(sizeof(float) * *columns);
        for(int j=0; j < *columns; j++) {
            matrix[i][j] = rand() % 200 - 100;
        }
    }
    return matrix;
}

void print_matrix(float **matrix, int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%9.1f", matrix[i][j]);
        }
        printf("\n");
    }
}

float **multiply_matrices(float **matrix1, float **matrix2, int rows_m1, int columns_m1, int rows_m2, int columns_m2) {
    float **new_matrix = NULL;
    if(columns_m1 == rows_m2) {
        new_matrix = (float **)malloc(sizeof(float *) * rows_m1);
        for(int i = 0; i < rows_m1; i++) {
            new_matrix[i] = (float *)malloc(sizeof(float) * columns_m2);
        }

        for(int i = 0; i < rows_m1; i++) {
            for(int j = 0; j < columns_m2; j++) {
                new_matrix[i][j] = 0;
                for(int k = 0; k < columns_m1; k++) {
                    new_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }
    return new_matrix;
}


//int find_determinant() {
//
//}
//
void free_matrix(float **matrix, int rows) {
    for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main(int argc, char * argv[]) {
    srand(time(NULL));
    int rows_of_matrix1 = 0, columns_of_matrix1 = 0;
    int rows_of_matrix2 = 0, columns_of_matrix2 = 0;

    float **matrix1 = generate_matrix(&rows_of_matrix1, &columns_of_matrix1);
    printf("First matrix: \n");
    print_matrix(matrix1, rows_of_matrix1, columns_of_matrix1);

    float **matrix2 = generate_matrix(&rows_of_matrix2, &columns_of_matrix2);
    printf("Second matrix: \n");
    print_matrix(matrix2, rows_of_matrix2, columns_of_matrix2);

    float **new_matrix = multiply_matrices(matrix1, matrix2, rows_of_matrix1, columns_of_matrix1, rows_of_matrix2, columns_of_matrix2);
    if(new_matrix != NULL) {
        printf("After multiplying 2 matrices: \n");
        print_matrix(new_matrix, rows_of_matrix1, columns_of_matrix2);
        free_matrix(new_matrix, rows_of_matrix1);
    } else {
        printf("Failed to multiply 2 matrices\n");
    }


//    free_matrix(new_matrix, rows_of_matrix1);
    free_matrix(matrix1, rows_of_matrix1);
    free_matrix(matrix2, rows_of_matrix2);
}