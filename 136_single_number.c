#include <stdio.h>

int singleNumber(int* nums, int numsSize)
{
	int value;
	int i;

	value = nums[0];
	for( i=1; i< numsSize; i++)
	{
		value = value^nums[i];
	}

	return value;
}

int main()
{
	int nums[] = {1, 3, 5, 1, 5};

	int rv = singleNumber(nums, 5);

	printf("%d\n",rv);
}