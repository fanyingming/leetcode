class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> htable;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++)
            htable[nums[i]].push_back(i);

        for (int i = 0; i < nums.size(); i++) {
            htable[nums[i]].erase(htable[nums[i]].begin());
            int num = target - nums[i];
            if (htable.find(num) == htable.end() || htable[num].size() == 0)
                continue;

            int index = htable[num].at(0);
            res.push_back(i+1);
            res.push_back(index+1);
            return res;
        }
    }
};