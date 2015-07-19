#include <stdio.h>
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* h;
    struct ListNode* cur;
    //error handling.
    if (l1 == NULL && l2 == NULL)
        return NULL;
    if (l1 == NULL && l2 != NULL)
        return l2;
    if (l1 != NULL && l2 == NULL)
        return l1;
        
    if (l1->val < l2->val) {
        h = l1;
        l1 = l1->next;
    } else {
        h = l2;
        l2= l2->next;
    }
    
    cur = h;
    
    while (l1 && l2){
        if (l1->val < l2->val) {
            cur->next = l1;
            l1        = l1->next;
        } else {
            cur->next = l2;
            l2        = l2->next;
        }
		cur = cur->next;// do not forget this op~~~
    }
    
    if (l1) {
        cur->next = l1;
    } else {
        cur->next = l2;
    }
    
    return h;
}

int main()
{
	struct ListNode a, b1, b2, b3;
	struct ListNode* h;
	int i;

	a.val = 5;
	b1.val = 1;
	b2.val = 2;
	b3.val = 4;

	a.next = NULL;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = NULL;

	h= mergeTwoLists( &a, &b1);
	
	while (h){
		printf("%d\t", h->val);
		h = h->next;
	}
	printf("\n");
}