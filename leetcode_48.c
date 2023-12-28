#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int top, bottom, left, right;
    int i;
    int topleft;

    left = 0;
    right = matrixSize - 1;

    while (right > left) {
        for (i = 0; i < right - left; i++) {
            top = left;
            bottom = right;

            // save top left
            topleft = matrix[top][left + i];

            // move bottom left to top left
            matrix[top][left + i] = matrix[bottom - i][left];

            // move bottom right to bottom left
            matrix[bottom - i][left] = matrix[bottom][right - i];

            // move top right to bottom right
            matrix[bottom][right - i] = matrix[top + i][right];

            // move top left to top right
            matrix[top + i][right] = topleft;
        }
        right -= 1;
        left += 1;
    }
}

// Function to print a matrix
void printMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int i,j;
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    // Example matrix
    int matrixSize = 3;
    int matrixColSize = 3;
    int matrixData[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int i,j;
    
    // Allocate memory for matrix
    int **matrix = (int**)malloc(matrixSize * sizeof(int*));
    for(i=0; i<matrixSize; i++){
        matrix[i] = (int*)malloc(matrixColSize * sizeof(int));
        for(j=0; j<matrixColSize; j++){
            matrix[i][j] = matrixData[i][j];
        }
    }
    
    // print the original matrix
    printf("Original matrix:\n");
    printMatrix(matrix, matrixSize, &matrixColSize);
    
    // rotate the matrix in-place
    rotate(matrix, matrixSize, &matrixColSize);
    
    // print the rotated matrix
    printf("\nRotated matrix: \n");
    printMatrix(matrix, matrixSize, &matrixColSize);
    
    for(i=0; i<matrixSize; i++){
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}