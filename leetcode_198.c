// Solution uses Dynamic Programming Method
// Solution 1
/*
int rob(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    }

    int prevRobbed = nums[0]; // Maximum money if the first house is robbed
    int prevNotRobbed = 0;   // Maximum money if the first house is not robbed

    for (int i = 1; i < numsSize; i++) {
        int currentRobbed = prevNotRobbed + nums[i];
        int currentNotRobbed = (prevRobbed > prevNotRobbed) ? prevRobbed : prevNotRobbed;

        prevRobbed = currentRobbed;
        prevNotRobbed = currentNotRobbed;
    }

    return (prevRobbed > prevNotRobbed) ? prevRobbed : prevNotRobbed;
}
*/

// Solution 2: result = max(total[n-2] + nums[n], total[n-1]);
int rob(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    }

    int *result = (int*)malloc(numsSize * sizeof(int));
    result[0] = nums[0];
    result[1] = fmax(nums[0], nums[1]);

    for(int i=2; i<numsSize; i++){
        result[i] = fmax((result[i-2] + nums[i]), result[i-1]);
    }

    return result[numsSize-1];
}