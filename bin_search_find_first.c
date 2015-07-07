#include <stdio.h>

int bin_search_find_first(int *array, size_t length, int v){
	int l, m, r;

	l = 0;
	r = length-1;

	while(l <= r){
		m = (l+r)/2;

		if(array[m] == v){
			if(m == 0)
				return m;
			if(array[m-1] != v)
				return m;
			else
				r = m-1;
		}else if(v > array[m]){
			l = m+1;
		}else{
			r = m-1;
		}
	}

	return -1;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 4, 4, 4, 4, 5, 6, 7};

	int v = bin_search_find_first(a, sizeof(a)/sizeof(a[0]), 4);

	printf("%d\n", v);
}