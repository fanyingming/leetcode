/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inverse(struct TreeNode* head) {
    if (head == NULL)
        return;
    else {
        struct TreeNode* t;
        
        t = head->left;
        head->left = head->right;
        head->right = t;
        
        if (head->left)
            inverse(head->left);
        if (head->right)
            inverse(head->right);
    }
}

struct TreeNode* invertTree(struct TreeNode* root) {
    inverse(root);
    return root;
}