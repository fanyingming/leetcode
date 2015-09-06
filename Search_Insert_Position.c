int searchInsert1(int* nums, int numsSize, int target) {
    int i;
    
    for( i=0; i<numsSize; i++ )
    {
        if(nums[i] == target)
            return i;
        else if(nums[i] <  target)
            continue;
        else
            return i;
    }
    
    return i;
}

int searchInsert(int* nums, int numsSize, int target) {
    int l, r, m;
    l = 0;
    r = numsSize-1;
//    assert(nums != NULL);
    while (l <= r) {
        m = l + (r-l)/2;
        if (nums[m] == target)
            return m;
        else if (target > nums[m])
            l = m + 1;
        else
            r = m - 1;
    }

    return l;
}