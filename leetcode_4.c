#include<stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int low = 0;
    int high = nums1Size;
    int totalLen = nums1Size + nums2Size;
    
    while(high >= low) {
        int partition1 = (low + high)/2; //mid indices of nums1
        int partition2 = (totalLen + 1)/2 - partition1; //mid indices of nums2
        
        // handle the edges cases & left and right point of the nums1 and nums2
        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == nums1Size) ? INT_MAX : nums1[partition1];
        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == nums2Size) ? INT_MAX : nums2[partition2];
        
        if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if(totalLen % 2 == 0) {
                return((double) (fmax(maxLeft1, maxLeft2) + fmin(minRight1, minRight2))) / 2;
            }else{
                return fmax(maxLeft1, maxLeft2);
            }
        }else if(maxLeft1 > minRight2) {
            high = partition1 - 1;
        }else{
            low = partition1 + 1;
        }
    }
    return 0.0;
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int nums1Size = sizeof(nums1)/sizeof(nums1[0]);
    int nums2Size = sizeof(nums2)/sizeof(nums2[0]);
    
    double median = findMedianSortedArrays(nums1, nums1Size,nums2, nums2Size);
    printf("Median = %.2f\n", median);
    
    return 0;
}