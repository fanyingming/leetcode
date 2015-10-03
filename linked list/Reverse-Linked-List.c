/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur;
    struct ListNode* h;
    struct ListNode* next;
    
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
        
    cur = NULL;
    h = head;
    while (h) {
        next = h->next;
        h->next = cur;
        cur = h;
        h = next;
    }
    
    return cur;
}