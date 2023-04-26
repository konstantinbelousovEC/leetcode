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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if (head == nullptr) return head;

       ListNode* previous = nullptr;
       ListNode* current = head;

       while (left > 1) {
            previous = current;
            current = current->next;
            left--;
            right--;
       }

       ListNode* con = previous;
       ListNode* tail = current;

       ListNode* next = nullptr;
       while (right > 0) {
           next = current->next;
           current->next = previous;
           previous = current;
           current = next;
           right--;
       }

       if (con != nullptr) {
           con->next = previous;
       } else {
           head = previous;
       }

       tail->next = current;
       return head;
    }
};