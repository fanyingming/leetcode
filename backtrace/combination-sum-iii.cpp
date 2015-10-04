vector< vector<int> > return_list;

int vector_sum(vector<int>& nums) {
    int sum = 0;
    
    for (int i = 0; i < nums.size(); i++)
        sum += nums.at(i);
    return sum;
}

int is_a_solution(vector<int>& nums, int k, int n) {
    if (nums.size() == k && vector_sum(nums) == n)
        return true;
    else
        return false;
}

void process_solution(vector<int>& nums) {
    return_list.push_back(nums);    
}

void construct_cand(vector<int>& nums,int k, int n, vector<int>& cand) {
    int nums_len = nums.size();
    int max;
    
    if (nums_len > k)//end backtrace.
        return;
    if (vector_sum(nums) >= n)//pruning.
        return;
        
    if (nums_len == 0)
        max = 0;
    else
        max = nums.at(nums_len-1);
    
    for (int i = max+1; i <= 9; i++)
            cand.push_back(i);
    
}

void backtrack(vector<int>& nums,int k, int n) {
    if (is_a_solution(nums, k ,n ))
        process_solution(nums);
    else {
        vector<int> cand;
        construct_cand(nums, k, n, cand);
        for (int i = 0; i < cand.size(); i++) {
            nums.push_back(cand.at(i));
            backtrack(nums, k, n);
            nums.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        return_list.clear();
        backtrack(nums, k, n);
        return return_list;
    }
};