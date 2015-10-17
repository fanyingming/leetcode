/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 ** 规律是：
 ** 1. 如果调换的位置不挨着，则调换第一个位置的first和第二个位置的second；
 ** 2. 如果调换的位置挨着，则调换他们就行。
 ** 这个规律是关键，不容易想到。
 */
class Solution {
public:
    TreeNode* p1;
    TreeNode* p2;
    TreeNode* pre;
    
    void inorderTraverse(TreeNode* root) {
        if (root->left)
            inorderTraverse(root->left);
            
        if (pre) {
            if (p1 == NULL && root->val < pre->val) {
                p1 = pre;
                p2 = root;
            } else if (p1 && root->val < pre->val) {
                p2 = root;
                return;
            }
        }
        pre = root;
        
        if (root->right)
            inorderTraverse(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        pre = p1 = p2 = NULL;
        inorderTraverse(root);
        int t = p1->val;
        p1->val = p2->val;
        p2->val = t;
    }
};