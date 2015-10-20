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
	bool judge(TreeNode* root, long long minNum, long long maxNum) {
		if (root == NULL)
        	return true;
        if (root->val >= maxNum || root->val <= minNum)
        	return false;
        if (root->left && root->val <= root->left->val)
        	return false;
        if (root->right && root->val >= root->right->val)
        	return false;
        return judge(root->left, minNum, root->val) && judge(root->right, root->val, maxNum);
	}
    bool isValidBST(TreeNode* root) {
    	return judge(root, LLONG_MIN, LLONG_MAX);
    }
};