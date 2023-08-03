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
    ListNode* deleteDuplicates(ListNode* head) const noexcept {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode dummy_head{0, head};
        ListNode* left_ptr = &dummy_head;
        ListNode* right_ptr = head;

        while (right_ptr != nullptr) {
            bool is_duplicate = false;
            while (right_ptr->next != nullptr && (right_ptr->val == right_ptr->next->val)) {
                right_ptr = right_ptr->next;
                is_duplicate = true;
            }

            if (is_duplicate) left_ptr->next = right_ptr->next;
            else left_ptr = right_ptr;
            
            right_ptr = right_ptr->next;
        }

        return dummy_head.next;
    }

};
