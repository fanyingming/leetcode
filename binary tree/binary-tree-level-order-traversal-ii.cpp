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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> rl;
    	stack<vector<int>> rstack;
    	queue<TreeNode*> que;

    	if (root == NULL)	return rl;
    	que.push(root);
    	while (que.empty() == false) {
    		int num = que.size();
    		vector<int> row;
    		for (int i = 0; i < num; i++) {
    			TreeNode *node = que.front();
    			que.pop();
    			row.push_back(node->val);
    			if (node->left)
    				que.push(node->left);
    			if (node->right)
    				que.push(node->right);
    		}
    		rstack.push(row);
    	}
    	while (rstack.empty() == false) {
    		rl.push_back(rstack.top());
    		rstack.pop();
    	}
    	return rl;
    }
};