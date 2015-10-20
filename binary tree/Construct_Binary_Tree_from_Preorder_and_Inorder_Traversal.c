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
    int preIndex;
    TreeNode* build(vector<int>& inorder, vector<int>& preorder, int left, int right) {
        if (left > right)
            return NULL;
        int i;
        for (i = left; i <= right; i++)
            if (inorder[i] == preorder[preIndex])
                break;
        preIndex++;
        TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
        node->val = inorder[i];
        node->left  = build(inorder, preorder, left, i-1);
        node->right = build(inorder, preorder, i+1, right);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() != preorder.size()) return NULL;
        preIndex = 0;
        return build(inorder, preorder, 0, preorder.size()-1);
    }
};