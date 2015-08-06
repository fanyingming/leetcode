int removeDuplicates(int* nums, int numsSize) {
	int l, r;
	int same_count = 1;

	if (nums == NULL || numsSize == 0)
		return 0;
	if (nums == 1)
		return 1;
	l = 0;
	r = 1;
	while (r < numsSize) {
		if (nums[l] == nums[r]) {
			if (same_count >= 2) {
				r++;
			} else {
				nums[++l] = nums[r];
				r++;
				same_count++;
			}
		} else {
			nums[++l] = nums[r];
			r++;
			same_count = 1;
		}
	}

	return l + 1;
}
