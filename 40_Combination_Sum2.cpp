#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<int> > return_list;

static inline int get_vector_sum(vector<int>& nums, vector<int>& input) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums.at(i) == 1)
            sum += input.at(i);
    return sum;
}

static inline vector<int> get_num_vector(vector<int>& nums, vector<int>& input) {
    vector<int> v;
    for (int i = 0; i < nums.size(); i++)
        if (nums.at(i) == 1)
            v.push_back(input.at(i));
    return v;
}

static inline bool is_a_solution(vector<int>& nums, int target, vector<int>& input) {
    int sum = get_vector_sum(nums, input);
    
    if (sum == target) {
        return_list.push_back(get_num_vector(nums, input));
        return true;
    } else if (sum > target || nums.size() >= input.size()) {
        return true;//return true to end backtrack.
    } else {
        return false;
    }
}

void construct_cand(vector<int>& nums, vector<int>& input, vector<int>& c) {
    c.clear();
    if (nums.size()-1 >= 0 && nums.size() < input.size()) {
        int left_pos = nums.size()-1;
        if (input.at(left_pos+1) == input.at(left_pos) && nums.at(left_pos) == 0) {
            c.push_back(0);
            return;
        }
    }
    c.push_back(1);
    c.push_back(0);
}

void backtrack(vector<int>& nums, vector<int>& input, int target) {
    if (is_a_solution(nums, target, input))
        return;
    else {
        vector<int> c;
        construct_cand(nums, input, c);
        for (int i = 0; i< c.size(); i++) {
            nums.push_back(c.at(i));
            backtrack(nums, input, target);
            nums.pop_back();
        }
    }
}

class Solution {
public:
    vector< vector<int> > combinationSum2(vector<int>& candidates, int target) {
        return_list.clear();
        vector<int> nums;
        
        sort(candidates.begin(), candidates.end());
        backtrack(nums, candidates, target);
        
        return return_list;
    }
};

int main() {
    Solution obj;
    vector<int> nums;
    vector< vector<int> > rv;

    nums.push_back(10);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(5);
    rv = obj.combinationSum2(nums, 8);
    
    for (int i = 0; i < rv.size();i++) {
        for (int j = 0; j < rv.at(i).size(); j++)
            cout<<rv.at(i).at(j)<<" ";
        cout<<endl;
    }
}

