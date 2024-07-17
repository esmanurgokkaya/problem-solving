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
    ZAMAN KARMAŞIKLIĞI = 0(n)
    ALAN KARMAŞIKLIĞI = O (n)
*/

 struct ListNode{
     int val;
     struct ListNode *next;
 };
 
// adding
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* listHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    int i =0;
    struct ListNode * temp = listHead; 
    temp->val=0;
    temp->next=NULL;

    while(l1 != NULL || l2 != NULL){
        int x =(l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = x +y + i;
        i = sum / 10;
        sum %=10;
        temp->next = (struct ListNode * )malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = sum ;
        temp->next=NULL;

        if(l1 != NULL )l1 = l1->next;
        if(l2 != NULL )l2 = l2->next;

    }

    if(i>0){
         temp->next = (struct ListNode * )malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = i ;
        temp->next = NULL;
    }

    
    struct ListNode* list = listHead->next;
    free(listHead);
    return list;

}


// creating linked list
struct ListNode* push( struct ListNode* r, int x)
{
    if(r == NULL){
    r= (struct ListNode*)malloc(sizeof(struct ListNode));
    r->val = x;
    r->next = NULL;
    return r ; 
    }
    struct ListNode* iter = r; 
    while(iter->next != NULL){
        iter = iter->next;
    }
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next = NULL;
    iter->next = temp;
    temp->val = x;
    return r;

    
}

// printing
void print (struct ListNode* r)
{
    while(r != NULL){
        printf("%d",r->val);
        
        r=r->next;
    }
       

}

int main (){
    struct ListNode* l1 ;
    l1 = NULL;
    l1 =  push (l1,9);
    l1 =  push (l1,9);
    l1 =  push (l1,9);
    l1 =  push (l1,9);
    l1 =  push (l1,9);
    l1 =  push (l1,9);
    l1 =  push (l1,9);

    struct ListNode* l2 ;
    l2 = NULL;
    l2 =  push (l2,9);
    l2 =  push (l2,9);
    l2 =  push (l2,9);
    l2 =  push (l2,9);

    print(addTwoNumbers( l1,  l2));

    return 0 ;

}