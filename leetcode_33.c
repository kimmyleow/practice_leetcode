#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int index_left = 0;
    int index_right = numsSize - 1;
    int mid = 0;

    while(index_right >= index_left) {
        mid = index_left + (index_right - index_left) / 2;

        if(nums[mid] == target) {
            return mid;
        }
        
        //left sorted
        if(nums[mid] >= nums[index_left]) {
            if(nums[index_left] <= target && target < nums[mid]) {
                index_right = mid - 1;
            }else{
                index_left = mid + 1;
            }
        }else{ //Right sorted
            if(nums[mid] < target && target <= nums[index_right]) {
                index_left = mid + 1;
            }else{
                index_right = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int nums[] = {4,5,6,7,0,1,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 0;
    int result = search(nums, numsSize, target);
    printf("Index of %d: %d\n", target, result);
    return 0;
    
}