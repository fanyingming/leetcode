/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode preNode;
    struct ListNode *cur, *pre;
    int n_num = n;
    
    if (head == NULL || n == 0)
        return head;
    
    preNode.next = head;
    pre = &preNode;
    cur = head;
    
    while (n_num--) {
        cur = cur->next;
    }
    
    while (cur) {
        pre = pre->next;
        cur = cur->next;
    }
    
    pre->next = pre->next->next;
    
    return preNode.next;
}