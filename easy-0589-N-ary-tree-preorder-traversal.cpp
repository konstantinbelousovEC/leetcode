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
	inline void preorder_recursive(Node* node, vector<int>& res) {
		if (node == nullptr) return;
		res.push_back(node->val);
		for (auto elem : node->children) {
			preorder_recursive(elem, res);
		}
	}
    inline vector<int> preorder(Node* root) {
        vector<int> res;
		preorder_recursive(root, res);
		return res;
    }
};
