/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *cur;
    struct RandomListNode *newNode;
    struct RandomListNode preNode;
    
    cur = head;
    preNode.next = NULL;
    //new and linked to a line.
    while (cur) {
        newNode = malloc(sizeof(struct RandomListNode));
        newNode->label = cur->label;
        newNode->next  = cur->next;
        cur->next = newNode;
        cur = newNode->next;
    }
    //fill random field for new list
    cur = head;
    while (cur) {
        if (cur->random) {
            cur->next->random = cur->random->next;
        } else {
            cur->next->random = NULL;
        }
        cur = cur->next->next;
    }
    //seperate combined list.
    newNode = &preNode;
    cur = head;
    while (cur) {
        newNode->next = cur->next;
        cur->next = cur->next->next;
        cur = cur->next;
        newNode = newNode->next;
        newNode->next = NULL;
    }
    return preNode.next;
}
