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
	inline void postorder_recursive(Node* node, vector<int>& res) {
		if (node == nullptr) return;
		for (auto elem : node->children) {
			postorder_recursive(elem, res);
		}
		res.push_back(node->val);
	}	

    inline vector<int> postorder(Node* root) {
		vector<int> res;
		postorder_recursive(root, res);
		return res;
    }
};
