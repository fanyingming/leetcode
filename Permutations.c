class Solution {
public:
    vector<vector<int>> return_list;

    void construct_cand(vector<int>& nums, vector<int>& input, vector<int>& c) {
        int i, j;
        c.clear();
        
        for (i = 0; i < input.size(); i++) {
            int input_v = input.at(i);
            
            for (j = 0; j < nums.size(); j++) {
                if (nums.at(j) == input_v)
                    break;
            }
            
            if (j == nums.size())
                c.push_back(input_v);
        }
    }
    
    void backtrack(vector<int>& nums, vector<int>& input) {
        if (nums.size() == input.size()) {
            return_list.push_back(nums);
        } else {
            vector<int> c;
            construct_cand(nums, input, c);
            for (int i = 0; i< c.size(); i++) {
                nums.push_back(c.at(i));
                backtrack(nums, input);
                nums.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& input) {
        return_list.clear();
        vector<int> nums;
        backtrack(nums, input);
        return return_list;
    }
};