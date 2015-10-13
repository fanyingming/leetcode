/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode Pre;
    struct ListNode* h;
    struct ListNode* next;
    
    if (head == NULL || head->next == NULL)
        return head;
        
    Pre.next = NULL;
    h = head;
    while (h) {
        next = Pre.next;
        Pre.next = h;
        h = h->next;
        Pre.next->next = next;
    }
    
    return Pre.next;
}
void helper(struct ListNode* head, struct ListNode* reversed) {
    struct ListNode* next;
    if (head == NULL)   return;
    next = reversed->next;
    reversed->next = head;
    head = head->next;
    reversed->next->next = next;
    helper(head, reversed);
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode Pre;
    Pre.next = NULL;
    helper(head, &Pre);
    return Pre.next;
}