/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> clone_map;
public:
    Node* cloneGraph(Node* node) {
        clone_map[nullptr] = nullptr;
        return helper(node);
        
    }

    Node* helper(Node* old_node) {
        if (clone_map.count(old_node) != 0) {
            // new_node created;
            return clone_map[old_node];
        }
        // new node doesn't exist
        Node* new_node = new Node(old_node->val);
        clone_map[old_node] = new_node;
        for (auto nei:old_node->neighbors) {
            new_node->neighbors.push_back(helper(nei));
        }
        return new_node;
    }

};
