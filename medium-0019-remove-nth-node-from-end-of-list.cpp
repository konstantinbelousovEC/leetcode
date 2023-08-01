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
    ListNode* removeNthFromEnd(ListNode* head, int n) const noexcept {
        ListNode* node_left = head;
        ListNode* node_right = head;

        int k = 0;
        while (k < n) {
            node_right = node_right->next;
            k++;
        }

        if (node_right == nullptr) return head->next;

        while (node_right->next != nullptr) {
            node_left = node_left->next;
            node_right = node_right->next;
        }

        node_left->next = node_left->next->next;

        return head;
    }
};
