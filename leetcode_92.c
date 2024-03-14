#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(head==NULL || left==right || head->next == NULL) return head;
    
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode *leftPre = dummy;
    struct ListNode *currNode = head;
    int pos = 0;
    
    for(pos=1; pos<left; pos++) {
        leftPre = leftPre->next;
        currNode = currNode->next;
    }
    
    int i = 0;
    int posInterval = right - left + 1;
    struct ListNode *subListHead = currNode;
    struct ListNode *prevNode = NULL;
    struct ListNode *nextNode = NULL;
    for(i=0; i<posInterval; i++) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    
    leftPre->next = prevNode;
    subListHead->next = currNode;
    
    struct ListNode *result = dummy->next;
    free(dummy); // Free the dummy node
    return result;
}

void printList(struct ListNode *head) {
    struct ListNode *temp = head;
    while(temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
}

struct ListNode* createNode(int val) {
    struct ListNode *new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->val = val;
    new->next = NULL;
    return new;
}

int main() {
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    printf("Original List: \n");
    printList(head);
    
    head = reverseBetween(head, 2, 4);
    
    printf("Reversed List: \n");
    printList(head);
    
    return 0;
}