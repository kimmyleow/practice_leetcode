int majorityElement(int* nums, int numsSize){
  int count = 1;
  int currentIdx = 0;
  int i = 0;

  for(i=0;i<numsSize;i++)
  {
    if(nums[currentIdx] == nums[i]){
      count++;
    }else{
      count--;
    }

    if(!count){
      currentIdx = i;
      count = 1;
    }
  }

  return nums[currentIdx];

}