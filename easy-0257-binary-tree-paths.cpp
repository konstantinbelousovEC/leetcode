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
    void traverse(TreeNode* node, std::vector<std::string>& res, std::string str) {
        if (!str.empty()) str.append("->");
        str.append(std::to_string(node->val));
        if (node->left != nullptr) traverse(node->left, res, str);
        if (node->right != nullptr) traverse(node->right, res, str);
        if (node->left == nullptr && node->right == nullptr) res.push_back(str);
    }

public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> res;
        std::string path;

        traverse(root, res, path);
        return res;
    }
};