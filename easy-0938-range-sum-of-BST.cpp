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

auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
 
class Solution {
private:
    int res{0};
    int low_;
    int high_;

    void traverse(TreeNode* node) noexcept {
        if (node == nullptr) return;
        
        if (node->val >= low_ && node->val <= high_) {
            res += node->val;
            traverse(node->left);
            traverse(node->right);
        }
        else if (node->val < low_) traverse(node->right);
        else traverse(node->left);
        
        return;
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) noexcept {
        low_ = low;
        high_ = high;

        traverse(root);
        
        return res;
    }
};
