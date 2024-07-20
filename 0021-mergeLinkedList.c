#include <stdio.h>
#include <stdlib.h>
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

*/

/*
    ZAMAN KARMAŞIKLIĞI = 0(n + m)
    ALAN KARMAŞIKLIĞI = O (n + m)
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};

// adding

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        if(list1->val <= list2->val){
           list1->next =mergeTwoLists(list1->next, list2);
           return list1;
        }
        else{
           list2->next = mergeTwoLists(list1,list2->next);
           return list2;
        }
       


    

    return list1 == NULL ? list2 : list1;


}

// creating linked list
struct ListNode *push(struct ListNode *r, int x)
{
    if (r == NULL)
    {
        r = (struct ListNode *)malloc(sizeof(struct ListNode));
        r->val = x;
        r->next = NULL;
        return r;
    }
    struct ListNode *iter = r;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->next = NULL;
    iter->next = temp;
    temp->val = x;
    return r;
}

// printing
void print(struct ListNode *r)
{
    while (r != NULL)
    {
        printf("%d", r->val);

        r = r->next;
    }
}

int main()
{
    struct ListNode *l1;
    l1 = NULL;
    l1 = push(l1, 1);
    l1 = push(l1, 2);
    l1 = push(l1, 3);
    l1 = push(l1, 4);

    struct ListNode *l2;
    l2 = NULL;
    l2 = push(l2, 1);
    l2 = push(l2, 2);
    l2 = push(l2, 3);
    l2 = push(l2, 4);

    print(mergeTwoLists(l1, l2));

    return 0;
}