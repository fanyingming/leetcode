class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rl;
        if (nums.size() < 3)    return rl;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int l = i+1;
            int r = nums.size()-1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    vector<int> v;
                    v.push_back(nums[i]);v.push_back(nums[l]);v.push_back(nums[r]);
                    rl.push_back(v);
                    while (l+1 < r && nums[l] == nums[l+1])
                        l++;
                    while (r-1 > l && nums[r] == nums[r-1])
                        r--;
                    l++;r--;
                } else if (nums[i] + nums[l] + nums[r] > 0) {
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
        return rl;
    }
};