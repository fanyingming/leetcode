
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool searchTree(struct TreeNode *p, struct TreeNode *q){
    if(p==NULL&&q==NULL)
        return true;
    if(p==NULL && q!=NULL)
        return false;
    if(p!=NULL && q==NULL)
        return false;
    if(p->val != q->val)
        return false;
    
 //   assert(p->val == q->val)
    {
        bool left, right;
        
        left =  searchTree(p->left, q->left);
        right = searchTree(p->right, q->right);
        
        if (left && right)
            return true;
        else
            return false;
    }
    
} 
 
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    return searchTree(p, q);
}

int main()
{
    struct TreeNode a1,a2,a3;
    struct TreeNode b1,b2,b3;
    bool b_same = false;

    a1.left = &a2; a1.right = NULL; a1.val = 1;
    a2.left = &a3; a2.right = NULL; a2.val = 2;
    a3.left = a3.right = NULL; a3.val = 3;

    b1.left = &b2; b1.right = NULL; b1.val = 1;
    b2.left = &b3; b2.right = NULL; b2.val = 2;
    b3.left = b3.right = NULL; b3.val = 1;

    b_same = isSameTree(&a1, &b1);

    if (b_same)
        printf("same\n");
    else
        printf("not same\n");
}