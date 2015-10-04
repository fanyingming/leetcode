class Solution {
public:
    void reverse(vector<int>& nums, int begin, int end) {
        int t, c;
        for (int i = begin, c = 0; i <= begin + (end-begin)/2; i++, c++) {
            t = nums[i]; nums[i] = nums[end-c]; nums[end-c] = t;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int i, j, t;
        if (nums.size() == 0 || nums.size() == 1)
            return;
        for (i = nums.size()-2; i >= 0; i--) {
            if (nums[i] < nums[i+1])
                break;
        }
        if (i == -1) {
            reverse(nums, 0, nums.size()-1);
            return;
        }
        int diff_min = 0x7fffffff;
        int min_index;
        for (j = i+1; j < nums.size(); j++) {
            int diff = nums[j] - nums[i]; 
            if (diff > 0 && diff < diff_min) {
                diff_min = diff;
                min_index = j;
            }
        }
        
        t = nums[i];nums[i] = nums[min_index]; nums[min_index] = t;
        sort(nums.begin() + i+1, nums.end());
    }
};