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
    TreeNode* sortedArrayToBST(std::vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int current_index = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[current_index]);

        node->left = sortedArrayToBST(nums, left, current_index - 1);
        node->right = sortedArrayToBST(nums, current_index + 1, right);
        
        return node;
    }
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return sortedArrayToBST(nums, 0 , nums.size() - 1);
    }
};