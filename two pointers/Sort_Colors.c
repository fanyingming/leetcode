class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int index = 0;
        while (l <= r && index <= r) {
            if (nums[index] == 0) {
                swap(nums[index], nums[l]); l++; index++;
            } else if (nums[index] == 2) {
                swap(nums[index], nums[r]); r--;
            } else {
                index++;
            }
        }
    }
};