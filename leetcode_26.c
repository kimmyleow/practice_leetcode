int removeDuplicates(int* nums, int numsSize){
    int i = 1;
    int k = 1;

    for(i = 1; i<numsSize; i++){
         if(nums[i-1] < nums[i]){
            nums[k] = nums[i];
            k= k+1;
        }
    }
    return k;
}