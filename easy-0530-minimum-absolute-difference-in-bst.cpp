// Tree | Depth-First Search | Breadth-First Search | Binary Search Tree | Binary Tree

class Solution {
    void traverse(TreeNode* node, TreeNode*& prev, int& diff) const noexcept {
        if (node == nullptr) return;

        traverse(node->left, prev, diff);
        if (prev != nullptr) diff = std::min(diff, node->val - prev->val);
        prev = node;
        traverse(node->right, prev, diff);
    }

public:
    int getMinimumDifference(TreeNode* root) const noexcept {       
        int diff = INT_MAX;
        TreeNode* prev = nullptr;
        traverse(root, prev, diff);
        return diff;
    }
};

