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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // having 2 pointers iterating list1 and list2
        // while p1 or p2 is valid
        // if both are valid:
        //      put the smaller one in the next node
        //      move the node forward
        // if only one is valid:
        //      put the valid one in the next node
        //      move the node forward
        ListNode* head = nullptr;
        ListNode *p1, *p2, *p;
        p1 = list1;
        p2 = list2;
        // decide the head
        if (p1 && p2) {
            if (p1->val < p2->val) {
                head = p1;
                p1 = p1->next;
            } else {
                head = p2;
                p2 = p2->next;
            }
        } else if (p1) {
            head = p1;
            p1 = p1->next;
        } else if (p2) {
            head = p2;
            p2 = p2->next;
        } else {
            head = nullptr;
        }
        p = head;

        while (p1 || p2) {
            if (p1 && p2) {
                if (p1->val < p2->val) {
                    p->next = p1;
                    p1 = p1->next;
                } else {
                    p->next = p2;
                    p2 = p2->next;
                }
            } else if (p1) {
                p->next = p1;
                p1 = p1->next;
            } else if (p2) {
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = nullptr;
            }
            p = p->next;
        }
        return head;
    }

};
