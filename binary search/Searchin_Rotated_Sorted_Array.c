int binarySearch (int* nums, int numsSize, int target, int l, int r) {
    int m;
    
    while (l <= r) {
        m = (l+r)/2;
        if (nums[m] < target)
            l = m+1;
        else if (nums[m] > target)
            r = m-1;
        else
            return m;
    }
    return -1;
}

int findMin(int* nums, int numsSize) {
    int l, r, m;

        else if (nums[m] > nums[end])//这里m要加一，否则会有死循环。因为begin与m是可能重合的，此时会死循环。
    if (nums[0] <= nums[numsSize-1])
        return nums[0];

    l = 0;
    r = numsSize-1;
    while (l < r) {
        m = l + (r-l)/2;
        if (nums[m] < nums[r])
            r = m;
        else 
            l = m+1;
    }
    return nums[l];
}

int search(int* nums, int numsSize, int target) {
    int rv;
    int index = findMin(nums, numsSize);
    
    if (target > nums[numsSize-1]) {//target bigger than most right num, then must appear in [0,index-1] or not appear at nums.
        rv = binarySearch(nums, numsSize, target, 0, index-1);
    } else {
        rv = binarySearch(nums, numsSize, target, index, numsSize-1);
    }
    
    return rv;
}
