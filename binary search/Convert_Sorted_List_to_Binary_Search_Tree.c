/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct ListNode* cur;
 
struct TreeNode* buildBST(int left, int right) {
    struct TreeNode* curNode;
    int m;
    
    if (left > right)//you should understand why ">" not ">="
        return NULL;
    curNode = malloc(sizeof(struct TreeNode));
    m = left + (right-left)/2;
    curNode->left = buildBST(left, m-1);
    curNode->val = cur->val;
    cur = cur->next;
    curNode->right = buildBST(m+1, right);
    
    return curNode;
}

int getListSize(struct ListNode* head) {
    struct ListNode* h = head;
    int size = 0;
    while (h) {
        size++;
         h = h->next;
    }
    return size;
} 
struct TreeNode* sortedListToBST(struct ListNode* head) {
    int size = getListSize(head);
    cur = head;
    return buildBST(0, size-1);
}