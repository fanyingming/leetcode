/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
vector<vector<int>> rl;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        rl.clear();
        int i, l, r;
        int numsSize = nums.size();
        int sum;
        
        if (numsSize < 3)
            return rl;
        
        sort(nums.begin(), nums.end());
        
        for (i = 0; i < numsSize-2; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
             
            l = i+1;
            r = numsSize-1;
            while (l < r) {
                sum = -nums[i];
                if (nums[l] + nums[r] == sum) {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[r]);
                    rl.push_back(v);
                    while (l < r && nums[l] == nums[l+1])
                        l++;
                    while (l < r && nums[r] == nums[r-1])
                        r--;
                    l++;
                    r--;
                } else if (nums[l] + nums[r] < sum) {
                    while (l < r && nums[l] == nums[l+1])
                        l++;
                    l++;
                } else {
                    while (l < r && nums[r] == nums[r-1])
                        r--;
                    r--;
                }
            }
        }
        return rl;
    }
};
