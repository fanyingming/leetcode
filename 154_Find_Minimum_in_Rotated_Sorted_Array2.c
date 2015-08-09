int min_my(int a, int b) {
    if (a <= b)
        return a;
    else
        return b;
}

int findMin(int* nums, int numsSize) {
    int min = nums[0];
    int i, m;
    int begin, end;
    
    if (nums[0] < nums[numsSize-1])
        return nums[0];
    
    begin = 0;
    end = numsSize-1;
    
    //invariant: min value in [begin, end]
    while (begin < end) {
        m = (begin+end)/2;
        
        if (nums[m] > nums[end]) {//当中间的值小于最右边值时，bein = m+1，因为最小值一定位于[m+1,r]。
            begin = m+1;
        } else if (nums[m] < nums[end]) {
            end = m;
        } else {//当中间值和end值相等时，他们一定不是同一个小标，同一个index的情况值出现于m和begin相等，所以这里直接-1是
        //没有什么问题的。减一后大不了最小值落到m处。
            end--;
        }
    }
    //assert(begin == end)
    
    return nums[begin];
}
