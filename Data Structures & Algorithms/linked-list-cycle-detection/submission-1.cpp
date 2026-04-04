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
        // if there would be any cycle in the linked list
        // the fast pointer and slow pointer would meet
        // in the loop
        // pointer p1 skips one node per iteration
        // pointer p2 skips two nodes per iteration
        ListNode *p1, *p2;
        p1 = head;
        p2 = head;

        while (p2 && p2->next) {
            cout << p1->val << ", " << p2->val << endl;
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) {
                return true;
            }
        }
        return false;
        
    }
};
