#include<stdio.h>

int missingNumber(int* nums, int numsSize) {
    int expectedSum = 0;
    int missingSum = 0;
    int missingNum = 0;
    int i = 0;
    
    for(i=0; i<numsSize; i++)
    {
        missingSum += nums[i];
    }

    //expectedSum = numsSize * (numsSize + 1) / 2;
    for(i=0; i<numsSize+1; i++)
    {
        expectedSum = expectedSum + i;
    }
    
    printf("missingsum = %d\n", missingSum);
    printf("expectedSum = %d\n", expectedSum);
    
    missingNum = expectedSum - missingSum;
    return missingNum;
}

int main()
{
    int nums[] = {3, 0, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int missing = missingNumber(nums, numsSize);
    printf("The missing number is: %d\n", missing);
    return 0;
}