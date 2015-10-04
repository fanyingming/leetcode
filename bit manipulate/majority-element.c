//trick is that if majority element exist, it will only one.

int majorityElement(int* nums, int numsSize) {
    int major, i, count;
      
    count = 1;
    major = nums[0];
    for (i = 1; i < numsSize; i++) {
        if (nums[i] == major) {
            count++;
        } else {
            count--;
            if (count == 0) {
                major = nums[i];
                count++;
            }
        }
    }
    
    return major;
}