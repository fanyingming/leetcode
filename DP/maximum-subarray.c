int max_my(int a, int b) {
    return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize) {
    int *sum = malloc(sizeof(int)*numsSize);
    int i;
    int max = 0;

    max = sum[0] = nums[0];

    for (i = 1; i < numsSize; i++) {
        if (sum[i-1] + nums[i] > nums[i]) { //key point.
            sum[i] = sum[i-1] + nums[i];
        } else {
            sum[i] = nums[i];
        }
        max = max_my(sum[i], max);
    }

    free(sum);

    return max;
}
