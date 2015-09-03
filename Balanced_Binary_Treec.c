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
    int helper(TreeNode* root) {
        int depth_left, depth_right;
        if (!root)
            return 0;
        depth_left = helper(root->left);
        depth_right= helper(root->right);
        if (depth_left < 0 || depth_right < 0)
            return -1;
        if (abs(depth_left - depth_right) > 1)
            return -1;
        return max(depth_left, depth_right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (helper(root) >= 0)
            return true;
        else 
            return false;
    }
};