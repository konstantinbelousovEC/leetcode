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
    inline void traverse(TreeNode* node, unordered_map<int, int>& count) {
        if (node == nullptr) return;

        count[node->val]++;

        traverse(node->left, count);
        traverse(node->right, count);
    }

    inline vector<int> findMode(TreeNode* root) {
        if (root == nullptr) return {0};
        unordered_map<int, int> count;
        traverse(root, count);

        int max = 1;
        vector<int> res;
        for (auto [key, count] : count) {
            if (count == max) {
                res.push_back(key);
            } else if (count > max) {
                res.clear();
                res.push_back(key);
                max = count;
            }
        }

        return res;
    }
};