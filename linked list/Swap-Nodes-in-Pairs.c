/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode  pre;//key point.
    struct ListNode* h;
    
    h = &pre;
    pre.next = head;
    
    while (h->next) {
        struct ListNode* cur;
        struct ListNode* next;
        
        cur = h->next;
        next = cur->next;
        
        if (next == NULL)//single node.
            break;
        
        cur->next = next->next;
        h->next = next;
        next->next = cur;
        
        h = cur;
    }
    
    return pre.next;
}