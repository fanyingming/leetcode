class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode *> sta;
		vector<int> result;

		result.clear();
		stack.clear();

		if(root == NULL)
			return result;

		//as init value.
		sta.push(root);

		while (sta.empty() == false) {
			struct TreeNode *node = sta.top();

			stack.pop();
			result.push(node->val);

			if (node->right != NULL)
				stack.push_back(node->right);
			if (node->left != NULL)
				stack.push_back(node->left);
		}
		
		return result;
    }
};