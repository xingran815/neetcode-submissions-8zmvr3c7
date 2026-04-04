/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // use hash_set to record each node
        unordered_set<ListNode*> hset;
        ListNode* p = head;
        while (p) {
            if (!hset.empty() && hset.find(p) != hset.end()) {
                // there the node existed in the hset
                return true;
            }
            hset.insert(p);
            p = p->next;
        }
        return false;
        
    }
};
