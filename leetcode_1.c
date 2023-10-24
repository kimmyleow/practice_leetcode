/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //Brute force method
 //Use 2 for loop to add all the possible combination to get target number
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    for(int i=0; i<numsSize-1;i++){
      for(int j=i+1; j<numsSize;j++){
        if (nums[i] + nums[j] == target) {
          result[0] = i;
          result[1] = j;
          return result;
      }
    }
    }
    return NULL;
}