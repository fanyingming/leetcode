class Solution {
public:
    vector<vector<int>> return_list;

    int get_true_count(vector<int>& nums)  {
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++)
            count += nums.at(i);
        
        return count;
    }
    
    int is_a_solution(vector<int>& nums, int n, int k) {
        return get_true_count(nums) == k ? true : false;
    }
    
    int process_solution(vector<int>& nums) {
        vector<int> v;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == 1)
                v.push_back(i+1);
        }
        
        return_list.push_back(v);
    }
    
    void construct_cand(vector<int>& nums, int n, int k, vector<int>& c) {
        c.clear();
        if (nums.size() == n)
            return;
        c.push_back(1);
        c.push_back(0);
    }
    
    void backtrack(vector<int>& nums, int n, int k) {
        if (is_a_solution(nums, n, k))
            process_solution(nums);
        else {
            vector<int> c;
            construct_cand(nums, n, k, c);
            for (int i = 0; i < c.size(); i++) {
                nums.push_back(c.at(i));
                backtrack(nums, n, k);
                nums.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        backtrack(nums, n, k);
        return return_list;
    }
};