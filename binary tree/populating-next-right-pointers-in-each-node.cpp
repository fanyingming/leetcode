/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	//O(1) space
	void connect(TreeLinkNode *root) {
		if (root == NULL)	return;
		TreeLinkNode *h = root;
		while (h->left) {
			TreeLinkNode *cur = h;
			while (cur->next) {
				cur->left->next  = cur->right;
				cur->right->next = cur->next->left;
				cur = cur->next;
			}
			cur->left->next = cur->right;
			h = h->left;
		}
	}
    //O(n) space
    void connect1(TreeLinkNode *root) {
        if (root == NULL)	return;
        queue<TreeLinkNode*> que;
        que.push(root);
        while (que.empty() == false) {
        	int num = que.size();
        	for (int i = 0; i < num; i++) {
        		TreeLinkNode *node = que.front();
        		que.pop();

        		if (node->left && node->right) {
        			que.push(node->left);
        			que.push(node->right);
        			node->left->next = node->right;
        			if (i < num-1)
	        			node->right->next = que.front()->left;
        		}
        	}
        }
    }
};