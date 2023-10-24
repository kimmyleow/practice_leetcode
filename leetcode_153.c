int findMin(int* nums, int numsSize){
  int left, right, mid;
  left = 0;
  right = numsSize-1;
  
  while(right>left){
    mid = left + (right - left)/2;

    // If the middle element is greater than the right end, it means the minimum is in the right subarray
    if(nums[mid]>nums[right]){
      left = mid + 1;
    // If the middle element is less than the right end, it means the minimum is in the left subarray
    }else if(nums[right]<nums[mid]){
      right = mid;
    // If they are equal, move the right pointer to eliminate duplicates
    }else{
      right--;
    }
  }
  return nums[left];
}