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
    void flatten(TreeNode* root) {
    	stack<TreeNode*> sta;
    	TreeNode preNode(0);
    	TreeNode* h;
    	TreeNode* pre;
    	if (root == NULL)
    		return;

    	pre = &preNode;
    	sta.push(root);
    	while (sta.empty() == false) {
    		h = sta.top();
    		sta.pop();
    		if (h->right)
    			sta.push(h->right);
    		if (h->left)
    			sta.push(h->left);
    		pre->left = NULL;
    		pre->right= h;
    		pre = h;
    	}
    	pre->left = pre->right = NULL;
    }
};