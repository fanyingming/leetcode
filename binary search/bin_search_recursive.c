#include <stdio.h>
#include <assert.h>

int bin_search_recursive(int *array, int v, int l, int r){
	int m;
	int ret;

	m = l + (r-l)/2;//(l+r)/2;

	assert(l <= r);
	if (v == array[m])
		return m;
	if (v > array[m])
		ret = bin_search_recursive(array, v, m+1, r);
	else
		ret = bin_search_recursive(array, v, l, m-1);

	return ret;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7};

	int v = bin_search_recursive(a, 7, 0, sizeof(a)/sizeof(a[0]));

	printf("%d\n", v);
}