#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> return_list;

int is_a_solution(vector<int>& nums, vector<int>& input) {
    return nums.size() == input.size();
}

void process_silution(vector<int>& nums) {
    return_list.push_back(nums);
}

void construct_cand(vector<int>& nums, vector<int>& input, vector<int>& c, int *ncand) {
    c.clear();
    (*ncand) = 0;
    
    for (int i = 0; i < input.size(); i++) {
        input_v = input.at(i);
        
        for ( int j = 0; j < nums.size(); j++) {
            if (nums.at(j) == input_v)
                break;
        }
        
        if (j == nums.size()) {
            c.push_back(input_v);
            (*ncand)++;
        }
    }
}

void backtrack(vector<int>& nums, vector<int>& input) {
    vector<int> c;
    int ncand;
    int i;
    
    if(is_a_solution(nums, input))
        process_solution(nums);
    else {
        construct_cand(nums, input, &c, &ncand);
        for (i = 0; i< ncand; i++) {
            nums.push_back(c[i]);
            backtrack(nums, k, input);
            nums.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& input) {
        return_list.clear();
        vector<int> nums;
        nums.clear();
        backtrack(&nums, input);
        
        return return_list;
    }
};

int main() {
	Solution obj;
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);

	vector<int>
}