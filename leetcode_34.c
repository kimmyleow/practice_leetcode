#include <stdio.h>
#include <stdlib.h>

int findLeftMostPosition(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int result = -1;
    
    while(right >= left) {
        int mid = left + (right - left)/2;
        
        if(nums[mid] >= target) {
            if(nums[mid] == target) {
                result = mid;
            }
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return result;
}

int findRightMostPosition(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int result = -1;
    
    while(right >= left) {
        int mid = left + (right - left)/2;
        
        if(nums[mid] <= target) {
            if(nums[mid] == target) {
                result = mid;
            }
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return result;
}

int* searchRange(int *nums, int numsSize, int target, int *returnSize) {
    int *result = (int*)malloc(sizeof(int) * 2);
    
    int left = findLeftMostPosition(nums, numsSize, target);
    int right = findRightMostPosition(nums, numsSize, target);
    
    result[0] = left;
    result[1] = right;
    *returnSize = 2;
    
    return result;
}

int main() {
    int nums[] = {5,7,7,8,8,10};
    int target = 8;
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    
    int *range = searchRange(nums, numsSize, target, &returnSize);
    
    printf("Output: [%d, %d]\n", range[0], range[1]);
    free(range);
    return 0;
}