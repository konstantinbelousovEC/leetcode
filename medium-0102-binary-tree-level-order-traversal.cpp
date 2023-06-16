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
	inline void traverse(TreeNode* node, vector<vector<int>>& res, int level) {
		if (node == nullptr) return;
		if (res.size() > level) {
			res[level].push_back(node->val);
		} else {
			res.push_back({});	
			res[level].push_back(node->val);
		}
		traverse(node->left, res, level+1);
		traverse(node->right, res, level+1);
	}

    inline vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
		traverse(root, res, 0);
		return res;
    }
};
