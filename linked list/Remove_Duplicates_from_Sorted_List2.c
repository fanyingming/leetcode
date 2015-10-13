struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p1;
    struct ListNode *p2;
    struct ListNode preNode;
    struct ListNode *pre;
    bool b_same = false;

    if (head == NULL || head->next == NULL) return head;
    preNode.next = head;
    pre = &preNode;
    p1 = head;
    p2 = head->next;
    while (p2 != NULL) {
        if (p1->val == p2->val) {
            b_same = true;
            p2 = p2->next;
        } else {
            if (b_same) {
                pre->next = p2;
                p1 = p2;
                p2 = p1->next;
                b_same = false;
            } else {
                pre = pre->next;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
    }
    if (b_same)
        pre->next = NULL;
    return preNode.next;
}