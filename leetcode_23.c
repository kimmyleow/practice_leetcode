#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    struct ListNode* mergedList = NULL;
    
    if(l1->val < l2->val)
    {
        mergedList = l1;
        mergedList->next = mergeTwoLists(l1->next, l2);
    }else{
        mergedList = l2;
        mergedList->next = mergeTwoLists(l2->next, l1);
    }
    return mergedList;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    int interval = 1;
    int i = 0;
    
    if(listsSize == 0) return NULL;
    
    while(interval < listsSize)
    {
        for(i=0; i < listsSize - interval; i += interval*2)
        {
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }
    return lists[0];
}

struct ListNode* createNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head)
{
    while(head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(4);
    list1->next->next = createNode(5);
    
    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);
    
    struct ListNode* list3 = createNode(2);
    list3->next = createNode(6);
    
    struct ListNode* lists[3] = {list1, list2, list3};
    
    printf("Merged List: ");
    struct ListNode* merged = mergeKLists(lists, 3);
    printList(merged);
    
    return 0;
}