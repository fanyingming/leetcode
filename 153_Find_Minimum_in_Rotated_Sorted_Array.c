int findMin(int* nums, int numsSize) {
    int min = nums[0];
    int i, m;
    int begin, end;
    
    if (nums[0] <= nums[numsSize-1])
        return nums[0];
    
    begin = 0;
    end = numsSize-1;
    
    //invariant: min value in [begin, end]
    while (begin < end) {
        m = (begin+end)/2;

        if (nums[m] < nums[end])
            end = m;
        else if (nums[m] > nums[end])//这里m要加一，否则会有死循环。因为begin与m是可能重合的，此时会死循环。
            begin = m+1;
//        else 
        //assert(0);
    }
    //assert(begin == end)
    
    return nums[begin];
    

}
