/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildBST(int* nums, int left, int right) {
    struct TreeNode* curNode;
    int m;
    
    if (left > right)//you should understand why ">" not ">="
        return NULL;
    curNode = malloc(sizeof(struct TreeNode));
    m = left + (right-left)/2;
    curNode->left = buildBST(nums, left, m-1);
    curNode->val = nums[m];
    curNode->right = buildBST(nums, m+1, right);
    
    return curNode;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return buildBST(nums, 0, numsSize-1);
}