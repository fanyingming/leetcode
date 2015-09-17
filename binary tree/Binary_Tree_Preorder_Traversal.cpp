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
		sta.push_back(root);

		while (sta.empty() == false) {
			struct TreeNode *node = sta.top();

			stack.pop_back();
			result.push_back(node->val);

			if (node->right != NULL)
				stack.push_back(node->right);
			if (node->left != NULL)
				stack.push_back(node->left);
		}
		
		return result;
    }
};