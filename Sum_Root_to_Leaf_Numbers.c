/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int>> vlist;

void DFS(TreeNode* root, vector<int>& rem) {
    if (!root) return;
    rem.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
        vlist.push_back(rem);
        rem.pop_back();
        return;
    }
    
    DFS(root->left, rem);
    DFS(root->right,rem);    
    rem.pop_back();
}

int vector_sum(vector<vector<int>>& input) {
    int i;
    int sum = 0;
    for (i = 0; i < input.size(); i++) {
        int value = 0;
        int j;
        for (j = 0; j < input.at(i).size(); j++)
            value = value*10 + input.at(i)[j];
        sum += value;
    }
    return sum;
}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<int> nums;
        vlist.clear();
        nums.clear();
        DFS(root, nums);
        return vector_sum(vlist);
    }
};