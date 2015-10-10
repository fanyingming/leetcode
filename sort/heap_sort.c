#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define HEAP_MAX_SIZE 100
/*
** 对于一个给定的数组（数组下表从1开始，为了方便找节点的左右子节点），堆排序的做法是：
** 1. 建堆：从n/2个节点一直到root节点，调用max_heapify，对一个节点和他的子节点进行比较，最大值放上边；
** 2. 从数组最后一个开始，每次把顶端元素和最后一个元素替换，最大堆的结果得到从小到大的排序。
*/
typedef struct heap{
	int arr[HEAP_MAX_SIZE];
	int length;
}heap;

void swap(int *arr, int i, int j)
{
	int t;
	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}
//前提是，h.arr[i]的左右子树都是最大堆。
void max_heapify(heap *h, int i)
{
	int l = i*2;
	int r = i*2+1;
	int max;
	int t;

	if (i >= h->length)
		return;

	max = i;
	//三个数中选择最小的数，第一次写的版本是有bug得，值得注意。
	if (l <= h->length && h->arr[l] > h->arr[i])
		max = l;
	if (r <= h->length && h->arr[r] > h->arr[max])
		max = r;

	if (max == i)
		return;
	//swap max and i node.
	t = h->arr[i];
	h->arr[i] = h->arr[max];
	h->arr[max] = t;

	max_heapify(h, max);
}

void build_max_heap(heap *h)
{
	int i;

	for (i = h->length/2; i>=1; i--){
		max_heapify(h, i);
	}
}

void heap_sort(int *arr, int n)
{
	heap *h = malloc(sizeof(heap));
	int i;

	for (i = 1; i <= n; i++)
		h->arr[i] = arr[i-1];
	h->length = n;

	build_max_heap(h);

	for (i = n; i >=2; i--){
		int t;

		t = h->arr[1];
		h->arr[1] = h->arr[i];
		h->arr[i] = t;

		h->length--;
		max_heapify(h, 1);
	}

	for (i = 1; i <= n; i++)
		arr[i-1] = h->arr[i];
	
	free(h);
}

#define LENGTH(v) sizeof(v)/sizeof(v[0])


int main()
{
	int nums[] = {5,9,1,6,2,9,10};
//	int nums[] = {1,1,1,1,1};
	int i;

	heap_sort(nums, LENGTH(nums));
//	qsort(nums, 0, LENGTH(nums)-1);

	for( i=0; i<LENGTH(nums); i++)
		printf("%d\t", nums[i]);

	printf("\n");
}