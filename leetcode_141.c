#include <stdio.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
bool hasCycle(struct ListNode *head);

int main() {
    // Creating nodes for a linked list
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *second = malloc(sizeof(struct ListNode));
    struct ListNode *third = malloc(sizeof(struct ListNode));
    struct ListNode *fourth = malloc(sizeof(struct ListNode));

    // Assigning values and linking nodes
    head->val = 1;
    head->next = second;
    second->val = 2;
    second->next = third;
    third->val = 3;
    third->next = fourth;
    fourth->val = 4;
    fourth->next = NULL;

    // Creating a cycle in the linked list (uncomment to create a cycle)
    // fourth->next = head;

    // Checking if there's a cycle in the linked list
    bool has_cycle = hasCycle(head);

    if (has_cycle) {
        printf("The linked list has a cycle.\n");
    } else {
        printf("The linked list does not have a cycle.\n");
    }

    // Freeing memory
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}