/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    inline void traverse(Node* node, vector<vector<int>>& res, int level) {
        if (node == nullptr) return;
        if (res.size() > level) {
            res[level].push_back(node->val);
        } else {
            res.push_back({});
            res[level].push_back(node->val);
        }
        for (auto elem : node->children) {
            traverse(elem, res, level + 1);
        }
    }

    inline vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        traverse(root, res, 0);
        return res;
    }
};
