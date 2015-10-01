/*
** 位置index能积累的水与2个因素有关，其左边最高的墙高度，右边最高的墙高度，以及当前位置墙的高度。
** sum += min(left_max, right_max) - height[i]
*/

class Solution {
public:
	vector<int> vl;
	int trap(vector<int>& height) {
		if (height.size() == 0)
			return 0;
		int sum = 0;
		int max = height[0];
		int *left_max = (int *)malloc(sizeof(int)*height.size());
		int *right_max = (int *)malloc(sizeof(int)*height.size());
		
		for (int i = 1; i < height.size(); i++) {
			if (height[i] > max)
				max = height[i];
			left_max[i] = max;
		}

		max = height[height.size() - 1];
		for (int i = height.size() - 2; i >= 0; i--) {
			if (height[i] > max)
				max = height[i];
			right_max[i] = max;
		}

		for (int i = 1; i < height.size() - 1; i++) {
			sum += min(left_max[i], right_max[i]) - height[i];
		}
		free(left_max);
		free(right_max);
		return sum;
	}
};