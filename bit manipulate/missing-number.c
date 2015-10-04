int missingNumber(int* nums, int numsSize) {
    int i, j;
    int bits[32];
    int res = 0;
    
    memset(bits, 0, sizeof(int)*32);
    for (j = 0; j < 32; j++)
            bits[j] += (numsSize>>j)&1;
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 32; j++)
            bits[j] += (nums[i]>>j)&1;
            
        for (j = 0; j < 32; j++)
            bits[j] += (i>>j)&1;
    }
    
    for (j = 0; j < 32; j++)
            res += (bits[j]%2)<<j;
    return res;
}