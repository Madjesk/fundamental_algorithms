#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define EPS 1e-7

enum {
    WRONG_MATRIX_SIZE = -5
};

float **generate_matrix(int *rows, int *columns) {
    *rows = rand() % 10 + 1;
    *columns = rand() % 10 + 1;
    float **matrix = (float**)malloc(sizeof(float *) * *rows);
    if(matrix == NULL) {
        return NULL;
    }

    for(int i =0; i < *rows; i++) {
        matrix[i] = (float*)malloc(sizeof(float) * *columns);
        if(matrix[i] == NULL) {
            return NULL;
        }
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
    printf("\n");
}

float **multiply_matrices(float **matrix1, float **matrix2, int rows_m1, int columns_m1, int rows_m2, int columns_m2) {
    float **new_matrix = NULL;
    if(columns_m1 == rows_m2) {
        new_matrix = (float **)malloc(sizeof(float *) * rows_m1);
        if(new_matrix == NULL) {
            return NULL;
        }
        for(int i = 0; i < rows_m1; i++) {
            new_matrix[i] = (float *)malloc(sizeof(float) * columns_m2);
            if(new_matrix[i] == NULL) {
                return NULL;
            }
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


int find_determinant(float **matrix, int rows, int columns) {
    if(rows != columns) {
        return WRONG_MATRIX_SIZE;
    } else {
        int det = 1;
        float * tmp;
        for (int i = 0; i < rows; i++) {
            int k = i;
            for (int j = i + 1; j < rows; j++)
                if (fabs(matrix[j][i]) > fabs(matrix[k][i]))
                    k = j;
            if (fabs(matrix[k][i]) < EPS) {
                det = 0;
                break;
            }
            tmp = matrix[i];
            matrix[i] = matrix[k];
            matrix[k] = tmp;
            if (i != k)
                det = -det;
            det *= matrix[i][i];
            for (int j = i + 1; j < rows; j++)
                matrix[i][j] /= matrix[i][i];
            for (int j = 0; j < rows; ++j)
                if (j != i && fabs(matrix[j][i]) > EPS)
                    for (int k = i + 1; k < rows; k++)
                        matrix[j][k] -= matrix[i][k] * matrix[j][i];
        }
        return det;
    }
}

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
    int determinant_of_matrix1, determinant_of_matrix2;
    float **matrix1 = generate_matrix(&rows_of_matrix1, &columns_of_matrix1);

    if(matrix1 != NULL) {
        printf("First matrix: \n");
        print_matrix(matrix1, rows_of_matrix1, columns_of_matrix1);
    } else {
        printf("Failed to generate 1 matrix");
    }

    float **matrix2 = generate_matrix(&rows_of_matrix2, &columns_of_matrix2);
    if(matrix1 != NULL) {
        printf("Second matrix: \n");
        print_matrix(matrix2, rows_of_matrix2, columns_of_matrix2);
    } else {
        printf("Failed to generate 2 matrix");
    }

    float **new_matrix = multiply_matrices(matrix1, matrix2, rows_of_matrix1, columns_of_matrix1, rows_of_matrix2, columns_of_matrix2);
    if(new_matrix != NULL) {
        printf("After multiplying 2 matrices: \n");
        print_matrix(new_matrix, rows_of_matrix1, columns_of_matrix2);
        free_matrix(new_matrix, rows_of_matrix1);
    } else {
        printf("Failed to multiply 2 matrices\n");
    }

    determinant_of_matrix1 = find_determinant(matrix1, rows_of_matrix1, columns_of_matrix1);
    determinant_of_matrix2 = find_determinant(matrix2, rows_of_matrix2, columns_of_matrix2);

    if(determinant_of_matrix1 != -5) {
        printf("Determinant of first matrix: %d\n", determinant_of_matrix1);
    } else {
        printf("Failed to find determinant of first matrix\n");
    }

    if(determinant_of_matrix2 != -5) {
        printf("Determinant of second matrix: %d\n", determinant_of_matrix2);
    } else {
        printf("Failed to find determinant of second matrix\n");
    }

    free_matrix(matrix1, rows_of_matrix1);
    free_matrix(matrix2, rows_of_matrix2);
}