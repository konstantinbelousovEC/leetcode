// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> inorderTraversalRecursive(TreeNode* root) {
        std::vector<int> res;
        inorderTraversalRecursive(root, res);
        return res;
    }

    vector<int> inorderTraversalIterate(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> stack;
        TreeNode* current = root;
        while (current != nullptr || !stack.empty()) {
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }
            current = stack.top();
            stack.pop();
            res.push_back(current->val);
            current = current->right;
        }
        return res;
    }

private:
    void inorderTraversalRecursive(TreeNode* node, vector<int>& values) {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left, values);
            values.push_back(node->val);
            inorderTraversalRecursive(node->right, values);
        }
    }

};