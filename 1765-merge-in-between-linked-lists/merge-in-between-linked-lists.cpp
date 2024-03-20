/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        ListNode* temp = list1;
        int i = 0;
        while (head!=NULL)
        {
            if (i>=a && i<=b)
            {
                temp = temp->next;
                i++;
                continue;
            }
            if (i==a-1)
            {
                temp = head;
                i++;
                continue;
            }

            if (i==b+1)
            {
                ListNode* t = list2;
                while (t!=NULL)
                {
                    head->next = t;
                    head = head->next;
                    t = t->next;
                }
                head->next = temp->next;
                i++;
                continue;
            }
            head=head->next;
            
            i++;

            
        }

        return list1;
    }
};