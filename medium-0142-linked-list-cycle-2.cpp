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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* turtle = head;
        ListNode* hare = head;
        while (hare != nullptr && hare->next != nullptr) {
            turtle = turtle->next;
            hare = hare->next->next;
            if (turtle == hare) {
                turtle = head;

                while (turtle != hare) {
                    turtle = turtle->next;
                    hare = hare->next;
                }

                return turtle;
            }
        }

        return nullptr;
    }
};