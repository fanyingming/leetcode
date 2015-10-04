int singleNumber(int* nums, int numsSize) {
    int bits[32];
    int i, j, res;
    memset(bits, 0, 32*sizeof(int));
    
    for (i = 0; i < numsSize; i++)
        for (j = 0; j < 32; j++)
            bits[j] += (nums[i]>>j)&1;
    res = 0;
    for (i = 0; i < 32; i++)
        res += (bits[i]%3)<<i;
    return res;
}