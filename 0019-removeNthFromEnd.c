#include <stdio.h>
#include <stdlib.h>
/*

Given the head of a linked list, remove the nth node from the end of the list and return its head.


Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

*/

/*
    ZAMAN KARMAŞIKLIĞI = 0(n)
    ALAN KARMAŞIKLIĞI = O (1)
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};

// removing from end 
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *temp;
    struct ListNode *iter = head;
    int count = 0;
    while (iter != NULL)
    {
        count++;
        iter = iter->next;
    }
    int i;
    iter = head;
    int iteration = count - n;
    temp = NULL;
    if(iteration == 0){
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    for (i = 0; i < iteration; i++)
    {
        temp = iter;
        iter = iter->next;
    }

    if (iter == NULL)
    {
        return head;
    }
    temp ->next = iter->next;
    free(iter);
    return head;
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
    l1 =  push (l1,3);
    l1 =  push (l1,4);
    l1 =  push (l1,5);



    print(removeNthFromEnd(l1, 2));

    return 0;
}