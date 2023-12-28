#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    
    struct ListNode *current = dummy;
    
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val)
        {
            current->next = l1;
            l1 = l1->next;
        }else{
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    if(l1 != NULL){
        current->next = l1;
    }else{
        current->next = l2;
    }
    
    struct ListNode *result = dummy->next;
    free(dummy);
    return result;

}

void printList(struct ListNode *head)
{
    while(head != NULL)
    {
        printf("head->val = %d\n", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct ListNode *list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = NULL;
    
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = 2;
    newNode->next = NULL;
    list1->next = newNode;
    
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = 4;
    newNode->next = NULL;
    list1->next->next = newNode;
    
    struct ListNode *list2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->val = 1;
    list2->next = NULL;
    
    struct ListNode *newNode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode2->val = 3;
    newNode2->next = NULL;
    list2->next = newNode2;
    
    newNode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode2->val = 5;
    newNode2->next = NULL;
    list2->next->next = newNode2;
    
    // Print the original list
    printf("List 1: \n");
    printList(list1);
    
    printf("List 2: \n");
    printList(list2);
    
    // Merge 2 list
    struct ListNode* mergedList = mergeTwoLists(list1, list2);
    
    // Print the merged list
    printf("Merged List:\n");
    printList(mergedList);
    
    // Free allocated memory
    while(list1 != NULL)
    {
        struct ListNode *temp = list1;
        list1 = list1->next;
        free(temp);
    }
    
    while(list2 != NULL)
    {
        struct ListNode *temp = list2;
        list2 = list2->next;
        free(temp);
    }
    
    while(mergedList != NULL)
    {
        struct ListNode *temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }
    
    return 0;
}