int removeElement_v1(int* nums, int numsSize, int val) {
    int len = numsSize;
    int i ,j;
    
    if (nums == NULL || numsSize <= 0)
        return 0;
    
    //invariant: [0,i] no val.
    for (i = 0; i < len;) {
        if (nums[i] == val) {
            for (j = i; j+1 < len; j++)
                nums[j] = nums[j+1];
            len--;
        } else {
            i++;
        }
        
    }
    
    return len;
}

int removeElement(int* nums, int numsSize, int val) {
    int len = numsSize;
    int i ,j;
    int index = 0;
    
    if (nums == NULL || numsSize <= 0)
        return 0;
    
    //invariant: [0,index) no val.
    for (i = 0; i < len; i++) {
       if (nums[i] != val) {
           nums[index++] = nums[i];
       }
    }
    
    return index;
}