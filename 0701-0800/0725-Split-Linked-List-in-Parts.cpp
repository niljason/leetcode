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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> nodes(k);
        ListNode* curr = head;
        int length = 0;
        while (curr != nullptr) {
            curr = curr->next;
            length++;
        }

        int extra = length % k;
        int part_size = length / k;

        int part_num = 0;
        int count = 0;

        curr = head;
        ListNode* part = head;

        while (curr != nullptr) {
            count++;
            if (part_num < extra && count == part_size+1) {
                ListNode* copy = curr->next;
                curr->next = nullptr;
                nodes[part_num] = part;
                                
                curr = copy;
                part = curr;
                count = 0;
                part_num++;
            } 
            else if (part_num >= extra && count == part_size) {
                ListNode* copy = curr->next;
                curr->next = nullptr;
                nodes[part_num] = part;
                                
                curr = copy;
                part = curr;
                count = 0;
                part_num++;
            } else {
                curr = curr->next;
            }
        }
        return nodes;
    }
};
