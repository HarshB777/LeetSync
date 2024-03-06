/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> addr;

        while (head != NULL)
        {
            if (addr.find(head)!=addr.end())
                return true;
            addr.insert(head);
            head = head->next;
        }

        return false;
    }
};