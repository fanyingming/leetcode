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
    void reorderList(ListNode* head) {
        ListNode* t;
        ListNode* s;
        ListNode* f;
        ListNode* st;
        ListNode* ft;
        ListNode pre(0);
        
        if (head == NULL || head->next == NULL || head->next->next == NULL) return;
        s = f = head;
        while (f->next) {//list nodes is even count
            if (f->next->next == NULL) //list nodes is odd count
                break;
            f = f->next->next;
            s = s->next;
        }
        
        pre.next = NULL;
        t = s;
        s = s->next;
        t->next = NULL;
        while (s) {
            t = pre.next;
            pre.next = s;
            s = s->next;
            pre.next->next = t;
        }
        
        s = head;
        f = pre.next;
        
        while (s && f) {
            st = s->next;
            ft = f->next;
            s->next = f;
            f->next = st;
            s = st;
            f = ft;
        }
        return;
    }
};