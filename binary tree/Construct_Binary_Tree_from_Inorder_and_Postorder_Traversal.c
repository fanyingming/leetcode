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
    int postIndex;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right)
            return NULL;
        int i;
        for (i = left; i <= right; i++)
            if (inorder[i] == postorder[postIndex])
                break;
        postIndex--;
        TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
        node->val = inorder[i];
        node->right = build(inorder, postorder, i+1, right);
        node->left  = build(inorder, postorder, left, i-1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return NULL;
        postIndex = postorder.size()-1;
        return build(inorder, postorder, 0, postIndex);
    }
};