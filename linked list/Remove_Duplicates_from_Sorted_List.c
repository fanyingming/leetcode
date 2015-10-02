/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cur;
    struct ListNode* next;
    
    if (head == NULL || head->next == NULL)
        return head;
        
    cur = head;
    next= head->next;
    //special case, only two nodes.
    //invariant, list still sorted.
    while (next){
        if (cur->val != next->val){
            cur->next = next;
            cur = next;
        }
        next = next->next;
    }
    //delete tail same nodes.
    cur->next = NULL;
    
    return head;
}