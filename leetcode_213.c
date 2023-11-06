int robberHelper(int* house, int houseNum){
    int *result = (int*)malloc(houseNum * sizeof(int));

    result[0] = house[0];
    result[1] = fmax(house[0], house[1]);

    for(int i = 2; i < houseNum; i++){
        result[i] = fmax(result[i-2] + house[i], result[i-1]);
    }

    int maxAmount = result[houseNum-1];

    free(result); // Don't forget to free the memory when done.

    return maxAmount;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    } else if (numsSize == 2){
        return fmax(nums[0], nums[1]);
    }

    int* first_to_skip = (int*)malloc((numsSize-1) * sizeof(int));
    int* last_to_skip = (int*)malloc((numsSize-1) * sizeof(int));

    if (first_to_skip == NULL || last_to_skip == NULL) {
        // Handle memory allocation failure
        return 0; // You can use an error code or other appropriate handling here.
    }

    // Calculate first_to_skip and last_to_skip
    for (int i = 0; i < numsSize - 1; i++) {
        first_to_skip[i] = nums[i + 1];  // Skip the first house
        last_to_skip[i] = nums[i];       // Skip the last house
    }

    int first = robberHelper(first_to_skip, numsSize - 1);
    int last = robberHelper(last_to_skip, numsSize - 1);

    free(first_to_skip);
    free(last_to_skip);

    return fmax(nums[0], fmax(first, last));
}