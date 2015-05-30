#include <vector>
#include <iostream>

using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
		vector<TreeNode *> stack;
		vector<int> result;

		result.clear();
		stack.clear();

		if(root == NULL)
			return result;

		//as init value.
		stack.push_back(root);

		while(stack.empty() == false){
			int length = stack.size();
			struct TreeNode *node = stack.at(length-1);

			stack.pop_back();
			result.push_back(node->val);

			if(node->right != NULL)
				stack.push_back(node->right);
			if(node->left != NULL)
				stack.push_back(node->left);
		}
		
		return result;
    }
};

int main()
{
	Solution s;
	int i;

	struct TreeNode a(1);
	struct TreeNode b(2);
	struct TreeNode c(3);
	struct TreeNode d(4);
	struct TreeNode e(5);

	a.left = &b;
	a.right = &c;
	b.right = &d;
	c.left = &e;

	vector<int> result = s.preorderTraversal(&a);

	for( i=0; i<result.size(); i++)
		cout<<result.at(i)<<"\t";
	cout<<endl;
}