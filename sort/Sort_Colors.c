void swap(int* nums, int i, int j) {
    int t;
    t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}

void sortColors(int* nums, int numsSize) {
    int l = 0;
    int r = numsSize-1;
    int i = 0;
    while (i <= r) {
        if (nums[i] == 0) {
            swap(nums, i, l);
            l++;
            i++;//notice here. necessary, position l must be element equal to 1.
        } else if (nums[i] == 2){
            swap(nums, i, r);
            r--;
        } else {
            i++;
        }
    }
}

void sortColors_countSort(int* nums, int numsSize) {
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