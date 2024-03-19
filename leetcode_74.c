#include <stdio.h>
#include <stdbool.h>

// lay flat the matrix
bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target) {
    if(matrix==NULL || matrixSize==0 || matrixColSize==NULL || *matrixColSize==0) {
        return false;
    }
    
    int row = matrixSize;
    int col = *matrixColSize;
    int left = 0;
    int right = rows*col - 1;
    
    while(left<=right) {
        int mid = left + (right - left)/2;
        int midElement = matrix[mid/col][mid%col];
        
        if(midElement == target) {
            return true;
        }else if(midElement < target) {
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return false;
}

// compare by row & column
bool searchMatrix_v2(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL || *matrixColSize == 0) {
        return false;
    }

    int rows = matrixSize;
    int cols = *matrixColSize;

    int left = 0;
    int right = rows - 1;

    while (left <= right) {
        int midRow = left + (right - left) / 2;
        int firstElementOfRow = matrix[midRow][0];
        int lastElementOfRow = matrix[midRow][cols - 1];

        if (firstElementOfRow <= target && target <= lastElementOfRow) {
            // Perform binary search within this row
            int rowLeft = 0;
            int rowRight = cols - 1;

            while (rowLeft <= rowRight) {
                int midCol = rowLeft + (rowRight - rowLeft) / 2;
                int midElement = matrix[midRow][midCol];

                if (midElement == target) {
                    return true;
                } else if (midElement < target) {
                    rowLeft = midCol + 1;
                } else {
                    rowRight = midCol - 1;
                }
            }

            return false; // Target not found in this row
        } else if (target < firstElementOfRow) {
            right = midRow - 1; // Search in upper rows
        } else {
            left = midRow + 1; // Search in lower rows
        }
    }

    return false;
}

int main() {
    int matrix[3][4] = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    
    int target = 3;
    int matrixSize = 3;
    int matrixColSize = 4;
    bool result = searchMatrix(matrix, matrixSize, &matrixColSize, target);
    if(result) {
        printf("Target exists in the matrix\n");
    }else{
        printf("Target does not exist in the matrix\n");
    }
    return 0;
}