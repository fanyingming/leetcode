#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0

struct ListNode {
     int val;
     struct ListNode *next;
};

int hasCycle(struct ListNode *head) {
    struct ListNode *p1;
    struct ListNode *p2;
    
    if(head == NULL || head->next == NULL)
        return false;
    
    p1 = head;
    p2 = head->next;
    
    while(p1 != NULL && p2 != NULL){
        if(p1 == p2)
            return true;
		if(p2->next == NULL)
			return false;
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    return false;
}

int main()
{
	struct ListNode a,b,c,d,e;
	int b_have_cycle;

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = NULL;

	b_have_cycle = hasCycle(&a);

	if(b_have_cycle)
		printf("have cycle.\n");
	else
		printf("no cycle.\n");
}