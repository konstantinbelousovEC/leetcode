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
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) return true;

        std::vector<int> v;

        ListNode* current_node = head;
        while (current_node != nullptr) {
            v.push_back(current_node->val);
            current_node = current_node->next;
        }

        for (int i = 0, j = v.size() - 1; i < j; i++, j--) {
            if (v[i] != v[j]) return false;
        }

        return true;
    }
};

// recursive

class Solution {
private:
    ListNode* frontPointer;

    bool recursivelyCheck(ListNode* currentNode) {
        if (currentNode != nullptr) {
            if (!recursivelyCheck(currentNode->next)) return false;
            if (currentNode->val != frontPointer->val) return false;
            frontPointer = frontPointer->next;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
};