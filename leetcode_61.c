#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(head == NULL || k == 0)
    {
        return head;
    }
    
    //find length of list
    int length = 1;
    int i = 0;
    struct ListNode *tail = head;
    
    while(tail->next != NULL)
    {
        tail = tail->next;
        length++;
    }
    

    
    // Calculate the actual rotation amount
    k = k%length;
    
    if(k==0)
    {
        return head;
    }
    
    // Connect last node to the head to form a loop
    tail->next = head;
    
    // Traverse to the (n-k%n -1)th node
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    for(i=0; i<length-k; i++)
    {
        prev = current;
        current = current->next;
    }
    
    // Set next node after as new node
    struct ListNode *new_head = current;
    prev->next = NULL;
    
    return new_head;
    
}

void printList(struct ListNode* head)
{
    while(head != NULL)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = NULL;
    
    struct ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = NULL;
    head->next = l1;
    
    struct ListNode *l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 3;
    l2->next = NULL;
    head->next->next = l2;
    
    struct ListNode *l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->val = 4;
    l3->next = NULL;
    head->next->next->next = l3;
    
    struct ListNode *l4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l4->val = 5;
    l4->next = NULL;
    head->next->next->next->next = l4;
    
    int k = 5;
    
    printf("Original List: ");
    printList(head);
    
    struct ListNode *rotated_head = rotateRight(head,k);
    
    printf("Rotated Right: ");
    printList(rotated_head);
    
    return 0;
}