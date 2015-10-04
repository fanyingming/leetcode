class Solution {
public:
    vector<vector<int>> return_list;

    void construct_cand(vector<int>& nums, vector<int>& status, vector<int>& c) {
        if (status.size() == nums.size())
            return;
        c.push_back(0);
        c.push_back(1);
    }
    
    void backtrack(vector<int>& nums, vector<int>& status) {
        if (nums.size() == status.size()) {
            vector<int> v;
            for (int i = 0; i < status.size(); i++) {
                if (status.at(i) == 1)
                    v.push_back(nums.at(i));
            }
            return_list.push_back(v);
        } else {
            vector<int> c;
            construct_cand(nums, status, c);
            for (int i = 0; i < c.size(); i++) {
                status.push_back(c.at(i));
                backtrack(nums, status);
                status.pop_back();
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> status;
        sort(nums.begin(), nums.end());
        backtrack(nums, status);
        return return_list;
    }
};