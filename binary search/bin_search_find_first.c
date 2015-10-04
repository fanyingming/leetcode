int bin_search_find_first(int *array, size_t length, int v){
	int l, m, r;

	l = 0;
	r = length-1;

	while (l <= r){
		m = l + (r-l)/2;//(l+r)/2;

		if (array[m] == v) {
			if(m == 0)
				return m;
			if(array[m-1] != v)
				return m;
			else
				r = m-1;
		} else if (v > array[m]){
			l = m+1;
		} else {
			r = m-1;
		}
	}

	return -1;
}