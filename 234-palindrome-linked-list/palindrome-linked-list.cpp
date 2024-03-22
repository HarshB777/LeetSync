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
    bool isPalindrome(ListNode* head) {
        string s = "";

        //ListNode* t = head;

        while (head!=NULL)
        {
            s += to_string(head->val);
            
            head = head->next;
        }

        string t = s;
        reverse(s.begin(),s.end());

        if (s == t)
        {
            return true;
        }
        return false;
    }
};