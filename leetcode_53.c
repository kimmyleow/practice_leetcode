int maxSubArray(int* nums, int numsSize){
    int maxSum = nums[0];
    int currSum = nums[0];

    for(int i=1; i<numsSize; i++){
        // Compare whether it's better to extend the current subarray or start a new subarray
        currSum = (currSum>0)? currSum + nums[i]: nums[i];
        // Update maxSum if we find a larger sum
        maxSum = (currSum > maxSum) ? currSum : maxSum;
    }

    return maxSum;
}