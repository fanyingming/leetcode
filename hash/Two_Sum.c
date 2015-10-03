/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 typedef struct Hash_table {
     int index;
     int value;
     struct Hash_table *next;
 }Hash_table;
 
 int abs_value(int a) {
     if (a < 0)
        return -a;
    else
        return a;
 }
 
 Hash_table* build_table(int* nums, int numsSize) {
    Hash_table *table = malloc(numsSize*sizeof(struct Hash_table));
    int i;
    memset(table, 0, numsSize*sizeof(struct Hash_table));
    for (i = 0; i < numsSize; i++) {
        int pos;
        Hash_table *node = malloc(sizeof(struct Hash_table));
        node->index = i+1;
        node->value = nums[i];
        node->next = NULL;
        pos = abs_value(node->value)%numsSize;
        if (table[pos].next == NULL) {
            table[pos].next = node;
        } else {
            Hash_table *cur = table[pos].next;
            
            while(cur->next)
                cur = cur->next;
            
            cur->next = node;
        }
    }
    
    return table;
 }
 
 int* twoSum(int* nums, int numsSize, int target) {
     int *rv = malloc(2*sizeof(int));
     Hash_table *table = build_table(nums, numsSize);
     int i,j;
     
     for (i = 0; i < numsSize-1; i++) {
         int index1 = i+1;
         int value1 = nums[i];
         int value2 = target - value1;
         int pos2 = abs_value(value2)%numsSize;
         
         if (table[pos2].next == NULL) {
             continue;
         } else {
             Hash_table *cur = table[pos2].next;
             while (cur) {
                 if (cur->value == value2 && cur->index > index1) {
                     rv[0] = index1;
                     rv[1] = cur->index;
                     return rv;
                 } else {
                     cur = cur->next;
                 }
             }
         }
     }
 }
 
int* twoSum_brute_force(int* nums, int numsSize, int target) {
    int *rv = malloc(2*sizeof(int));
    int i, j;
    
    for ( i = 0; i < numsSize; i++) {
        for ( j = i+1; j< numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                rv[0] = i + 1;
                rv[1] = j + 1;
                return rv;
            }
        }
    }
}
/*
int main() {
	int  a[3] = {3,2,4};
	int target = 6;
	int *rv;

	rv = twoSum(a, 3, target);
	printf("%d %d\n", rv[0], rv[1]);
}*/