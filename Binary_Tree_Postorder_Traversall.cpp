/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NUL7L) {}
 * };
 */]
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
		vector<int> result;
		vector<int> inv_result;
		int i;

		result.clear();

		if(root == NULL)
			return result;

		//as init value.
		s.push(root);

		while(s.empty() == false){
			struct TreeNode *node = s.top();

			s.pop();
			result.push_back(node->val);

			if(node->left != NULL)
				s.push(node->left);
			if(node->right != NULL)
				s.push(node->right);
		}
		
		for( i=result.size()-1; i>=0; i-- ){
			inv_result.push_back( result.at(i) );
		}

		return inv_result;
    }
};
