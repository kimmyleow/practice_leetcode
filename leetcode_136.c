#include<stdio.h>

int singleNumber(int *nums, int numsSize)
{
    int result = 0;
    int i;
    
    for(i=0; i<numsSize; i++)
    {
        result ^= nums[i];
    }
    return result;
}

int main()
{
    int nums1[] = {2, 2, 1};
    int nums2[] = {4, 1, 2, 1, 2};
    
    int result1 = singleNumber(nums1, sizeof(nums1) / sizeof(nums1[0]));
    int result2 = singleNumber(nums2, sizeof(nums2) / sizeof(nums2[0]));
    
    printf("Result1 = %d\n", result1);
    printf("Result2 = %d\n", result2);
}