/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int index1;

struct TreeNode* buildBT (int* postorder, int* inorder, int left, int right) {
    struct TreeNode* node;
    int i;
    if (left > right)
        return NULL;
    
    for (i = left; i <= right; i++) {
        if (postorder[index1] == inorder[i])
            break;
    }
    node = malloc(sizeof(struct TreeNode));
    node->val = postorder[index1--];
    node->right = buildBT(postorder, inorder, i+1, right);
    node->left= buildBT(postorder, inorder, left, i-1);
    return node;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (postorderSize != inorderSize)
        return NULL;
    index1 = postorderSize-1;
    return buildBT(postorder, inorder, 0, inorderSize-1);
}