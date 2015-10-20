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
	vector<vector<int>> pathList;

	void traverse(TreeNode* root, vector<int>& list) {
		if (root == NULL)
			return;

		list.push_back(root->val);
		if (root->left == NULL && root->right == NULL) {
			pathList.push_back(list);
			list.pop_back();
			return;
		}

		if (root->left)
			traverse(root->left, list);
		if (root->right)
			traverse(root->right,list);
		list.pop_back();
	}

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> rl;
        if (root == NULL)	return rl;
        vector<int> tv;
        traverse(root, tv);
        for (int i = 0; i < pathList.size(); i++) {
        	string str;
        	vector<int> row;
        	for (int j = 0; j < pathList[i].size(); j++) {
        		char buffer[20];      
				sprintf(buffer, "%d", pathList[i][j]);
				string num(buffer); 
        		str += num;
        		if (j < pathList[i].size()-1)
        			str += "->";
        	}
        	rl.push_back(str);
        }
    }
};