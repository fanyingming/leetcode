#include <stdlib.h>
#include <stdio.h>

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

#define LENGTH(v) sizeof(v)/sizeof(v[0])


int main()
{
	int nums[] = {5,9,1,6,2,9,10};
	int i;

	qsort_my(nums, 0, LENGTH(nums)-1);
//	qsort(nums, 0, LENGTH(nums)-1);

	for( i=0; i<LENGTH(nums); i++)
		printf("%d\t", nums[i]);

	printf("\n");
}
