class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin, end;
        int l, r, m;
        int left, right;
        begin = end = -1;
        left = l = 0;
        right = r = nums.size()-1;
        while (l <= r) {
            m = l + (r-l)/2;
            if (nums[m] < target) {
                left = l = m+1;
            } else if (nums[m] > target) {
                right = r = m-1;
            } else {
                break;
            }
        }
        l = left;
        r = m;
        while (l <= r) {
            m = l + (r-l)/2;
            if (nums[m] < target) {
                l = m+1;
            } else if (nums[m] > target) {
                r = m-1;
            } else {
                begin = m;
                r = m-1;
            }
        }
        l = m;
        r = right;
        while (l <= r) {
            m = l + (r-l)/2;
            if (nums[m] < target) {
                l = m+1;
            } else if (nums[m] > target) {
                r = m-1;
            } else {
                end = m;
                l = m+1;
            }
        }
        vector<int> res;
        res.push_back(begin);
        res.push_back(end);
        return res;
    }
};