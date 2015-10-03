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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q[2];
		int index = 0;
		vector<vector<int>> res;

		if (root == NULL)
			return res;

		q[index].push(root);

		while (q[index].size() != 0) {
			vector<int> tmp;
			while(q[index].size() != 0) {
				TreeNode * node = q[index].front();

				tmp.push_back(node->val);
				q[index].pop();

				if (node->left)
					q[(index+1)%2].push(node->left);
				if (node->right)
					q[(index+1)%2].push(node->right);
			}

			res.push_back(tmp);
			index = (index+1)%2;
		}

		return res;
    }
};