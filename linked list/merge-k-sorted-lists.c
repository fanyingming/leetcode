/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /*
 ** K路归并，普通算法的复杂度是多少？O(nk),比如循环归并，1和2归并好后，与3归并，每次2个链表归并时，
 ** 都要从头开始往后遍历，因为没有对位置的记忆。
 ** 使用最小堆进行K路归并：用每个链表的第一个元素建立一个K个元素的最小堆，每次取堆顶元素加入结果，
 ** 因为是最小堆，所以每次顶部都是最小的值，这样就相当于我们能够记住一个位置，而不用像普通归并那样，
 ** 每次从头开始~！！！复杂度是O(nlgk)
 */

struct List {
    struct ListNode *list;
};

struct Heap {
    struct List* heapELement;
    int length;
};

void min_heapify(struct Heap *h, int i)
{
    int l = i*2;
    int r = i*2+1;
    int min;
    struct List t;

    if (i >= h->length) return;

    min = i;
    //三个数中选择最小的数，第一次写的版本是有bug得，值得注意。
    if (l <= h->length && h->heapELement[l].list->val < h->heapELement[min].list->val)
        min = l;
    if (r <= h->length && h->heapELement[r].list->val < h->heapELement[min].list->val)
        min = r;

    if (min == i)
        return;
    //swap max and i node.
    t = h->heapELement[i];
    h->heapELement[i] = h->heapELement[min];
    h->heapELement[min] = t;

    min_heapify(h, min);
}

void build_min_heap(struct Heap *h)
{
    int i;

    for (i = h->length/2; i>=1; i--){
        min_heapify(h, i);
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int i;
    struct Heap heap;
    struct ListNode res;
    struct ListNode* cur;
    int index = 1;
    res.next = NULL;
    cur = &res;

    if (lists == NULL || listsSize <= 0)
        return NULL;

    heap.heapELement = (struct List*)malloc((listsSize+1)*sizeof(struct List));
    
    for (i = 0; i < listsSize; i++) {
        if (lists[i])//skip null list.
            heap.heapELement[index++].list = lists[i];
    }
    heap.length = index-1;

    build_min_heap(&heap);

    while (heap.length > 0) {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = heap.heapELement[1].list->val;
        tmp->next = NULL;

        cur->next = tmp;
        cur = cur->next;

        if (heap.heapELement[1].list->next == NULL) {
            heap.heapELement[1] = heap.heapELement[heap.length];
            heap.length--;
        } else {
            heap.heapELement[1].list = heap.heapELement[1].list->next;
        }
        
        min_heapify(&heap, 1);
    }
    return res.next;
}