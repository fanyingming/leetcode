#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define false 0
#define true 1
int dp_table[1000][2];

int max_my(int a, int b) {
	return a > b ? a : b;
}

int dp(int *nums, int numsSize, int i, int b_rob_cur) {
	int rob_yes;
	int rob_no;
	int max;

	if (i == -1)
		return 0;

	if (dp_table[i][b_rob_cur] != -1)
		return dp_table[i][b_rob_cur];

	rob_yes = nums[i] + dp(nums, numsSize, i - 1, 0);
	rob_no = max_my(dp(nums, numsSize, i - 1, 1), dp(nums, numsSize, i - 1, 0));

	if (b_rob_cur) {
		max = rob_yes;
	}
	else {
		max = rob_no;
	}

	dp_table[i][b_rob_cur] = max;

	return max;
}

int rob(int* nums, int numsSize) {
	int i, rv;
	if (nums == NULL || numsSize <= 0)
		return 0;
	for (i = 0; i < numsSize; i++)
		dp_table[i][0] = dp_table[i][1] = -1;
	rv = max_my(dp(nums, numsSize, numsSize - 1, 1), dp(nums, numsSize, numsSize - 1, 0));

	if (rv < 0)
		return 0;
	return rv;
}
/*
int main() {
	int nums[2] = { 1, 1 };

	int rv = rob(nums, 2);
	printf("%d\n", rv);
}
*/
