
int jump(int* nums, int numsSize){
    int maxPos = 0;
    int end = 0;
    int jump = 0;
    int i = 0;

    for(i=0;i<numsSize-1;i++){
        if(maxPos>=i){
            maxPos = fmax(maxPos, i + nums[i]);
        }

        if(end == i){
            jump++;
            end = maxPos;
        }
    }
    return jump;
}