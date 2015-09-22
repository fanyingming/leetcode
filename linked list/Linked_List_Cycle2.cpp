/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        struct ListNode *p1;
        struct ListNode *p2;
        
        if(head == NULL || head->next == NULL)
            return NULL;
        
        p1 = p2 = head;
        
        while(p1 != NULL && p2 != NULL){
            if(p2->next == NULL)
                return NULL;
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1 == p2)
                break;
        }
        if (p1 == NULL || p2 == NULL)
            return NULL;
        
        p1 = head;
        while (1) {
            if (p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
};