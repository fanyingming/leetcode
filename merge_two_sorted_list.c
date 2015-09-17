/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists_old(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* h;
    struct ListNode* cur;
    //error handling.
    if (l1 == NULL && l2 == NULL)
        return NULL;
    if (l1 == NULL && l2 != NULL)
        return l2;
    if (l1 != NULL && l2 == NULL)
        return l1;
        
    if (l1->val < l2->val) {
        h = l1;
        l1 = l1->next;
    } else {
        h = l2;
        l2= l2->next;
    }
    
    cur = h;
    
    while (l1 && l2){
        if (l1->val < l2->val) {
            cur->next = l1;
            l1        = l1->next;
        } else {
            cur->next = l2;
            l2        = l2->next;
        }
		cur = cur->next;// do not forget this op~~~
    }
    
    if (l1) {
        cur->next = l1;
    } else {
        cur->next = l2;
    }
    
    return h;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* cur;
    struct ListNode* cur1;
    struct ListNode* cur2;
    struct ListNode preNode;
    //error handling.
        
    preNode.next = NULL;
    cur = &preNode;
    cur1 = l1;
    cur2 = l2;
    while (cur1 && cur2) {
        if (cur1->val <= cur2->val) {
            cur->next = cur1;
            cur1 = cur1->next;
        } else {
            cur->next = cur2;
            cur2 = cur2->next;
        }
        cur = cur->next;
    }
    if (cur1)
        cur->next = cur1;
    if (cur2)
        cur->next = cur2;
    return preNode.next;
}
