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
    // recursive
    inline ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }

    // iterative
    inline ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;

        ListNode* node = new ListNode(0, head);
        ListNode* current = head;
        ListNode* prev = node;

        while (current != nullptr) {
            if (current->val == val) {
                prev->next = current->next;
            } else {
                prev = current;
            }
            current = current->next;
        }

        return node->next;
    }
};