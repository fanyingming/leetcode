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
    int num;
    int sum;
    void dfs(TreeNode* root) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            num = num*10 + root->val;
            sum += num;
            num = num/10;
            return;
        }
        num = num*10 + root->val;
        if (root->left)
            dfs(root->left);
        if (root->right)
            dfs(root->right);
        num = num/10;
    }

    int sumNumbers(TreeNode* root) {
        num =sum = 0;
        dfs(root);
        return sum;
    }
};