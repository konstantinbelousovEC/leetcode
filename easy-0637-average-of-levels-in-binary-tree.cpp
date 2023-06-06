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

using namespace std;

class Solution {
public:
    inline void average(TreeNode* node, int level, vector<double>& res, vector<int>& count) {
        if (node == nullptr) return;

        if (level < res.size()) {
            res[level] = res[level] + static_cast<double>(node->val);
            count[level]++;
        } else {
            res.push_back(node->val);
            count.push_back(1);
        }

        average(node->left, level + 1, res, count);
        average(node->right, level + 1, res, count);
    }

    inline vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<int> count;
        average(root, 0, res, count);

        transform(res.begin(), res.end(), count.begin(), res.begin(), [](double element, int divisor) {
            return element / static_cast<double>(divisor);
        });

        // или так:

        // for (int i = 0; i < res.size(); i++) {
        //     res[i] = res[i] / static_cast<double>(count[i]);
        // }

        return res;
    }
};