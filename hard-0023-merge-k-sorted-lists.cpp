// Linked List | Divide and Conquer | Heap (Priority Queue) | Merge Sort

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

// without additional container, slow
class Solution {
private:
    ListNode* findMin(std::vector<ListNode*>& lists) {
        lists.erase(std::remove_if(lists.begin(), lists.end(), [](ListNode* ptr) {
            return ptr == nullptr;
        }), lists.end());

        ListNode* min_node = nullptr;
        int min_val = 10001;
        int pos;

        for (size_t i = 0; i < lists.size(); i++) {
            if (lists[i]->val < min_val) {
                min_node = lists[i];
                min_val = lists[i]->val;
                pos = i;
            }
        }

        if (min_node != nullptr) lists[pos] = lists[pos]->next;

        return min_node;
    }

public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* node = new ListNode{};
        ListNode* dummy_head = node;

        while (true) {
            ListNode* min_node = findMin(lists);
            if (min_node == nullptr) break;

            node->next = min_node;
            node = node->next;
        }

        return dummy_head->next;
    }
};

// with additional container, fast
class Solution2 {
public:
    ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        std::vector<int> values; values.reserve(10001);

        for (ListNode* node : lists) {
            while (node != nullptr) {
                values.push_back(node->val);
                node = node->next;
            }
        }

        std::sort(values.begin(), values.end());

        ListNode* head = nullptr;
        for(int i = values.size() - 1; i >= 0; i--) {
            ListNode* current = new ListNode{values[i], head};
            head = current;
        }
        
        return head;
    }
};

