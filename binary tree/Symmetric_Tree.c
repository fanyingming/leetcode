/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode* h1, struct TreeNode* h2) {
	if (!h1 && !h2)
		return true;
	if (!h1 || !h2)
		return false;
	if (h1->val != h2->val)
		return false;
	return helper(h1->left, h2->right) && helper(h1->right, h2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root)
    	return true;
    return helper(root->left, root->right);
}