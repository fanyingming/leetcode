int removeDuplicates(int* nums, int numsSize) {
    int l, r;
	if (nums == NULL || numsSize == 0)
		return 0;
	l = r = 0;
	while (r < numsSize) {
		if (nums[l] == nums[r]) {
			r++;
		} else {
			nums[++l] = nums[r];
			r++;
		}
	}

	return l + 1;
}
