class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int index = 0;
        if (len == 0)
        	return 0;
        for (int i = 1; i < nums.size(); i++) {
        	if (nums[index] != nums[i])
        		nums[++index] = nums[i];
        }
        return index+1;
    }
};