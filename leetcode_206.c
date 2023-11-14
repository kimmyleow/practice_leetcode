/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }

    if(head->next == NULL){
        return head;
    }

    struct ListNode *preNode = NULL;
    struct ListNode *currNode = head;
    
    while(currNode != NULL){
        struct ListNode *nextNode = currNode->next;
        currNode->next = preNode;
        preNode = currNode;
        currNode = nextNode;
    }

    head = preNode;

    return head;

}