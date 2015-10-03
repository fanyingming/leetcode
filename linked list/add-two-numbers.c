/**
 * Definition for singly-linked list.
 * struct ListNode { 342 + 465 = 807
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* h;
    struct ListNode* cur;
    struct ListNode pre;
    
    pre.next = NULL;
    cur = &pre;
    
    while (l1 || l2) {
        struct ListNode* t = malloc(sizeof(struct ListNode));
        t->next = NULL;
        
        if (l1 && l2)
            t->val = l1->val + l2->val;
        else if (l1 && l2 == NULL)
            t->val = l1->val;
        else
            t->val = l2->val;
        
        cur->next = t;
        cur = t;
        
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    
    cur = pre.next;
    while (cur) {
        if (cur->val >= 10) {
            if (cur->next) {
                cur->next->val += 1;
                cur->val -= 10;
            } else {
                struct ListNode* t = malloc(sizeof(struct ListNode));
                t->val = 1;
                t->next = NULL;
                cur->next = t;
                cur->val -= 10;
                break;
            }
        }
        cur = cur->next;
    }
    
    return pre.next;
}