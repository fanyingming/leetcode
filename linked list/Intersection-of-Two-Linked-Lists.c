/*
** 2种方法
** 1.先求链表1的长度，再求链表2的长度，长的链表先走diff距离，然后2个链表对剩下的距离进行
**   挨个判断。这个思路比较好理解。
** 2.2个链表分别遍历，当一个链表遍历到结尾时，从另一个链表进行遍历，如果有交点，
**   交换过头后的遍历会遍历到相同节点。
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0;
    int lenB = 0;
    int diff;
    struct ListNode *p;
    struct ListNode *q;

    if (headA == NULL || headB == NULL)
        return NULL;

    p = headA;
    while (p) {
        lenA++;
        p = p->next;
    }
    p = headB;
    while (p) {
        lenB++;
        p = p->next;
    }
    diff = abs(lenA-lenB);
    if (lenA < lenB) {
        p = headB;
        q = headA;
    } else if (lenA > lenB) {
        p = headA;
        q = headB;
    } else {
        p = headA;
        q = headB
    }
    while (diff-- > 0)
        p = p->next;

    while (q && p) {
        if (p == q)
            return p;
        p = p->next;
        q = q->next;
    }
    return NULL;
}

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