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
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftHeight = 0, rightHeight = 0;
        TreeNode* h = root->left;
        while (h) {
            leftHeight++;
            h = h->left;
        }
        h = root->right;
        while (h) {
            rightHeight++;
            h = h->right;
        }
        if (leftHeight == rightHeight)
            return pow(2, leftHeight+1)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};