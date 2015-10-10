#include <stdlib.h>
#include <stdio.h>

void swap(int *arr, int i, int j)
{
	int t;
	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

int partition_version1(int *nums, int begin, int end)
{
	int i, j, key;

	key = nums[begin];
	i = begin;
	j = end;

	while (i < j){
		while (i<j && nums[j]>key)
			j--;

		while (i<j && nums[i]<=key)
			i++;

		if (i < j)
			swap(nums, i, j);
	}

	swap(nums, begin, j);

	return j;
}
//数组元素相同时，复杂度也为O(nlgn)
int partition_version2(int *nums, int begin, int end)
{
	int i, j, key;

	key = nums[begin];
	i = begin;
	j = end+1;

	while (i < j){
		do{
			j--;
		} while (i<j && nums[j]>key);

		do{
			i++;
		} while (i<j && nums[i]<key);

		if (i < j)
			swap(nums, i, j);
	}

	swap(nums, begin, j);

	return j;
}

void quick_sort(int *nums, int begin, int end)
{
	int i;

	if (begin >= end)
		return;

	i = partition_version2(nums, begin, end);

	quick_sort(nums, begin, i-1);
	quick_sort(nums, i+1,end);

}

#define LENGTH(v) sizeof(v)/sizeof(v[0])


int main()
{
	int nums[] = {5,9,1,6,2,9,10};
//	int nums[] = {1,1,1,1,2,2};
	int i;

	quick_sort(nums, 0, LENGTH(nums)-1);
//	qsort(nums, 0, LENGTH(nums)-1);

	for( i=0; i<LENGTH(nums); i++)
		printf("%d\t", nums[i]);

	printf("\n");
}
//2015-10-10 19:56:58
int quickSort(int* nums, int begin, int end) {
	int l, r, key;
	l = begin;
	r = end;
	key = nums[begin];
	while (l < r) {
		while (l < r && nums[r] > key) r--;
		while (l < r && nums[l] <= key) l++;
		if (l < r)	swap(nums, l, r);
	}
	swap(nums, begin, l);
	return l;
}
