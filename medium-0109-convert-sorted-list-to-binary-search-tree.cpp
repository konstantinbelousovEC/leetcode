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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:

    // --------------------------------------------------
    
    std::vector<int> makeVector(ListNode* head) {
        if (head == nullptr) return {};

        std::vector<int> v;
        for (ListNode* current = head; current != nullptr; current = current->next) {
            v.push_back(current->val);
        }

        return v;
    }

    TreeNode* sortedListToBST(std::vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int current_index = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[current_index]);

        node->left = sortedListToBST(nums, left, current_index - 1);
        node->right = sortedListToBST(nums, current_index + 1, right);

        return node;
    }

    // --------------------------------------------------

    TreeNode* sortedListToBST(ListNode* start, int n) {
        if (n <= 0) return nullptr;
        if (n == 1) return new TreeNode(start->val);

        int list_middle = n / 2;
        ListNode* current = start;

        while (list_middle--) {
            current = current->next;
        }
        
        return new TreeNode(current->val,
                            sortedListToBST(start, n / 2),
                            sortedListToBST(current->next, n - n / 2 - 1));
    }

public:

    // --------------------------------------------------

    TreeNode* sortedListToBSTCopy(ListNode* head) {
        std::vector<int> v = makeVector(head);
        if (v.empty()) return nullptr;

        return sortedListToBST(v, 0, v.size() - 1);
    }
    
    // --------------------------------------------------

    TreeNode* sortedListToBSTInPlace(ListNode* head) {
        if (head == nullptr) return nullptr;

        int list_size = 0;
        ListNode* tmp = head;

        while (tmp != nullptr) {
            list_size++;
            tmp = tmp->next;
        }

        return sortedListToBST(head, list_size);
    }
};