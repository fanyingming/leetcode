/*
** 旧方法需要遍历有三个循环，一个循环找到target，另外2个分别找到形同数的最左边以及最右边。
** 新方法是只需2个循环，一次找到target及左边，另一次找最右边。
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin, end, right, middle;
        int l, r, m;
        middle = begin = end = right = -1;
        l = 0;
        r = nums.size()-1;

        while (l <= r) {
            m = l + (r-l)/2;
            if (nums[m] > target) {
                r = m-1;
            } else if (nums[m] < target) {
                l = m+1;
            } else {
                if (right == -1) {
                    right = r;
                    middle = m;
                }
                begin = m;
                r = m-1;
            }
        }
        l = middle;
        r = right;
        while (l <= r) {
            m = l + (r-l)/2;
            if (nums[m] > target) {
                r = m-1;
            } else if (nums[m] < target) {
                l = m+1;
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