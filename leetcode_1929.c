/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    
    *returnSize = numsSize * 2;
    int *newNums = (int*)malloc(*returnSize * sizeof(int));
    
    for(int i = 0; i<numsSize; i++){
        newNums[i] = nums[i];
        newNums[i+numsSize] = nums[i];
    }

    return newNums;

}