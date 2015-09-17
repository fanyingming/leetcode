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
    int min = nums[0];
    int i, m;
    int begin, end;
    
    begin = 0;
    end = numsSize-1;
    
    //invariant: min value in [begin, end]
    while (begin < end) {
        m = (begin+end)/2;

        if (nums[m] < nums[end])
            end = m;
        else if (nums[m] > nums[end])//这里m要加一，否则会有死循环。因为begin与m是可能重合的，此时会死循环。
            begin = m+1;
        else
            end--;
    }
    return begin;
}

bool search(int* nums, int numsSize, int target) {
    int rv = -1;
    int index = findMin(nums, numsSize);
    
    if (nums[0] == nums[numsSize-1]) {
        int i;
        for (i = 0; i < numsSize; i++)
            if (nums[i] == target){
                rv = i;
                break;
            }
    } else {
        if (target > nums[numsSize-1]) {//target bigger than most right num, then must appear in [0,index-1] or not appear at nums.
            rv = binarySearch(nums, numsSize, target, 0, index-1);
        } else {
            rv = binarySearch(nums, numsSize, target, index, numsSize-1);
        }
    }
    return rv == -1 ? false : true;
}
