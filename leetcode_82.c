/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* current = head;

    while (current != NULL) {
        if (current->next != NULL && current->val == current->next->val) {
            int duplicateVal = current->val;
            while (current != NULL && current->val == duplicateVal) {
                struct ListNode* temp = current;
                current = current->next;
                free(temp);
            }
            prev->next = current;
        } else {
            prev = prev->next;
            current = current->next;
        }
    }

    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}