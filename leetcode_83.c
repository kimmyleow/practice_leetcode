/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *temp = head;

    while(temp!=NULL && temp->next!=NULL) {
        if(temp->val == temp->next->val) {
            struct ListNode *temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);

        }else{
            temp = temp->next;
        }
    }
    return head;
}