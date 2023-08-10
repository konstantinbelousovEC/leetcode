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

auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

class Solution {
public:
    ListNode* sortList(ListNode* head) const noexcept {
        if (head == nullptr || head->next == nullptr) return head;

        // std::deque<int> tmp_container;                                           // 230ms
        std::vector<int> tmp_container;
        tmp_container.reserve(std::pow(10, 4) * 5);                                 // 132ms

        ListNode* current_node = head;
        while (current_node != nullptr) {
            tmp_container.push_back(current_node->val);
            current_node = current_node->next;
        }

        std::sort(tmp_container.begin(), tmp_container.end());

        current_node = head;
        for (auto elem : tmp_container) {
            current_node->val = elem;
            current_node = current_node->next;
        }

        return head;
    }
};
