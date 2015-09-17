class Solution {
public:
    vector< vector<int> > return_list;

    void backtrack(vector<int>& nums, vector<int>& used, vector<int>& input) {
        if (nums.size() == input.size()) {
            return_list.push_back(nums);
        }
        else {
            for (int i = 0; i< input.size(); i++) {
                if (i > 0 && used[i-1] == 0 && input[i] == input[i - 1])
                    continue;
                if (used[i] == 0) {
                    nums.push_back(input.at(i)); used[i] = 1;
                    backtrack(nums, used, input);
                    nums.pop_back(); used[i] = 0;
                }
            }
        }
    }

    vector< vector<int> > permute(vector<int>& input) {
        return_list.clear();
        vector<int> nums;
        vector<int> used;
        sort(input.begin(), input.end());
        for (int i = 0; i < input.size(); i++)
            used.push_back(0);
        backtrack(nums, used, input);
        return return_list;
    }
};