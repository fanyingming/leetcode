class Solution {
public:
    vector<vector<int>> return_list;

    void construct_cand(vector<int>& nums, vector<int>& status, vector<vector<int>>& c) {
        int begin_pos = status.size();
        int length = 1;
        //find same elements.
        for (int i = begin_pos+1; i < nums.size(); i++) {
            if (nums[begin_pos] == nums[i])
                length++;
            else
                break;
        }
        //eg. 3 same elements.
        //000 100 110 111
        for (int i = 0; i <= length; i++) {
            vector<int> tmp;
            for (int j = 1; j <= i; j++)
                tmp.push_back(1);
            for (int j = i+1; j <= length; j++)
                tmp.push_back(0);
            c.push_back(tmp);
        }
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
            vector<vector<int>> c;
            construct_cand(nums, status, c);
            for (int i = 0; i < c.size(); i++) {
                for (int j = 0; j < c[i].size(); j++)
                    status.push_back(c[i][j]);
                backtrack(nums, status);
                for (int j = 0; j < c[i].size(); j++)
                    status.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) {
            vector<vector<int>> t;
            return t;
        }

        vector<int> status;
        sort(nums.begin(), nums.end());
        backtrack(nums, status);
        return return_list;
    }
};