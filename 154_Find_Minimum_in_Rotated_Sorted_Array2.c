#include <stdio.h>

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
        
        if (nums[m] > nums[begin])
            begin = m;
        else if (nums[m] < nums[begin])
            end = m;
        else //m and begin is the same index.
            return min_my(nums[begin], nums[end]);
    }
    //assert(begin == end)
    
    return nums[begin];
}

int main()
{
	int a[3] = {3,1,3};
	int rv = findMin(a, 3);

	printf("%d\n",rv);
}