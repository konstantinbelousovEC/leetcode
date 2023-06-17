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
    int total_tilt = 0;

public:
    inline int sum(TreeNode* node) {
        if (node == nullptr) return 0;

        int left_sum = sum(node->left);
        int right_sum = sum(node->right);
        int tilt = std::abs(left_sum - right_sum);

        total_tilt += tilt;

        return node->val + left_sum + right_sum;
    }

    inline int findTilt(TreeNode* root) {
        if (root == nullptr) return 0;
        sum(root);
        return total_tilt;
    }
};
