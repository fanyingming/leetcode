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
    vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> res, reversed;

		if (root == NULL)	return res;

		s.push(root);
		while (!s.empty()) {
			TreeNode *node = s.top();
			s.pop();
			res.push_back(node->val);
			if (node->left)
				s.push(node->left);
			if (node->right)
				s.push_back(node->right);
		}
		for (int i = res.size()-1; i >= 0; i--)
			reversed.push_back(res[i]);
		return reversed;
    }
};