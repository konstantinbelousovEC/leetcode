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
    inline bool traverse(TreeNode* node, int sum) {
        if (node == nullptr) return false;
        sum -= node->val;
        if (node->left == nullptr && node->right == nullptr && sum == 0) return true;
        return traverse(node->left, sum) || traverse(node->right, sum);
    }

public:
    inline bool hasPathSum(TreeNode* root, int target_sum) {
        if (root == nullptr) return false;
        return traverse(root, target_sum);
    }
};