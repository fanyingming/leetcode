#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define INFINITE 0x7FFFFFFF

void merge_version1(int *arr, int begin, int m, int end)
{
	int *t = malloc((end - begin + 1)*sizeof(int));
	int length = end-begin+1;
	int i, j, k;

	assert(begin<=m && m<end);

	j = begin;
	k = m+1;
	for (i = 0; i < length; i++){
		//invariant: t[0, i] sorted.
		if (j <= m && k <= end){
			if (arr[j] <= arr[k]){
				t[i] = arr[j];
				j++;
			} else {
				t[i] = arr[k];
				k++;
			}
		} else {
			int l;
			if (j > m)
				for (l = i; l<length; l++)
					t[l] = arr[k++];
			else
				for (l = i; l<length; l++)
					t[l] = arr[j++];
			break;
		}
	}

	j = 0;
	for (i = begin; i <= end; i++, j++){
		arr[i] = t[j];
	}

	free(t);
}

void merge_version2(int *arr, int begin, int m, int end)
{
	int *left, *right;
	int i, j, k;
	int l_size, r_size, arr_size;

	l_size = m-begin+1;
	r_size = end-m;
	arr_size = end-begin+1;

	left = malloc((l_size+1)*sizeof(int));//注意，要多分配一个空间来存放哨兵值。
	right= malloc((r_size+1)*sizeof(int));

	memcpy(left,  arr+begin, l_size*sizeof(int));
	memcpy(right, arr+m+1,   r_size*sizeof(int));

	left[l_size] = right[r_size] = INFINITE;

	j = k = 0;
	for (i=begin; i<=end; i++){//注意i的下表赋值，不是从0开始。
		if (left[j] <= right[k]){
			arr[i] = left[j];
			j++;
		}else{
			arr[i] = right[k];
			k++;
		}
	}

	free(left);
	free(right);
}

void merge_sort(int *arr, int begin, int end)
{
	int m;
	assert(arr);

	if (end <= begin)
		return;

	m = (begin+end)/2;

	merge_sort(arr, begin, m);
	merge_sort(arr, m+1, end);
	merge_version2(arr, begin, m, end);
}

#define LENGTH(v) sizeof(v)/sizeof(v[0])


int main()
{
	int nums[] = {5,9,1,6,2,9,10};
	int i;

	merge_sort(nums, 0, LENGTH(nums)-1);
//	qsort(nums, 0, LENGTH(nums)-1);

	for( i=0; i<LENGTH(nums); i++)
		printf("%d\t", nums[i]);

	printf("\n");
}