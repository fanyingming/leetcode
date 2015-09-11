/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max_v(int a, int b) {
    return a > b ? a : b;
}
int max_value;

int DFS(struct TreeNode* root) {
    int left_sum, right_sum;
    int sum;
    
    if (root == NULL)
        return 0;
    
    left_sum = max_v(0, DFS(root->left));
    right_sum= max_v(0, DFS(root->right));
    sum = left_sum + right_sum + root->val;//a path.
    
    max_value = max_v(sum, max_value);
    
    return max_v(left_sum, right_sum) + root->val;//return one max path.
}

int maxPathSum(struct TreeNode* root) {
    if (root == NULL)
        return 0;
        
    max_value = -999999999;
    DFS(root);
    return max_value;
}