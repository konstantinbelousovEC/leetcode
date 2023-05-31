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
public:

    int defineMAX(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return 1 + std::max(defineMAX(node->left), defineMAX(node->right));
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } else {
            int h1 = defineMAX(root->left);
            int h2 = defineMAX(root->right);

            bool b = std::abs(h1 - h2) <= 1;
            return b && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};