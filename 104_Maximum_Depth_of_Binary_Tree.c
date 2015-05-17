#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

int DFS(struct TreeNode *node)
{
    int left_depth, right_depth;
    
    if(node->left)
        left_depth = DFS(node->left) + 1;
    else
        left_depth = 0;
        
    if(node->right)
        right_depth = DFS(node->right) + 1;
    else
        right_depth = 0;

    if(node->left==NULL && node->right==NULL)
        return 1;
    
    return left_depth>right_depth?left_depth:right_depth;
    
}

int maxDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    
    return DFS(root);
}

int main()
{
    struct TreeNode node1,node2,node3,node4;

    node1.left = &node2;
    node1.right = &node4;

    node2.left = &node3;
    node2.right = NULL;

    node3.left = node3.right = NULL;

    node4.left = node4.right = NULL;
    
    printf("%d\n", maxDepth(&node1));
}


