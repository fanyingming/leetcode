/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *curA;
    struct ListNode *curB;
    int loop_num = 0;
    int whichA, whichB;
    
    if (headA == NULL || headB == NULL)
        return NULL;
    
    whichA = 1;
    whichB = 1;
    curA = headA;
    curB = headB;
    
    while (loop_num < 2) {
        if (curA == curB) {
            return curA;
        } else {
            if (curA->next) {
                curA = curA->next;
            } else {
                loop_num++;
                curA = (whichA++)%2 == 1 ? headB : headA;
            }
            if (curB->next) {
                curB = curB->next;
            } else {
                curB = (whichB++)%2 == 1 ? headA : headB;
            }
        }
    }
    return NULL;
}