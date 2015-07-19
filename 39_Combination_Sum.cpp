#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<int> > return_list;

int get_vector_sum(vector<int>&nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums.at(i);
    return sum;
}

bool is_a_solution(vector<int>&nums, int target) {
    int sum = get_vector_sum(nums);
    
    if (sum == target) {
        return_list.push_back(nums);
        return true;
    } else if (sum > target) {
        return true;//return true to end backtrack.
    } else {
        return false;
    }
}

void process_solution() {
    return;
}

void construct_cand(vector<int>& nums, vector<int>& input, int target, vector<int>& c) {
    c.clear();
    int max_num;
    if (nums.size() > 0)
        max_num = nums.at(nums.size()-1);
    else
        max_num = 0;
    for (int i = 0; i < input.size(); i++) {
        int value = input.at(i);
        if (value >= max_num)
            c.push_back(value);
    }
}

void backtrack(vector<int>& nums, vector<int>& input, int target) {
    if (is_a_solution(nums, target))
        process_solution();
    else {
        vector<int> c;
        construct_cand(nums, input, target, c);
        for (int i = 0; i< c.size(); i++) {
            nums.push_back(c.at(i));
            backtrack(nums, input, target);
            nums.pop_back();
        }
    }
}

class Solution {
public:
    vector< vector<int> > combinationSum(vector<int>& input, int target) {
        return_list.clear();
        vector<int> nums;
        
        sort(input.begin(), input.end());
        backtrack(nums, input, target);
        
        return return_list;
    }
};

int main() {
    Solution obj;
    vector<int> nums;
    vector< vector<int> > rv;

    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
    rv = obj.combinationSum(nums, 7);
    
    for (int i = 0; i < rv.size();i++) {
        for (int j = 0; j < rv.at(i).size(); j++)
            cout<<rv.at(i).at(j)<<" ";
        cout<<endl;
    }
}