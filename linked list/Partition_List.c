/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode small;
			struct ListNode large;
			struct ListNode *cur1;
			struct ListNode *cur2;
			struct ListNode *next2;

			if (head == NULL)
				return NULL;

			small.next = NULL;
			large.next = head;
			cur1 = &large;
			cur2 = &small;

			while (cur1->next) {
				if (cur1->next->val < x) {
					cur2->next = cur1->next;
					next2 = cur1->next;
					cur1->next = cur1->next->next;
					next2->next = NULL;
					//			cur1 = cur1->next;
					cur2 = cur2->next;
				}
				else {
					cur1 = cur1->next;
				}
			}
			cur2->next = large.next;
			return small.next;
}
