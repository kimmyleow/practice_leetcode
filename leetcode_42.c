#include <stdio.h>

#ifndef max
#define max(a,b)    (((a) > (b) ? (a) : (b)))
#endif

#ifndef min
#define min(a,b)    (((a) < (b) ? (a) : (b)))
#endif

// This is using 2 pointer solution
// Time complexity O(n), memory complexity O(1)
int trap(int *height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;
    int leftMax = height[l];
    int rightMax = height[r];
    int res;
    
    while(r>l) {
        if(rightMax > leftMax) {
            l += 1;
            leftMax = max(leftMax, height[l]);
            res += leftMax - height[l];
        }else{
            r -= 1;
            rightMax = max(rightMax, height[r]);
            res += rightMax - height[r];
        }
    }
    return res;
}

// This is array solution
// Store minLeft & minRight
// min(left, right) - height
// Time complexity O(n), memory complexity O(n)
int trap_v2(int *height, int heightSize) {
    int leftMax[heightSize];
    int rightMax[heightSize];
    int i = 0;
    int res = 0;
    
    leftMax[0] = height[0];
    for(i=1; i<heightSize; i++) {
        //leftMax[i] = (height[i] > leftMax[i-1]) ? height[i] : leftMax[i-1];
        leftMax[i] = max(height[i], leftMax[i-1]);
    }
    
    rightMax[heightSize-1] = height[heightSize-1];
    for(i= heightSize-2; i>=0; i--) {
        //rightMax[i] = (height[i] > rightMax[i+1]) ? height[i] : rightMax[i+1];
        rightMax[i] = max(height[i], rightMax[i+1]);
    }
    
    for(i=0; i<heightSize; i++) {
        res += min(leftMax[i], rightMax[i]) - height[i];
    }
    return res;
}

int main() {
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int heightSize = sizeof(height)/sizeof(height[0]);
    int trappedWater = trap(height, heightSize);
    printf("The amount of water trapped after raining is: %d\n", trappedWater);
    return 0;
}