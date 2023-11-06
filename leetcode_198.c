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