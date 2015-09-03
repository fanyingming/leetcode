/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool DFS(struct TreeNode* root, int sum, int cur) {
    if (!root)
        return false;
    if (!root->left && !root->right) {//leaf node.
        if (cur + root->val == sum)
            return true;
        else
            return false;
    }

    return DFS(root->left, sum, cur + root->val) || DFS(root->right, sum, cur + root->val);
} 
bool hasPathSum(struct TreeNode* root, int sum) {
    return DFS(root, sum, 0);
}