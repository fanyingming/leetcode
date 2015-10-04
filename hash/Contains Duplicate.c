#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#define true 1
#define false 0
void qsort_my(int *nums, int begin, int end)
{
	int i, j, key;

	if(begin >= end)
		return;

	key = nums[begin];
	i = begin;
	j = end;

	while(i < j)
	{

		while(i<j && nums[j]>=key)
		{
			j--;
		}

		nums[i] = nums[j];
//		nums[j] = key;

		while(i<j && nums[i]<=key)
		{
			i++;
		}

		nums[j] = nums[i];
		nums[i] = key;
	}

	qsort_my(nums, begin, i-1);
	qsort_my(nums, i+1,end);

}

//#define LENGTH(v) sizeof(v)/sizeof(v[0])

int containsDuplicate(int* nums, int numsSize) {
    int i, j;

	qsort_my(nums, 0, numsSize-1);

    for( i=0; i<numsSize-1; i++){
        if(nums[i] == nums[i+1])
			return true;
    }

    return false;
}

int main()
{
    int nums[] = {1,2,3,4};
    int b_value;

    b_value = containsDuplicate(nums, sizeof(nums)/sizeof(nums[0]));

    if(b_value)
        printf("contain dump.");
    else
        printf("no dump.");

}
