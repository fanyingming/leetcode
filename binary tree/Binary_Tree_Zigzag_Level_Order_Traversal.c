class Solution {
public:
    vector<vector<int>> rl;
    queue<TreeNode*> que;
    
    void BFS(TreeNode* root) {
        que.push(root);
        
        int count = 1;
        
        while (que.empty() == false) {
            int size = que.size();
            vector<int> ver;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                ver.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                que.pop();
            }
            if (count%2 == 1) {
                rl.push_back(ver);
            } else {
                vector<int> reversed;
                for (int i = ver.size()-1; i >= 0 ; i--)
                    reversed.push_back(ver[i]);
                rl.push_back(reversed);
            }
            count++;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return rl;
        BFS(root);
        return rl;
    }
};
