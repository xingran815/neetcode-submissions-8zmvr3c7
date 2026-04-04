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
    ListNode* reverseList(ListNode* head) {
        // use 3 pointers, p_last, p_current, p_next        
        // pointing to the last node, current node, and next node
        // in the original list when iterate the node
        // change the direction of the linked list
        // p_current -> next = p_last

        ListNode *p_last, *p_current, *p_next;
        p_last = nullptr;
        p_current = head;
        while (p_current != nullptr) {
            p_next = p_current->next;
            p_current->next = p_last;
            p_last = p_current;
            p_current = p_next;
        }
        head = p_last;
        return head;
        
    }
};
