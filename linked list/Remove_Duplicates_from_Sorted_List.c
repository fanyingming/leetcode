/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* p1;
    struct ListNode* p2;

    if (head == NULL)   return head;

    p1 = head;
    p2 = head->next;
    while (p2 != NULL) {
        if (p1->val == p2->val) {
            p2 = p2->next;
            p1->next = p2; 
        } else {
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    return head;
}