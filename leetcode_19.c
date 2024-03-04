#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* fast = dummy;
    struct ListNode* slow = dummy;

    // Move fast pointer so that the gap between fast and slow is n nodes apart
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move fast to the end, maintaining the gap
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node from the end
    struct ListNode* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    return dummy->next;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Example usage
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = NULL;

    printf("Original list: ");
    printList(head);

    int n = 2;
    struct ListNode* newHead = removeNthFromEnd(head, n);

    printf("List after removing %dth node from the end: ", n);
    printList(newHead);

    // Free memory
    while (newHead != NULL) {
        struct ListNode* temp = newHead;
        newHead = newHead->next;
        free(temp);
    }

    return 0;
}