/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 struct ListNode* insertNode(struct ListNode* head, struct ListNode* p){
	struct ListNode* current =  head;

	while(1){
		if(p->val >= current->val && (current->next == NULL || p->val <= current->next->val)){
			p->next = current->next;
			current->next = p;
			return head;
		}

		if(current->next == NULL)
			break;

		current = current->next;
	}

	//
	p->next = head;
	head = p;

	return head;
}

struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *sorted_head;
	struct ListNode *unsorted_head;
	struct ListNode *p;

	if(head == NULL || head->next == NULL)
		return head;

	unsorted_head = head->next;

	sorted_head = head;
	sorted_head->next = NULL;

	while(unsorted_head){
		p = unsorted_head;
		unsorted_head = unsorted_head->next;

		sorted_head = insertNode(sorted_head, p);
	}
	
	return sorted_head;
}