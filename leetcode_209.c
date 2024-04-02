#include <stdio.h>

// Sliding window method O(n)
int minSubArrayLen(int target, int *nums, int numsSize) {
    int left = 0;
    int right = 0;
    int total = 0;
    int minLength = numsSize + 1;
    
    for(right=0; right<numsSize; right++) {
        total += nums[right];
        while(total >= target) {
            int currentLen = right - left + 1;
            if(currentLen < minLength) {
                minLength = currentLen;
            }
            total -= nums[left];
            left++;
        }
    }
    return (minLength == numsSize + 1) ? 0 : minLength;
}

// Brute force method O(n^2)
int minSubArrayLen_bruteforce(int target, int *nums, int numsSize) {
    int start = 0;
    int end = 0;
    int minLength = numsSize + 1;
    
    for(start = 0; start <= numsSize; start++) {
        int sum = 0;
        for(end = start; end <= numsSize; end++) {
            sum += nums[end];
            if(sum >= target) {
                int currentLength = end - start + 1;
                if(currentLength < minLength) {
                    minLength = currentLength;
                }
                break;
            }
        }
    }
    return (minLength == numsSize + 1) ? 0: minLength;
}

int main() {
    int target = 7;
    int nums[] = {2,3,1,2,4,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int minLength = minSubArrayLen(target, nums, numsSize);
    printf("Minimal length of a subarray whose sum is greater than or equal to target = %d\n", minLength);
    return 0;

}