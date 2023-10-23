bool canJump(int* nums, int numsSize){
    int goal = 0;
    int i = 0;

    goal = numsSize - 1;

    for(i=numsSize-2; i>=0; i--){
        if(i + nums[i] >= goal){
            goal = i;
        }
    }

    if(goal == 0){
        return true;
    }

    return false;
}