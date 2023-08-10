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
    ListNode* partition(ListNode* head, int x) const noexcept {
        if (head == nullptr || head->next == nullptr) return head;

        std::deque<int> less;
        std::deque<int> not_less;

        // std::vector<int> less;      less.reserve(200);
        // std::vector<int> not_less;  not_less.reserve(200);

        ListNode* current_node = head;
        while (current_node != nullptr) {
            if (current_node->val < x) less.push_back(current_node->val);
            else not_less.push_back(current_node->val);

            current_node = current_node->next;
        }

        current_node = head;
        for (auto elem : less) {
            current_node->val = elem;
            current_node = current_node->next;
        }

        for (auto elem : not_less) {
            current_node->val = elem;
            current_node = current_node->next;
        }

        return head;
    }
};
