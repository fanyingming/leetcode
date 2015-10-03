/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode preNode;
    struct ListNode *pre, *cur;
    
    pre = &preNode;
    preNode.next = head;
    cur = head;
    
    while (cur) {
        if (cur->val == val) {
            pre->next = cur->next;
            cur = pre->next;
        } else {
            pre = cur;
            cur = cur->next;
        }
    }
    
    return preNode.next;
}