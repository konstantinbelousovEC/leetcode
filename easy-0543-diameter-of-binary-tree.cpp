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
    int res = 0;

public:
    inline int diameterOfBinaryTree(TreeNode* root) {
        max_height(root);
        return res;
    }

    inline int max_height(TreeNode* root) {
        if (root == nullptr) return 0;

        int x = max_height(root->left);
        int y = max_height(root->right);

        res = max(res, x + y);

        return max(x, y) + 1;
    }
};
