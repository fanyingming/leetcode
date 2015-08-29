/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <limits.h>
#include <stdint.h>
bool recursive_old(struct TreeNode* root, int64_t min, int64_t max) {
    bool bl, br;
    bl = br = true;
    if (!root) return true;
    if (root->left) {
        if (root->left->val >= root->val || root->left->val <= min || root->left->val >= max)
            return false;

        bl = recursive(root->left, min, root->val);
        if (!bl)
            return false;
    }
    if (root->right) {
        if (root->right->val <= root->val || root->right->val <= min || root->right->val >= max)
            return false;

        br = recursive(root->right, root->val, max);
    }
    if (bl == true && br == true)
        return true;
    else
        return false;
}


bool recursive_new(struct TreeNode* root, int64_t min, int64_t max) {
    if (!root) return true;

    if (root->val <= min || root->val >= max)   return false;

    return recursive(root->left, min, root->val) && recursive(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return recursive_new(root, LLONG_MIN, LLONG_MAX);
}
