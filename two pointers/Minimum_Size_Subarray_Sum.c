class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int min_length = INT_MAX;
        int begin_index = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                min_length = min(min_length, i-begin_index+1);
                sum -= nums[begin_index];
                begin_index++;
            }
        }
        
        return min_length == INT_MAX ? 0 : min_length;
    }
};