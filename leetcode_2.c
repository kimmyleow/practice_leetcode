#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int value;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->value = 0;
    dummy->next = NULL;
    
    struct ListNode* current = dummy;
    int carry = 0;
    
    while(l1 != NULL || l2 != NULL || carry !=0){
        int sum = carry;
        
        if(l1 != NULL){
            sum += l1->value;
            l1 = l1->next;
        }
        
        if(l2 != NULL){
            sum += l2->value;
            l2 = l2->next;
        }
        
        carry = sum/10;
        
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->value = sum%10;
        newNode->next = NULL;
        
        current->next = newNode;
        current = newNode;
    }
    
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
    
}

void printList(struct ListNode* head){
    while(head != NULL){
        printf("%d -> ", head->value);
        head = head->next;
        
    }
    
}

int main(){
    // l1
    struct ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->value = 2;
    l1->next = NULL;
    
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->value = 4;
    newNode->next = NULL;
    l1->next = newNode;
    
    struct ListNode *newNode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode2->value = 3;
    newNode2->next = NULL;
    l1->next->next = newNode2;
    
    // l2
    struct ListNode *l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->value = 5;
    l2->next = NULL;
    
    struct ListNode *newNode3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode3->value = 6;
    newNode3->next = NULL;
    l2->next = newNode3;
    
    struct ListNode *newNode4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode4->value = 4;
    newNode4->next = NULL;
    l2->next->next = newNode4;
    
    //print
    printf("List 1: \n");
    printList(l1);
    printf("List 2: \n");
    printList(l2);
    
    //Add 2 linked list
    struct ListNode *sumList = addTwoNumbers(l1,l2);
    printf("List Sum: \n");
    printList(sumList);
    
    //free memory
    while(l1 != NULL){
        struct ListNode* temp = l1;
        l1 = l1->next;
        free(temp);
    }
    
    while(l2 != NULL){
        struct ListNode* temp = l2;
        l2 = l2->next;
        free(temp);
    }
    
    while (sumList != NULL) {
        struct ListNode* temp = sumList;
        sumList = sumList->next;
        free(temp);
    }
    
    return 0;
}