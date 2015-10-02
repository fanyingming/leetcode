
 // Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 #define NULL 0
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode prenode;
    struct ListNode *pre;
    struct ListNode *cur;
    struct ListNode *next;
    int b_remove = 0;
    
    pre = &prenode;
    prenode.next = head;
    
    if (head == NULL || head->next == NULL)
        return head;
    
    cur = pre->next;
    next= cur->next;
    
    //invariant: nodes before cur no dumlicates
    while (next) {
        if (cur->val == next->val) {
            b_remove++;
            next = next->next;
        } else {
            if (b_remove) {
                pre->next = next;
                cur = next;
                next = next->next;
            } else {
                pre = cur;
                cur = next;
                next = next->next;
            }
            b_remove = 0;
        }
    }
    if (b_remove) {
        pre->next = next;
    }
    return prenode.next;
}