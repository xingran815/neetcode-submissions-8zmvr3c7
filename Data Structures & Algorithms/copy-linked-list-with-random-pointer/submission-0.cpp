/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // use an hash_map to store <address, index> pair of the old list
        // to find the random pointer
        // use a vector to store the address of of the new list

        unordered_map<Node*, int> hash_add_old;
        vector<Node*> v_add_new;

        Node* p_old = head;
        Node* dummy = new Node(0);
        Node* p_new = dummy;
        int idx=0;
        while (p_old) {
            hash_add_old.emplace(p_old, idx);
            Node* p = new Node(p_old->val);
            v_add_new.push_back(p);
            p_new->next = p;
            p_new = p;
            idx++;
            p_old = p_old->next;
        }

        // assign the random property
        p_old = head;
        p_new = dummy->next;
        while (p_old) {
            if (p_old->random) {
                auto it = hash_add_old.find(p_old->random);
                p_new->random = v_add_new[it->second];
                cout << it->second << endl;
            }
            p_new = p_new->next;
            p_old = p_old->next;
        }
        return dummy->next;
        
    }
};
