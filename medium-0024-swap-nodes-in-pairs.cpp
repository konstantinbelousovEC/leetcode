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
    ListNode* swapPairs(ListNode* head) const noexcept {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* left_ptr = nullptr;
        ListNode* right_ptr = head;
        ListNode* new_head = head->next;

        while (right_ptr != nullptr && right_ptr->next != nullptr) {
            ListNode* tmp = right_ptr->next;
            right_ptr->next = tmp->next;
            tmp->next = right_ptr;

            if (left_ptr != nullptr) left_ptr->next = tmp;

            left_ptr = right_ptr;
            right_ptr = right_ptr->next;
        }

        return new_head;
    }
};
