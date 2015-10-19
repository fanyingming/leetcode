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
    int minDepth(TreeNode* root) {
    	if (root == NULL)
    		return 0;
    	if (root->left == NULL && root->right == NULL)
    		return 1;
    	int leftDepth = 0;
    	int rightDepth= 0;
    	
    	if (root->left && root->right) {
    	    leftDepth = minDepth(root->left);
    	    rightDepth = minDepth(root->right);
    	    return min(leftDepth, rightDepth) + 1;
    	}
    	
    	if (root->left)
    		return leftDepth = minDepth(root->left)+1;

    	if (root->right)
    		return rightDepth = minDepth(root->right)+1;
    }
};