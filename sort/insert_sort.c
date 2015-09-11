#include <stdio.h>
#include <assert.h>

void swap(int *arr, int i, int j)
{
	int t;
	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void insert_sort_version1(int *arr, int n)
{
	int i, j, k;
	assert(arr);

	for (j = 1; j < n; j++){
		//invariant:arr[0,j-1] sorted.
		int v = arr[j];

		for (i = j-1; i >= 0; i--){
			if (v > arr[i])
				break;
		}
		//position i+1 is right place for v;
		for (k = j; k > i+1; k--){
			arr[k] = arr[k-1];
		}
		arr[i+1] = v;
	}
}

void insert_sort_version2(int *arr, int n)
{
	int i, j, k;
	assert(arr);

	for (j = 1; j < n; j++){
		//invariant:arr[0,j-1] sorted.
		int v = arr[j];

		for (i = j-1; i >= 0; i--){
			if (v < arr[i]){
				arr[i+1] = arr[i];
			} else
			 	break;
		}
		//position i is right place for v;
		arr[i+1] = v;
	}
}

void insert_sort_version3(int *arr, int n)
{
	int i, j, k;
	assert(arr);

	for (j = 1; j < n; j++){
		//invariant:arr[0,j-1] sorted.
		int v = arr[j];

		i = j-1;
		while (i >= 0 && arr[i] > v){
			arr[i+1] = arr[i];
			i--;
		}
		//position i is right place for v;
		arr[i+1] = v;
	}
}

#define LENGTH(v) sizeof(v)/sizeof(v[0])


int main()
{
	int nums[] = {5,9,1,6,2,9,10};
	int i;

	insert_sort_version3(nums, LENGTH(nums));
//	qsort(nums, 0, LENGTH(nums)-1);

	for( i=0; i<LENGTH(nums); i++)
		printf("%d\t", nums[i]);

	printf("\n");
}