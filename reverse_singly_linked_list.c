/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head)
{

    //if list is empty
    if (!head)
        return head;

    struct ListNode *p = head->next;

    head->next = NULL;

    while (NULL != p)
    {
        struct ListNode *ptmp = p->next;
        p->next = head;
        head = p;
        p = ptmp;
    }
    return head;
}