#include<stdio.h>
#include<stdlib.h>

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

// Brute force method : use 2 for loops to find every possible combination O(n^2)
// Method 1: using Kadane's Algorithm (Dynamic Programming)
int maxSubArray(int *nums, int numsSize)
{
    int maxValue = nums[0];
    int currentMax = nums[0];
    int i = 0;
    
    for(i=1; i<numsSize; i++)
    {
        currentMax = max(nums[i], nums[i] + currentMax);
        maxValue = max(maxValue, currentMax);
    }
    
    return maxValue;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    
    int result = maxSubArray(nums, numsSize);
    printf("Output: %d\n", result);
    
    return 0;
}