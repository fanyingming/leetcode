/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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

struct ListNode* mergeKLists_slow(struct ListNode** lists, int listsSize) {
    int i;
    struct ListNode* list1;
    
    if (lists == NULL || listsSize <= 0)
        return NULL;
        
    list1 = lists[0];
    
    for (i = 1; i < listsSize; i++) {
        list1 = mergeTwoLists(list1, lists[i]);
    }
    
    return list1;
}

struct ListNode* merge(struct ListNode** lists, int left, int right) {
    if (left < right) {
        int m = (left + right)/2;
        return mergeTwoLists(merge(lists, left, m), merge(lists, m+1, right));
    } else {
        return lists[left];
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize <= 0)
        return NULL;
    
    return merge(lists, 0, listsSize-1);
}