class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
		vector<int> result;
		TreeNode *p;

		//as init value.
		p = root;

		while(s.empty() == false || p != NULL){
			if (p) {
				s.push(p);
				p = p->left;
			} else {
				TreeNode *node = s.top();

				s.pop();
				result.push_back(node->val);
				p = node->right;
			}
		}
		
		return result;
    }
};
