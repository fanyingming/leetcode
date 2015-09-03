/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> tmpVector;
    vector<vector<int>> rl;
    
    void DFS(TreeNode* root, int sum) {
        if (!root)  return;
        tmpVector.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum == root->val)   rl.push_back(tmpVector);
            tmpVector.pop_back();
            return;
        }
        
        DFS(root->left, sum-root->val);
        DFS(root->right, sum-root->val);
        tmpVector.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        tmpVector.clear();
        rl.clear();
        DFS(root, sum);
        return rl;
    }
};