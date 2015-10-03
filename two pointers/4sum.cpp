vector<vector<int>> rl;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        rl.clear();
        int i, j;
        int l, r;
        int sum;
        
        if (nums.size() < 4)
            return rl;
        
        sort(nums.begin(), nums.end());
        
        for (i = 0; i < nums.size()-3; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            for (j = i+1; j < nums.size()-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1])
                    continue;
                l = j+1;
                r = nums.size()-1;
                
                while (l < r) {
                    sum = nums[i] + nums[j] + nums[l] + nums[r];
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
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        
        return rl;
    }
};