/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int index1;

struct TreeNode* buildBT (int* preorder, int* inorder, int left, int right) {
    struct TreeNode* node;
    int i;
    if (left > right)
        return NULL;
    
    for (i = left; i <= right; i++) {
        if (preorder[index1] == inorder[i])
            break;
    }
    node = malloc(sizeof(struct TreeNode));
    node->val = preorder[index1++];
    node->left = buildBT(preorder, inorder, left, i-1);
    node->right= buildBT(preorder, inorder, i+1, right);
    return node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize != inorderSize)
        return NULL;
    index1 = 0;
    return buildBT(preorder, inorder, 0, inorderSize-1);
}