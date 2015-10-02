void sortColors(int* nums, int numsSize) {
    int i, j, k;
	int count[3] = {0,0,0};

	for( i=0; i<numsSize; i++ ){
		count[nums[i]]++;
	}

	i = 0;
	for( k=0; k<3; k++)
		for( j=0; j<count[k]; j++, i++)
			nums[i] = k;
}