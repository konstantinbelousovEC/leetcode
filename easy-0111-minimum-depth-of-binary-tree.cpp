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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            int left_h = minDepth(root->left);
            int right_h = minDepth(root->right);
            
            if (left_h == 0) return 1 + right_h;
            if (right_h == 0) return 1 + left_h;

            return 1 + std::min(left_h, right_h);
        }
    }
};