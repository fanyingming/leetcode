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
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> res;
		TreeNode* p;

		if (root == NULL)	return res;
		p = root;
		while (!s.empty() || p != NULL) {
			if (p) {
				s.push(p);
				p = p->left;
			} else {
				TreeNode* node = s.top();
				s.pop();
				res.push_back(node->val);
				p = node->right;
			}
		}
		return res;
	}
};