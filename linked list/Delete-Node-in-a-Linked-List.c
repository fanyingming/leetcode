/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* h = node;
    
    while (h->next) {
        h->val = h->next->val;
        if(h->next->next == NULL) {
            h->next = NULL; 
            break;
        } else {
            h = h->next;
        }
    }
}