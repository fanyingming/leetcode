#include <stdio.h>
#include <assert.h>

void swap(int *arr, int i, int j)
{
	int t;
	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void bubble_sort(int *arr, int n)
{
	int i, j;
	assert(arr);

	for (i = 0; i < n; i++)
		for ( j = i+1; j < n; j++){
		//invariant:arr[0,j-1] sorted.
			if(arr[j] < arr[i])
				swap(arr, i, j);
		}
}

#define LENGTH(v) sizeof(v)/sizeof(v[0])


int main()
{
	int nums[] = {5,9,1,6,2,9,10};
	int i;

	bubble_sort(nums, LENGTH(nums));
//	qsort(nums, 0, LENGTH(nums)-1);

	for( i=0; i<LENGTH(nums); i++)
		printf("%d\t", nums[i]);

	printf("\n");
}