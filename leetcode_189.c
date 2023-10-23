void rotate(int* nums, int numsSize, int k){

  //solution 1: (i+k)%length_of_array
  //solution 2: reverse entire array, then reverse according to k

  //solution 1
 
  int newPos = 0;
  int i = 0;
  int num2[numsSize];

  for(i=0;i<numsSize;i++){
    newPos = (i+k)%numsSize;
    num2[newPos] = nums[i];
  }

  for(i=0;i<numsSize;i++){
    nums[i] = num2[i];
  }
}