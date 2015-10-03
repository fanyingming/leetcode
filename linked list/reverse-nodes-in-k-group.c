/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int isLongEnough(struct ListNode* head, int k) {
    int count = 0;
    struct ListNode* cur = head;
    while (cur) {
        cur = cur->next;
        if (++count >= k)
            return 1;
    }
    return 0;
}

struct ListNode* reverse(struct ListNode*head, int k) {
    struct ListNode preNode;
    struct ListNode *cur;
    struct ListNode *pre;
    struct ListNode *last;
    int count = 0;
    
    preNode.next = NULL;
    cur = head;
    pre = &preNode;
    while (cur && ++count <= k) {
        pre = preNode.next;
        preNode.next = cur;
        cur = cur->next;
        preNode.next->next = pre;
    }
    head->next = cur;
    return preNode.next;
}

struct ListNode* goSetp(struct ListNode* head, int k) {
	int count = 0;
    struct ListNode* cur = head;
    while (cur) {
        cur = cur->next;
        if (++count >= k)
            return cur ;
    }
    return NULL;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode preNode;
    struct ListNode *cur;
    struct ListNode *before;
    
    if (k == 1)
        return head;
    
    cur = head;
    preNode.next = head;
    before = &preNode;
    while (cur) {
        if (isLongEnough(cur, k)) {
            cur = before->next = reverse(cur, k);
            before = goSetp(cur, k-1);
            cur = before->next;
        } else {
        	break;
        }
    }

    return preNode.next;
}