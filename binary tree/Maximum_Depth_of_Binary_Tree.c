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
    int maxDepth(TreeNode* root) {
        if (root == NULL)   
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        int leftDepth = 0;
        int rightDepth= 0;

        if (root->left)
            leftDepth = maxDepth(root->left);
        if (root->right)
            rightDepth= maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
};