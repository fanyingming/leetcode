/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode pre;
    struct ListNode* cur;
    struct ListNode* slow;
    struct ListNode* fast;
    int b_odd = 0;
    
    if (head == NULL || head->next == NULL)
        return true;
    
    cur = pre.next = NULL;
    slow = fast = head;
    
    while (fast) {
        if (fast->next == NULL) {
            b_odd = 1;
            break;
        }
        
        cur = slow;
        
        fast = fast->next->next;
        slow = slow->next;
        
        cur->next = pre.next;
        pre.next = cur;
    }
    
    if (b_odd) {
        slow = slow->next;
    }
    
    cur = pre.next;
    while (cur) {
        if (cur->val != slow->val)
            return false;
        cur = cur->next;
        slow =slow->next;
    }
    return true;
}
