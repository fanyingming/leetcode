bool isLongEnough(struct ListNode* head, int k) {
    struct ListNode* h = head;
    while (k-- > 0) {
        if (h == NULL)
            return false;
        else
            h = h->next;
    }
    return true;
}

struct ListNode* reverse(struct ListNode* head, int k) {
    struct ListNode* t;
    struct ListNode* cur;
    struct ListNode  pre;

    pre.next = NULL;
    cur = head;
    while (k-- > 0) {
        t = pre.next;
        pre.next = cur;
        cur = cur->next;
        pre.next->next = t;
    }
    head->next = cur;//remember this operation, we need this to make list still linked.
    return pre.next;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* before;
    struct ListNode* cur;
    struct ListNode  pre;

    if (head == NULL || head->next == NULL || k == 0 || k == 1) return head;

    pre.next = head;
    before   = &pre;
    cur = head;
    while (cur) {
        int step = k;
        if (isLongEnough(cur, k)) {
            before->next = reverse(cur, k);
        } else {
            break;
        }
        while (step-- > 0)
            before = before->next;
        cur = before->next;
    }
    return pre.next;
}