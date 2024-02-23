#include<stdio.h>
#include<stdlib.h>

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

int maxProduct(int* nums, int numsSize) {
    int max_product = nums[0];
    int min_product = nums[0];
    int result = nums[0];
    int temp = 0;
    
    for(int i = 1; i < numsSize; i++)
    {
        //handling if element is 0
        if(nums[i] == 0)
        {
            min_product = 1;
            max_product = 1;
        }
        else if(nums[i] < 0)
        {
            //handling if element is negative
            temp = max_product;
            max_product = min_product;
            min_product = temp;
        }
        
        max_product = max(nums[i], max_product * nums[i]);
        min_product = min(nums[i], min_product * nums[i]);
        
        result = max(result, max_product);
    }
    
    return result;
}

int main()
{
    int nums[] = {2,3,-2,4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    
    int result = maxProduct(nums, numsSize);
    printf("result = %d\n", result);
    
    return 0;
}