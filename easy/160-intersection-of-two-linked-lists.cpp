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

    // brute force
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a_ptr = headA;
        while (a_ptr != nullptr) {

            ListNode* b_ptr = headB;
            while (b_ptr != nullptr) {
                if (a_ptr == b_ptr) return b_ptr;
                
                b_ptr = b_ptr->next;
            }

            a_ptr = a_ptr->next;
        }

        return nullptr;
    }

    // linear
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        int a_size = GetListSize(headA), b_size = GetListSize(headB);

        if (a_size > b_size) {
            while (a_size > b_size) {
                headA = headA->next;
                a_size--;
            }
        } else {
            while (b_size > a_size) {
                headB = headB->next;
                b_size--;
            }
        }

        while (headA != nullptr) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }

    // linear
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tail = headA;
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        tail->next = headA;

        ListNode* turtle = headB;
        ListNode* hare = headB;

        while (hare != nullptr && hare->next != nullptr) {
            turtle = turtle->next;
            hare = hare->next->next;

            if (turtle == hare) {
                turtle = headB;
                
                while (turtle != hare) {
                    turtle = turtle->next;
                    hare = hare->next; 
                }

                tail->next = nullptr;
                return turtle;
            }
        }

        tail->next = nullptr;
        return nullptr;
    }

private:

    int GetListSize(ListNode* head) {
        int size = 0;
        while (head != nullptr) {
            size++;
            head = head->next;
        }
        return size;
    }

};