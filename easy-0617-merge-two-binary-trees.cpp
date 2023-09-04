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
    
public:
    // new tree
    // hope somebody will free the allocated memory
    inline TreeNode* mergeTrees2(TreeNode* root1, TreeNode* root2) const {
        TreeNode* node = nullptr;
        if (root1 != nullptr && root2 != nullptr) {
            node = new TreeNode{root1->val + root2->val};
            node->left = mergeTrees(root1->left, root2->left);
            node->right = mergeTrees(root1->right, root2->right);
            return node;
        }
        
        if (root1 == nullptr && root2 == nullptr) return node;
        
        if (root1 == nullptr) {
            node = new TreeNode{root2->val, root2->left, root2->right};
            return node;
        }
        if (root2 == nullptr) {
            node = new TreeNode{root1->val, root1->left, root1->right};
            return node;
        }
        return nullptr;
    }

    // in place
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) const {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;

        root1->val = root1->val + root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};
