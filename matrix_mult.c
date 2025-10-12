#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double **createRandomMatrix(int rows, int cols) {
    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
    return matrix;
}

double **matrixMultiply(double **A, double **B, int n1, int m1, int m2) {
    double **C = (double **)malloc(n1 * sizeof(double *));
    for (int i = 0; i < n1; i++) {
        C[i] = (double *)malloc(m2 * sizeof(double));
    }
    
    // Three nested loops for matrix multiplication
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < m1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return C;
}

void freeMatrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <matrix_size>\\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    srand(time(NULL));
    
    double **A = createRandomMatrix(n, n);
    double **B = createRandomMatrix(n, n);
    
    clock_t start = clock();
    double **C = matrixMultiply(A, B, n, n, n);
    clock_t end = clock();
    
    double time_ms = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    printf("Execution time: %.3f ms\\n", time_ms);
    
    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);
    
    return 0;
}