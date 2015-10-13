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
    
    if (head == NULL || head->next == NULL || m == n)
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
/*
** 看不明白上边，也就是之前的代码了。所以重写，重写的代码又臭又多~
*/
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    int skipCount = m-1;
    struct ListNode *h;
    struct ListNode pre;
    struct ListNode headNode;
    struct ListNode *next;
    struct ListNode *last;
    struct ListNode *previous;

    if (head == NULL || head->next == NULL || m == n)   
        return head;
    
    n = n-m+1;
    headNode.next = head;
    h = &headNode;
    while (skipCount-- > 0)
        h = h->next;
    previous = h;
    h = h->next;
    last = h;
    pre.next = NULL;
    while (n-- > 0) {
        next = pre.next;
        pre.next = h;
        h = h->next;
        pre.next->next = next;
    }
    previous->next = pre.next;
    last->next = h;
    return headNode.next;
}