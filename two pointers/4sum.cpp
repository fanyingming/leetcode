class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rl;
        
        if (nums.size() < 4)
            return rl;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size()-3; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            for (int j = i+1; j < nums.size()-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1])
                    continue;
                int l = j+1;
                int r = nums.size()-1;
                
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        rl.push_back(v);
                        while (l < r && nums[l] == nums[l+1]) l++;
                        while (l < r && nums[r] == nums[r-1]) r--;
                        l++;r--;
                    } else if (sum > target) {
                        while (l < r && nums[r] == nums[r-1]) r--;
                        r--;
                    } else {
                        while (l < r && nums[l] == nums[l+1]) l++;
                        l++;
                    }
                }
            }
        }
        return rl;
    }
};