/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 int getListLength(struct ListNode* head){
     int len = 0;
     struct ListNode* cur = head;
     
     while (cur) {
         len++;
         cur = cur->next;
     }
     
     return len;
 }
 
 struct ListNode* getMiddleNode(struct ListNode* head) {
     struct ListNode* cur = head;
     struct ListNode* middle_node;
     int length = getListLength(head);
     int middle = length/2;
     
     if (length < 2)
        return head;
     if (head == NULL || head->next == NULL)
        return head;
     
     while (middle-1 > 0) {
         cur = cur->next;
         middle--;
     }
     
     middle_node = cur->next;
     cur->next = NULL;
     
     return middle_node;
 }
 
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

struct ListNode* mergeList(struct ListNode* head) {
    struct ListNode* middle;
    struct ListNode* h;
    struct ListNode* m;
    struct ListNode* rn;
    
    if (getListLength(head) < 2)
        return head;
        
    middle = getMiddleNode(head);
    
    h = mergeList(head);
    m = mergeList(middle);
    
    rn = mergeTwoLists(h, m);
    
    return rn;
} 

struct ListNode* sortList(struct ListNode* head) {
    return mergeList(head);
}