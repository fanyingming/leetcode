#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;
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

    vector< vector<int> > permuteUnique(vector<int>& input) {
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

int main() {
    Solution sol;
    vector<int> input;
    input.push_back(1); input.push_back(1); input.push_back(2);
    vector< vector<int> > rl = sol.permuteUnique(input);
    for (int i = 0; i < rl.size(); i++) {
        for (int j = 0; j < rl.at(i).size(); j++) {
            cout << rl.at(i).at(j) << " ";
        }
        cout << endl;
    }
}