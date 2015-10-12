int findMin(int* nums, int numsSize) {
    int l, r, m;

    if (nums[0] <= nums[numsSize-1])
        return nums[0];

    l = 0;
    r = numsSize-1;
    while (l < r) {
        m = l + (r-l)/2;
        //注意！我们要与右边的边界比，与左边的边界比，问题多多！！！
        //第二次重写就试了左边，写不对~~~
        if (nums[m] < nums[r])
            r = m;
        else 
            l = m+1;
    }
    return nums[l];
}