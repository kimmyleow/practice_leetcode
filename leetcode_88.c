void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int k = 0;

    k = m + n;

    while(m>0 && n>0){
        if(nums1[m-1] > nums2[n-1] ){
            nums1[k-1] = nums1[m-1];
            m = m - 1;
        }else{
            nums1[k-1] = nums2[n-1];
            n = n - 1;
        }
        k = k - 1;
    }

    while(n>0){
        nums1[k-1] = nums2[n-1];
        k--;
        n--;
    }

}