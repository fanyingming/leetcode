#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left, right, middle;
    
    //error handling.
    if (numsSize <= 0)
        return -1;
    
    left = 0;
    right = numsSize-1;
    middle = (left+right)/2;
    
    //can make sure that left, right, middle won't bigger than numsSize-1 or less than 0.
    while (left <= right)
    {
        if (left == right || right == middle)
            return nums[middle];
        if (middle == left)
            return nums[right];
        if (nums[middle] > nums[right])
        {
            left = middle;
            middle = (left+right)/2;
        }
        else
        {
            right = middle;
            middle = (left + right)/2;
        }

    }

}

int main()
{
    int nums[] = {1, 2};
    int res = findMin(nums, sizeof(nums)/sizeof(nums[0]));

    printf("result is %d\n", res);
}