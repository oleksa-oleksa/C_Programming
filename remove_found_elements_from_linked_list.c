/**
 * Remove all elements from a linked list of integers that have value val.
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {

    struct ListNode *prev = NULL;
    struct ListNode *toDelete = head;

    // if list is not empty
    if (head)
    {
        do
        {
            if (toDelete->val == val)
            {
                // if list has only one element
                if (toDelete == head && head->next == NULL)
                {
                    free(head);
                    return NULL;
                }

                // if first has to be deleted
                if (toDelete == head && head->next != NULL)
                {
                    head = head->next;
                    struct ListNode *tmp = toDelete;
                    toDelete = toDelete->next;
                    free(tmp);
                }

                // if last has to be deleted
                if (toDelete->next == NULL && toDelete != head)
                {
                    prev->next = NULL;
                    struct ListNode *tmp = toDelete;
                    free(tmp);
                    return head;
                }

                // if an element is in the centre of the list
                if (toDelete != head && head->next != NULL)
                {
                    struct ListNode *tmp = toDelete;
                    toDelete = toDelete->next;
                    prev->next = toDelete;
                    free(tmp);

                }
            }

            else
            {
                prev = toDelete;
                toDelete = toDelete->next;
            }

        }while(toDelete != NULL);
    }

        // if list is empty
    else
        return NULL;

    return head;
}