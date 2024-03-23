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
    void reorderList(ListNode* head) {
        vector<ListNode*> pos;
        ListNode* temp = head;
        while (temp!=NULL)
            {
            pos.push_back(temp);
            temp = temp->next;

            }
        
        temp = head;
        int i = 1;
        int j = pos.size()-1;
        while (i<j)
            {
            temp->next = pos[j];
      
            temp = temp->next;
            temp->next = pos[i];
            i++;
            j--;
            temp = temp->next;
            }
        temp->next = pos[j];
        temp = temp->next;
        temp->next = NULL;
       

    }
};