class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int resSum;
        if (nums.size() < 3)    return 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int l = i+1;
            int r = nums.size()-1;
            while (l < r) {
            	int sum = nums[i] + nums[l] + nums[r];
            	if (i == 0 && l == 1 && r == nums.size()-1)
            		resSum = sum;
            	else if (abs(sum-target) < abs(resSum-target))
            		resSum = sum;
                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    while (r-1 > l && nums[r] == nums[r-1])
                        r--;
                    r--;
                } else {
                    while (l+1 < r && nums[l] == nums[l+1])
                        l++;
                    l++;
                }
            }
            while (i+1 < nums.size()-1 && nums[i] == nums[i+1])
                i++;
        }
        return resSum;
    }
};