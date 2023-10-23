int removeDuplicates(int* nums, int numsSize){
  int i = 0;
  int count = 0;

  for(i=0;i<numsSize;i++){
    if(count<2 || nums[i] >nums[count-2]){
      nums[count++] = nums[i];
    }
  }
  return count;
}