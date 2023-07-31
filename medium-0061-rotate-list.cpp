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
private:
    ListNode* findPenultimateNode(ListNode* head) const noexcept {
        ListNode* node = head;
        while (node->next->next != nullptr) {
            node = node->next;
        }
        return node;
    }

    ListNode* findLastNode(ListNode* head) const noexcept {
        ListNode* node = head;
        while (node->next != nullptr) {
            node = node->next;
        }
        return node;
    }

    int getListSize(ListNode* head) const noexcept {
        int size = 1;
        ListNode* node = head;
        while (node->next != nullptr) {
            node = node->next;
            size++;
        }
        return size;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) const noexcept {
        if (head == nullptr || head->next == nullptr || k == 0) return head;
        
        int list_size = getListSize(head);

        if (k == list_size) return head;
        else if (k > list_size) k = k % list_size;

        ListNode* new_head = head;
        int i = 0;

        while (i < k) {
            ListNode* penultimate = findPenultimateNode(new_head);
            ListNode* last = findLastNode(new_head);
            
            penultimate->next = nullptr;
            last->next = new_head;
            new_head = last;

            i++;
        }

        return new_head;
    }
};