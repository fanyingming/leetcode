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
	vector<vector<TreeNode*>> pathList;
	int traverse(TreeNode* root, TreeNode* p, vector<TreeNode*>& list) {
		if (root == NULL)
			return 0;

		list.push_back(root);
		if (root == p) {
			pathList.push_back(list);
			return 1;
		}
		if (traverse(root->left, p, list))
			return 1;
		if (traverse(root->right,p, list))
			return 1;
		list.pop_back();
		return 0;
	}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
        	return root;
        vector<TreeNode*> list;
        traverse(root, p, list);
        list.clear();
		traverse(root, q, list);
		TreeNode* common = NULL;
		if (pathList.size() < 2)
	    	return common;
		for (int i = 0; i < pathList[0].size() && i < pathList[1].size(); i++) {
			if (pathList[0][i] == pathList[1][i])
				common = pathList[0][i];
			else
				break;
		}
		return common;
    }
};