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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* headptr = head;
        while (headptr) {
            if (headptr->next && headptr->val == headptr->next->val) {
                ListNode* del = headptr->next;
                headptr->next = headptr->next->next;
                delete del;
            } else {
                headptr = headptr->next;
            }
        }
        return head;
    }
};
