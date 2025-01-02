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

    ListNode* reverse(const ListNode* hp) {
        ListNode* headPtr = nullptr;
        const ListNode* curr = hp;
        while (curr) {
            headPtr = new ListNode{curr->val, headPtr}; // listAddHead
            curr = curr->next;
        }
        return headPtr;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        int carry = 0;
        int sum = 0;
        while(l1 && l2) {
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum % 10;
            result = new ListNode{sum, result};
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            sum = l1->val + carry;
            carry = sum/10;
            sum = sum % 10;
            result = new ListNode{sum, result};
            l1 = l1->next;
        }
        while(l2) {
            sum = l2->val + carry;
            carry = sum/10;
            sum = sum % 10;
            result = new ListNode{sum, result};
            l2 = l2->next;
        }
        while (carry != 0) {
            result = new ListNode{carry, result};
            carry = 0;
        }
        return reverse(result);
    }
};
