/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *rv = malloc(2*sizeof(int));
    int l1, r1, l2, r2, m1, m2;
    int pos_l, pos_r;
    int first_pos = -1;
    int last_right = -1;
    
    l1 = 0;
    r1 = numsSize-1;
    pos_l = pos_r = -1;
    
    while (l1 <= r1) {
        m1 = (l1+r1)/2;
        if (nums[m1] > target) {
            last_right = r1;
            r1 = m1 - 1;
        } else if (nums[m1] < target) {
            l1 = m1 + 1;
        } else { // search left dir.
            pos_l = m1;
            r1 = m1 - 1;
            if (first_pos == -1)
                first_pos = pos_l;
        }
    }
    if (first_pos >= 0) {
        if (last_right < 0)
            last_right = numsSize-1;
        l2 = first_pos;
        r2 = last_right;//;
        while (l2 <= r2) {
            m2 = (l2+r2)/2;
            if (nums[m2] > target) {
                r2 = m2 - 1;
            } else if (nums[m2] < target) {
                l2 = m2 + 1;
            } else { // search right dir.
                pos_r = m2;
                l2 = m2 + 1;
            }
        }
    }
    
    rv[0] = pos_l;
    rv[1] = pos_r;
    *returnSize = 2;
    return rv;
}
