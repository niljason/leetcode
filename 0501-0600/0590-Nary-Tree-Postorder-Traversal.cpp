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
    vector<int> postorder(Node* root) {
        stack<Node*> nodes;
        vector<int> order;
        if (root == nullptr) {
            return order;
        }
        nodes.push(root);
        while (nodes.size() != 0) {
            Node* curr = nodes.top();
            nodes.pop();
            if (curr->children.size() != 0) {
                Node* temp = new Node{curr->val};
                nodes.push(temp);
                for (int ind = curr->children.size(); ind > 0; --ind) {
                    nodes.push(curr->children[ind-1]);
                }
            } 
            else {
                order.push_back(curr->val);
            }
        }
        return order;
    }
};
