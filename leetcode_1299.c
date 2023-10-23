/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int* replaceElements(int* arr, int arrSize, int* returnSize) {
     int maxRight = -1;
     *returnSize = arrSize;

     for(int i = arrSize - 1; i>=0; i-- ){
         int currentElement = arr[i];
        arr[i] = maxRight;
        if (currentElement > maxRight) {
            maxRight = currentElement;
        }
     }
     return arr;
 }

 // Brute force solution
/*int* replaceElements(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;

    for (int i = 0; i < arrSize - 1; i++) {
        int maxRight = arr[i + 1];
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j] > maxRight) {
                maxRight = arr[j];
            }
        }
        arr[i] = maxRight;
    }

    arr[arrSize - 1] = -1;
    
    return arr;
}*/

