#include<stdio.h>
#include<stdlib.h>

// Division method (stated in the question not allow to use)
// solution is [(axbxcxd)/a, (axbxcxd)/b, (axbxcxd)/c, (axbxcxd)/d)]

// O(n) solution
// 1. traverse the array twice
// 2. left to right to calculate prefix
// 3. right to left to calculate posfix
// 4. multiply corresponding prefix & posfix

int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int *prefix_products = (int*)malloc(numsSize * sizeof(int));
    int *posfix_products = (int*)malloc(numsSize * sizeof(int));
    int *answer = (int*)malloc(numsSize * sizeof(int));
    
    int i;
    prefix_products[0] = 1;
    for (i = 1; i < numsSize; i++) {
        prefix_products[i] = prefix_products[i - 1] * nums[i - 1];
        //printf("i = %d, prefix_value = %d\n", i, prefix_products[i]);
    }
    
    posfix_products[numsSize - 1] = 1;
    for (i = numsSize - 2; i >= 0; i--) {
        posfix_products[i] = posfix_products[i + 1] * nums[i + 1];
        //printf("i = %d, posfix_products = %d\n", i, posfix_products[i]);
    }
    
    // Multiply corresponding prefix and suffix products to get the answer
    for (i = 0; i < numsSize; i++) {
        answer[i] = prefix_products[i] * posfix_products[i];
        //printf("i = %d, answer = %d\n", i, answer[i]);
    }
    
    // Set the return size
    *returnSize = numsSize;
    
    // Free allocated memory
    free(prefix_products);
    free(posfix_products);
    
    return answer;
}

int main(){
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int i;
    int *answer = productExceptSelf(nums, numsSize, &returnSize);
    
    printf("[");
    for(i = 0; i < returnSize; i++){
        printf("%d", answer[i]);
        if(i != returnSize -1){
            printf(", ");
        }
    }
    
    printf("]\n");
    free(answer);
    
    return 0;
}
