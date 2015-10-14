/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
 /*
 ** 巧妙的方法是：先创建新链表，并链入原有链表，就是说一个旧节点，一个新节点；
 ** 然后遍历旧链表，顺便对新链表节点的random赋值，因为和旧节点相邻，所以比较好赋值。
 ** 最后新旧链表拆开即可。
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *cur;
    struct RandomListNode *newNode;
    struct RandomListNode preNode;
    
    cur = head;
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
        if (cur->random)
            cur->next->random = cur->random->next;
        else
            cur->next->random = NULL;
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
    }
    newNode->next = NULL;
    return preNode.next;
}