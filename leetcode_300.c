#include<stdio.h>

#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif

int lengthOfLIS(int* nums, int numsSize) {
    int i,j;
    int maxLen = 1;
    int dp[numsSize];
    
    if(numsSize == 0) return 0;
    
    for(i=0; i<numsSize; i++){
        dp[i] = 1;
    }
    
    for(i=1; i<numsSize; i++){
        for(j=0; j<i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], 1+dp[j]);
                maxLen = max(maxLen, dp[i]);
            }
        }
    }
    return maxLen;
}

int main()
{
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    
    int result = lengthOfLIS(nums, numsSize);
    
    printf("Length of the longest increasing subsequence: %d\n", result);
    
    return 0;
    
}