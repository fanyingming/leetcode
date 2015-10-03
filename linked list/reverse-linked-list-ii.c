//hard to think.
//看了discuss才知道要建立一个pre node.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode* cur;
    struct ListNode* h;
    struct ListNode* next;
    struct ListNode pre;
    struct ListNode*p;
    int i;
    
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    if (m == n)
        return head;
    
    n = n-m;
    p = &pre;
    pre.next = head;
    h = p;
    while (--m > 0)
        h = h->next;
    cur = h->next;
    while (n-- > 0) {
        next = cur->next;
        cur->next = next->next;
        next->next = h->next;
        h->next = next;
    }
    
    return p->next;
}