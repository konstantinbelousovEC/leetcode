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
        if (head == nullptr || head->next == nullptr) return false;

        ListNode* turtle = head;
        ListNode* hare = head;
        while (hare != nullptr && hare->next != nullptr) {
            turtle = turtle->next;
            hare = hare->next->next;
            if (turtle == hare) return true;
        }

        return false;
    }
};