/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool DFS(struct TreeNode* root, int sum, int cur) {
    if (!root->left && !root->right) {//leaf node.
        if (cur + root->val == sum)
            return true;
        else
            return false;
    }
    
    if (root->left)
        if (DFS(root->left, sum, cur + root->val))
            return true;
    if (root->right)
        if (DFS(root->right, sum, cur + root->val))
            return true;

    return false;
} 
bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL)
        return false;
    return DFS(root, sum, 0);
}