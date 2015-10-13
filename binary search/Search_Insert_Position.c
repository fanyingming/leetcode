/*
** 注意一个特征，left最小到0,而right可以无限扩大。
** 这恰好与left的值一致。
*/
int searchInsert(int* nums, int numsSize, int target) {
    int l, r, m;
    l = 0;
    r = numsSize-1;
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