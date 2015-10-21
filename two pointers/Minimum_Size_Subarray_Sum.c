class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = INT_MAX;
        int sum = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                minLen = min(minLen, i-index+1);
                sum -= nums[index++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};