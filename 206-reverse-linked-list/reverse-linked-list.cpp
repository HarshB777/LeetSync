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
    ListNode* reverseList(ListNode* head) {
        vector<ListNode*> pos;

        while (head!=NULL)
        {
            //cout<<"pushing back = "<<head<<endl;
            pos.push_back(head);
            head = head->next;
        }
        int n = pos.size();
        if (n==0)
        {
            return head;
        }
        //cout<<pos[n-1]<<endl;
        head = pos[pos.size()-1];
        
        for (int i = pos.size()-2; i >= 0; i--)
        {
            head->next = pos[i];
            head = head->next;
        }
        head->next = NULL;

        ListNode* ans = pos[pos.size()-1];


        return ans;
    }
};