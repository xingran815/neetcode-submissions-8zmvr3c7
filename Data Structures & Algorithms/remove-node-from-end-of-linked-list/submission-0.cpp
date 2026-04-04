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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // we can use two pointers that have the distance of n
        // to find which node to delete
        int i = 0;
        ListNode* p2 = head;
        ListNode* p1 = head;
        ListNode* p_last = nullptr;
        while (p2) {

            p2 = p2->next;
            i++;
            if (i > n) {
                p_last = p1;
                p1 = p1->next;
            }
        }
        cout << p1->val << endl;
        if (p_last == nullptr) {
            // remove the first node
            head = p1->next;
        } else {
            // remove the node inside the list
            p_last->next = p1->next;
        }
        return head;
    }
};
