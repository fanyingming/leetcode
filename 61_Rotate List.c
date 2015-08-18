/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* slow;
    struct ListNode* fast;
    struct ListNode preNode;
    int size;
    int count = 0;
    
    if (k == 0 || head == NULL || head->next == NULL)
        return head;
    
    slow = fast = head;
    //get list length;
    while (fast) {
        fast = fast->next;
        count++;
    }
    size = count;
    k = k%size;
    if (k == 0)
        return head;
        
    fast = slow;
    count = 0;
    //fast walk k steps.
    while (fast->next) {
        fast = fast->next;
        if (++count == k)
            break;
    }
    
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    preNode.next = slow->next;
    fast->next = head;
    slow->next = NULL;
    return preNode.next;
}
