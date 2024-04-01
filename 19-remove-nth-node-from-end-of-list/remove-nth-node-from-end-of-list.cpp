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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* temp = head;

        while (temp!=NULL)
        {
            sz++;
            temp = temp->next;
        }

        int ele = sz-n;
        int cnt = 0;
        temp = head;
        if (sz-n == 0)
        {
            head = head->next;
            return head;
        }

        while (cnt < sz-1 && temp->next!=NULL)
        {
            cnt++;

            if (cnt == ele)
            {
                temp->next = temp->next->next;
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        cout<<"sz = "<<sz<<endl;
        return head;
    }
};